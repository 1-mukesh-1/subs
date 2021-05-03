import math
def issquare(x):
    if(x>=0):
        sr=int(math.sqrt(x))
        return ((sr*sr) == x)
    return false
for _ in range(int(input())):
    n=int(input())
    if(n%2!=0 and n%4!=0):
        print("NO")
        continue
    else:
        if(issquare(n/2)):
            print("YES")
            continue
        elif(n%4==0):
            if(issquare(n/4)):
                print("YES")
                continue
        else:
            print("NO")
            continue
    print("NO")
