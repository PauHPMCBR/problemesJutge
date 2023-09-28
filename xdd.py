T = int(input())

for i in range(T):
    n, m = list(map(int, input().split()))
    a = n//m
    b = (n + m -1) // m
    #c = (m - (n % m))%m #Numeros con el floor, queremos ver si es multiplo del primer 0
    c = (m - (n % m))
    if (c == m):
        c = 0
    
    # it = 0
    # while ((1 << it)&a):
    #     it = it+1
    
    
    # it = (1 << it)
    # it = it // 2

    it = 1
    while (it <= a):
        it *= 2
    it = it//2

    p = 0
    guar = c

    po = 2
    while ((c != 0 or it == 1)):
        print(c, it, p, guar, po)
        if guar == 0:
            p = p + it
            it = it // 2
            guar = c
            po = 2*po
            if (it == 1):
                c = 0

        elif (po - (guar % po)) <= c//2:
            p = p + it
            it = it // 2
            guar = c - 2*(po - (guar % po))
            po = 2*po
            if (it == 1):
                c = 0
        else:
            it = it // 2
            guar = c
            po = 2
            if (it == 1):
                c = 0
    
    print((a | b) - p)