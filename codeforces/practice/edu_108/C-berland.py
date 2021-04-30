def linput():
    return list(map(int,input().split()))
for _ in range(int(input())):
    n=int(input())
    u=linput()
    s=linput()
    d=dict()
    for i in range(n):
        try:
            d[u[i]].append(s[i])
        except:
            d[u[i]]=[s[i]]
    for x in d.keys():
        temp=sorted(d[x],reverse=True)
        for i in range(1,len(temp)):
            temp[i]+=temp[i-1]
        d[x]=temp
    ans=[0 for i in range(n)]
    for i in range(1,n+1):
        summ=0
        for arr in d.values():
            x=((len(arr)//i)*i)-1
            if(x<0):
                continue
            else:
                summ+=arr[x]
        ans[i-1]=summ
        if(summ==0):
            break
    print(*ans)
