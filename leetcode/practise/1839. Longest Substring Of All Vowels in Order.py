class Solution:
    def longestBeautifulSubstring(self, s: str) -> int:
        s+="0"
        n=len(s)
        l=[]
        i=0
        while(i<n):
            if(s[i]=="a"):
                l.append(i)
                while(s[i]=="a" and i<n):
                    i+=1
            i+=1
        l.append(n-1)
        maxi=0
        for i in range(len(l)-1):
            start=l[i]
            end=l[i+1]
            x=start
            prev=s[x]
            temp=""
            c=0
            while(x<end):
                temp+=prev
                while(s[x]==prev and x<end):
                    x+=1
                    c+=1
                prev=s[x]
                if(temp=="aeiou"):
                    maxi=max(maxi,c)
        return maxi
