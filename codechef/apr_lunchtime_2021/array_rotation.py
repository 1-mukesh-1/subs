MOD=1000000007
def linput():
    return list(map(int,input().split()))
n=int(input())
l=linput()
summ=sum(l)
q=int(input())
qrs=linput()
for i in range(q):
    summ*=2
    print(summ%MOD)
