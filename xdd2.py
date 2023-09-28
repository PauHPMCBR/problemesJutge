T = int(input())

for i in range(T):
    n, m = list(map(int, input().split()))
    a = n//m
    b = (n + m -1) // m
    c = (m - (n % m))%m #Numeros con el floor, queremos ver si es multiplo del primer 0
    
    
    it = 0
    while ((1 << it)&a):
        it = it+1
    
    
    it = (1 << it)
    it = it // 2
    # ~ print("h ", t)

    p = 0
    guar = c
    # ~ print()
    # ~ print(n, m, c, a, b, p, it)

    po = 2
    while ((c != 0 or it == 1) and (po - (guar % po))%po <= c//2):
        # ~ print(guar)
        p = p + it
        it = it // 2
        guar = c - 2*((po - (guar % po))%po)
        po = 2*po
        # ~ print() 
        # ~ print(guar)
        # ~ print()
        # ~ print()
        
        if (it == 1):
            c = 0
            
        # ~ print(guar, c, p)
        # ~ print((po - (guar % po))%po, c//2)
        
    # ~ print(n, m, c, a, b, p, it)
    # ~ print()
    # ~ print()
    # ~ print()
    
    print((a | b) - p)