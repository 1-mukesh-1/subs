def linput():
    return list(map(int,input().split()))
for _ in range(int(input())):
    n,k=linput()
    l=linput()
    l.sort()
    summ=0
    for i in range(n):
        summ+=l[i]
        if(summ==k):
            summ-=l[i]
            l[i],l[-1]=l[-1],l[i]
            summ+=l[i]
    if(summ==k):
        print("NO")
    else:
        print("YES")
        print(*l)
