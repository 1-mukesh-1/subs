MOD=1000000007
def linput():
    return list(map(int,input().split()))
for _ in range(int(input())):
    n=int(input())
    x=input()
    zero=0
    one=0
    flag=False
    for i in range(n):
        if(x[i]=="0"):
            zero+=1
        else:
            one+=1
        if(zero<=one):
            flag=True
            break
    if(flag):
        print("YES")
    else:
        print("NO")
