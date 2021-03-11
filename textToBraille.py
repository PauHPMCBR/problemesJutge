braille = {
    'a': '100000',
    'b': '110000',
    'c': '100100',
    'd': '100110',
    'e': '100010',
    'f': '110100',
    'g': '110110',
    'h': '110010',
    'i': '010100',
    'j': '010110',
    'k': '101000',
    'l': '111000',
    'm': '101100',
    'n': '101110',
    'o': '101010',
    'p': '111100',
    'q': '111110',
    'r': '111010',
    's': '011100',
    't': '011110',
    'u': '101001',
    'v': '111001',
    'w': '010111',
    'x': '101101',
    'y': '101111',
    'z': '101011',
    '#': '001111',
    '1': '100000',
    '2': '110000',
    '3': '100100',
    '4': '100110',
    '5': '100010',
    '6': '110100',
    '7': '110110',
    '8': '110010',
    '9': '010100',
    '0': '010110',
    ' ': '000000'}

cap = '000001'

def lel(x):
    if x == '1':
        return '*'
    return '.'

s = input().split()
v = []
for x in s:
    if x.isupper():
        v.append(cap)
        v.append(cap)
        x = x.lower()
    for l in x:
        if l.isupper():
            v.append(cap)
            l = l.lower()
        v.append(braille[l])
    v.append(' ')

for x in v:
    if x == ' ':
        print(' ', end='')
    else:
        print(lel(x[0])+lel(x[3]), end='')
print()
for x in v:
    if x == ' ':
        print(' ', end='')
    else:
        print(lel(x[1])+lel(x[4]), end='')
print()
for x in v:
    if x == ' ':
        print(' ', end='')
    else:
        print(lel(x[2])+lel(x[5]), end='')
print()