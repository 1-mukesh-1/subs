from math import ceil
for _ in range(int(input())):
    n,k=list(map(int,input().split()))
    l=list(map(int,input().split()))
    vals=[]
    l.sort()
    vals.append(l[0]-1)
    for i in range(1,n):
        vals.append(ceil((l[i]-l[i-1]-1)/2))
    vals.append(k-l[-1])
    vals.sort()
    ans=vals[-1]+vals[-2]
    for i in range(n-1):
        ans=max(ans,l[i+1]-l[i]-1)
    print("Case #"+str(_+1)+": "+str(round(ans/k,6)))
