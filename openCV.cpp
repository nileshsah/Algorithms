// Background average sample code done with averages and done with codebooks
/* 
************************************************** */
#include <cv.h>
#include "cvaux.h"
#include "cxmisc.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//VARIABLES for CODEBOOK METHOD:
CvBGCodeBookModel* model = 0;
const int NCHANNELS = 3;
bool ch[NCHANNELS]={true,true,true}; // This sets what channels should be adjusted for background bounds


void  detect(IplImage* img_8uc1,IplImage* img_8uc3);

void help(void)
{
    printf("\nLearn background and find foreground using simple average and average difference learning method:\n"
        "\nUSAGE:\nbgfg_codebook [--nframes=300] [movie filename, else from camera]\n"
        "***Keep the focus on the video windows, NOT the consol***\n\n"
        "INTERACTIVE PARAMETERS:\n"
        "\tESC,q,Q  - quit the program\n"
        "\th    - print this help\n"
        "\tp    - pause toggle\n"
        "\ts    - single step\n"
        "\tr    - run mode (single step off)\n"
        "=== AVG PARAMS ===\n"
        "\t-    - bump high threshold UP by 0.25\n"
        "\t=    - bump high threshold DOWN by 0.25\n"
        "\t[    - bump low threshold UP by 0.25\n"
        "\t]    - bump low threshold DOWN by 0.25\n"
        "=== CODEBOOK PARAMS ===\n"
        "\ty,u,v- only adjust channel 0(y) or 1(u) or 2(v) respectively\n"
        "\ta    - adjust all 3 channels at once\n"
        "\tb    - adjust both 2 and 3 at once\n"
        "\ti,o  - bump upper threshold up,down by 1\n"
        "\tk,l  - bump lower threshold up,down by 1\n"
        "\tSPACE - reset the model\n"
        );
}

//
//USAGE:  ch9_background startFrameCollection# endFrameCollection# [movie filename, else from camera]
//If from AVI, then optionally add HighAvg, LowAvg, HighCB_Y LowCB_Y HighCB_U LowCB_U HighCB_V LowCB_V
//
int main(int argc, char** argv)
{
    const char* filename = 0;
    IplImage* rawImage = 0, *yuvImage = 0; //yuvImage is for codebook method
    IplImage *ImaskCodeBook = 0,*ImaskCodeBookCC = 0;
    CvCapture* capture = 0;

    int c, n, nframes = 0;
    int nframesToLearnBG = 300;

    model = cvCreateBGCodeBookModel();
    
    //Set color thresholds to default values
    model->modMin[0] = 3;
    model->modMin[1] = model->modMin[2] = 3;
    model->modMax[0] = 10;
    model->modMax[1] = model->modMax[2] = 10;
    model->cbBounds[0] = model->cbBounds[1] = model->cbBounds[2] = 10;

    bool pause = false;
    bool singlestep = false;

    for( n = 1; n < argc; n++ )
    {
        static const char* nframesOpt = "--nframes=";
        if( strncmp(argv[n], nframesOpt, strlen(nframesOpt))==0 )
        {
            if( sscanf(argv[n] + strlen(nframesOpt), "%d", &nframesToLearnBG) == 0 )
            {
                help();
                return -1;
            }
        }
        else
            filename = argv[n];
    }

    if( !filename )
    {
        printf("Capture from camera\n");
        capture = cvCaptureFromCAM( 0 );
    }
    else
    {
        printf("Capture from file %s\n",filename);
        capture = cvCreateFileCapture( filename );
    }

    if( !capture )
    {
        printf( "Can not initialize video capturing\n\n" );
        help();
        return -1;
    }

    //MAIN PROCESSING LOOP:
    for(;;)
    {
        if( !pause )
        {
            rawImage = cvQueryFrame( capture );
            ++nframes;
            if(!rawImage) 
                break;
        }
        if( singlestep )
            pause = true;
        
        //First time:
        if( nframes == 1 && rawImage )
        {
            // CODEBOOK METHOD ALLOCATION
            yuvImage = cvCloneImage(rawImage);
            ImaskCodeBook = cvCreateImage( cvGetSize(rawImage), IPL_DEPTH_8U, 1 );
            ImaskCodeBookCC = cvCreateImage( cvGetSize(rawImage), IPL_DEPTH_8U, 1 );
            cvSet(ImaskCodeBook,cvScalar(255));
            
            cvNamedWindow( "Raw", 1 );
            cvNamedWindow( "ForegroundCodeBook",1);
            cvNamedWindow( "CodeBook_ConnectComp",1);
        }

        // If we've got an rawImage and are good to go:                
        if( rawImage )
        {
            cvCvtColor( rawImage, yuvImage, CV_BGR2YCrCb );//YUV For codebook method
            //This is where we build our background model
            if( !pause && nframes-1 < nframesToLearnBG  )
                cvBGCodeBookUpdate( model, yuvImage );

            if( nframes-1 == nframesToLearnBG  )
                cvBGCodeBookClearStale( model, model->t/2 );
            
            //Find the foreground if any
            if( nframes-1 >= nframesToLearnBG  )
            {
                // Find foreground by codebook method
                cvBGCodeBookDiff( model, yuvImage, ImaskCodeBook );
                // This part just to visualize bounding boxes and centers if desired
                cvCopy(ImaskCodeBook,ImaskCodeBookCC);  
                cvSegmentFGMask( ImaskCodeBookCC );
                //bwareaopen_(ImaskCodeBookCC,100);
                cvShowImage( "CodeBook_ConnectComp",ImaskCodeBookCC);
                detect(ImaskCodeBookCC,rawImage);
                
            }
            //Display
            detect( ImaskCodeBook, rawImage );
            //cvShowImage( "Raw", rawImage );
            cvShowImage( "ForegroundCodeBook",ImaskCodeBook);
            
        }

        // User input:
        c = cvWaitKey(10)&0xFF;
        c = tolower(c);
        // End processing on ESC, q or Q
        if(c == 27 || c == 'q')
            break;
        //Else check for user input
        switch( c )
        {
        case 'h':
            help();
            break;
        case 'p':
            pause = !pause;
            break;
        case 's':
            singlestep = !singlestep;
            pause = false;
            break;
        case 'r':
            pause = false;
            singlestep = false;
            break;
        case ' ':
            cvBGCodeBookClearStale( model, 0 );
            nframes = 0;
            break;
            //CODEBOOK PARAMS
        case 'y': case '0':
        case 'u': case '1':
        case 'v': case '2':
        case 'a': case '3':
        case 'b': 
            ch[0] = c == 'y' || c == '0' || c == 'a' || c == '3';
            ch[1] = c == 'u' || c == '1' || c == 'a' || c == '3' || c == 'b';
            ch[2] = c == 'v' || c == '2' || c == 'a' || c == '3' || c == 'b';
            printf("CodeBook YUV Channels active: %d, %d, %d\n", ch[0], ch[1], ch[2] );
            break;
        case 'i': //modify max classification bounds (max bound goes higher)
        case 'o': //modify max classification bounds (max bound goes lower)
        case 'k': //modify min classification bounds (min bound goes lower)
        case 'l': //modify min classification bounds (min bound goes higher)
            {
            uchar* ptr = c == 'i' || c == 'o' ? model->modMax : model->modMin;
            for(n=0; n<NCHANNELS; n++)
            {
                if( ch[n] )
                {
                    int v = ptr[n] + (c == 'i' || c == 'l' ? 1 : -1);
                    ptr[n] = CV_CAST_8U(v);
                }
                printf("%d,", ptr[n]);
            }
            printf(" CodeBook %s Side\n", c == 'i' || c == 'o' ? "High" : "Low" );
            }
            break;
        }
    }           
    

    cvReleaseCapture( &capture );
    cvDestroyWindow( "Raw" );
    cvDestroyWindow( "ForegroundCodeBook");
    cvDestroyWindow( "CodeBook_ConnectComp");
    return 0;
}



