n,k=list(map(int,input().split()))
l=list(map(int,input().split()))
dp=[k+1 for i in range(k+1)]
dp[0]=0
for x in l:
    for i in range(x,k+1):
        dp[i]=min(1+dp[i-x],dp[i])
print(-1 if dp[-1]>k else dp[-1])
