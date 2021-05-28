def linput():
    return list(map(int,input().split()))
for _ in range(int(input())):
    n=int(input())
    l=sorted(linput())
    ans=[0 for i in range(2*n)]
    for i in range(n):
        ans[2*i]=l[i]
        ans[2*i+1]=l[n+i]
    print(*ans)
