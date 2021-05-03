def util(s):
    if(len(s)==0):
        return True
    x=""
    flag=False
    for i in range(len(s)):
        x+=s[i]
        prev=int(x)
        y=""
        for j in range(i+1,len(s)):
            y+=s[j]
            # print(x,y)
            pres=int(y)
            if(prev-pres==1):
                if(j==len(s)-1):
                    return True
                flag|=util(s[i+1:])
            if(prev<pres):
                break
            if(flag):
                return True
        if(flag):
            return True
    if(flag):
            return True
    return False
class Solution:
    def splitString(self, s: str) -> bool:
        return util(s)