void  detect(IplImage* img_8uc1,IplImage* img_8uc3) {
    
    
//cvNamedWindow( "aug", 1 );


//cvThreshold( img_8uc1, img_edge, 128, 255, CV_THRESH_BINARY );
CvMemStorage* storage = cvCreateMemStorage();
CvSeq* first_contour = NULL;
CvSeq* maxitem=NULL;
double area=0,areamax=0;
int maxn=0;
int Nc = cvFindContours(
img_8uc3,
storage,
&first_contour,
sizeof(CvContour),
CV_RETR_LIST // Try all four values and see what happens
);
int n=0;
printf( "Total Contours Detected: %d ", Nc );

if(Nc>0)
{
for( CvSeq* c=first_contour; c!=NULL; c=c->h_next ) 
{
     
//cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );

area=cvContourArea(c,CV_WHOLE_SEQ );

if(area>areamax)
{areamax=area;
maxitem=c;
maxn=n;
}



n++;


}

printf(" Area: %f\n", areamax );

if(areamax>100)
{
CvPoint pt0;

CvMemStorage* storage1 = cvCreateMemStorage();
CvSeq* ptseq = cvCreateSeq( CV_SEQ_KIND_GENERIC|CV_32SC2, sizeof(CvContour),
                                     sizeof(CvPoint), storage1 );
        CvSeq* hull;

        for(int i = 0; i < maxitem->total; i++ )
        {   CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, maxitem, i );
            pt0.x = p->x;
            pt0.y = p->y;
            cvSeqPush( ptseq, &pt0 );
        }
        hull = cvConvexHull2( ptseq, 0, CV_CLOCKWISE, 0 );
        int hullcount = hull->total;



        pt0 = **CV_GET_SEQ_ELEM( CvPoint*, hull, hullcount - 1 );

        for(int i = 0; i < hullcount; i++ )
        {

            CvPoint pt = **CV_GET_SEQ_ELEM( CvPoint*, hull, i );
            cvLine( img_8uc3, pt0, pt, CV_RGB( 0, 255, 0 ), 1, CV_AA, 0 );
            pt0 = pt;
        }


cvReleaseMemStorage( &storage );
cvReleaseMemStorage( &storage1 );
//return 0;
}
}

  cvShowImage( "Raw", img_8uc3 );
 
}

