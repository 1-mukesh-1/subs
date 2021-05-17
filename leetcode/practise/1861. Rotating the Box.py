def lstspl(l):
    l.append("*")
    temp=[]
    start=0
    for i in range(len(l)):
        if(l[i]=="*"):
            temp.append(l[start:i])
            start=i+1
    return temp
def holy(l):
    x,y=0,0
    for q in l:
        if(q=="#"):
            x+=1
        else:
            y+=1
    temp=[]
    for i in range(y):
        temp.append(".")
    for i in range(x):
        temp.append("#")
    return temp
def gravity(l):
    temp=lstspl(l)
    for i in range(len(temp)):
        temp[i]=holy(temp[i])
    l=[]
    for x in temp:
        l.extend(x)
        l.append("*")
    return l[:-1]
class Solution:
    def rotateTheBox(self, l: List[List[str]]) -> List[List[str]]:
        for i in range(len(l)):
            l[i]=gravity(l[i])
        ans=[[0 for i in range(len(l))] for i in range(len(l[0]))]
        m=0
        n=0
        for i in range(len(l)):
            for j in range(len(l[0])):
                ans[j][n-1-i]=l[i][j]
        return ans
