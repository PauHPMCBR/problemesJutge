import sys, numpy

for line in sys.stdin:
    l = line.split()
    n = int(l[0])
    a = int(l[1])
    b = int(l[2])
    esq = 1
    dre = max(a,b)*n
    mig = 0
    while esq <= dre:
        mig = (esq+dre)//2
        if (mig//a)*(mig//b) < n:
            esq = mig+1
        else:
            dre = mig-1
    print(esq)
