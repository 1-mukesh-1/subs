""" 
Method 1: Brute force [rotate and find sum]
Method 2: This method discusses the efficient solution which solves the problem in O(n) time. 
In the naive solution, the values were calculated for every rotation. 
So if that can be done in constant time then the complexity will decrease.
"""

def max_sum(l,n):
    summ=sum(l)
    tot=0
    maxi=-100000000000
    for i in range(n):
        tot+=i*l[i]
    for x in l[::-1]:
        tot=tot+summ-n*x
        maxi=max(maxi,tot)
    return maxi
