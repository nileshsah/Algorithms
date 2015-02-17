import sys
for n in sys.stdin.readlines():
    n = int(n)
    DP = [[0 for x in range(2)] for x in range(n+1)]
    DP[n][0] = 1
    DP[n][1] = 1
    for i in range(n-1,0,-1):
        DP[i][0] = DP[i+1][1]
        DP[i][1] = DP[i+1][0] + DP[i+1][1]
    print (DP[1][1] + DP[1][0])
