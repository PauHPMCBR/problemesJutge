import sys

for line in sys.stdin:
    n = line
    n = n[0:-1]
    print("le ", end='')
    n = n.replace('oi', 'ua')
    n = n.replace('r', 'rg')
    if n.endswith('nt'):
        n = n[0:-2]
        print(n+'ng')
    else:
        print(n)