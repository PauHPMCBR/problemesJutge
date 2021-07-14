from itertools import permutations

while True:
    s = input()
    if s == '0':
        break
    perms = [''.join(p) for p in permutations(s)]
    perms = list(set(perms))
    for lel in perms:
        print(lel)
