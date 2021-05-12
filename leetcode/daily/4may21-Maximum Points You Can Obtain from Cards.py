class Solution:
    def maxScore(self, l: List[int], k: int) -> int:
        n=len(l)
        l.extend(l)
        summ=sum(l[n-k:n])
        maxi=summ
        for i in range(n-k,n):
            summ+=(l[i+k]-l[i])
            maxi=max(maxi,summ)
        return maxi
