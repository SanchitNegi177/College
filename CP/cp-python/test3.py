from math import comb

def validCombinations(A,B,C):
    mod=998244353
    res=(B*comb(A-1,C))%mod
    for i in range(C):
        res=(res*(B-1))%mod
    return res