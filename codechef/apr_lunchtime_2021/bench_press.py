MOD=1000000007
def linput():
    return list(map(int,input().split()))
for _ in range(int(input())):
    n,w,wr=linput()
    l=linput()
    if(wr>=w):
        print("YES")
    else:
        d=dict()
        for i in range(n):
            try:
                d[l[i]]+=1
            except:
                d[l[i]]=1
        summ=wr
        for x in d.keys():
            summ+=(x*(d[x]//2)*2)
        if(summ>=w):
            print("YES")
        else:
            print("NO")
