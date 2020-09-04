from PIL import Image, ImageDraw

def create(a, b, c, d, e, f, pos):
    dib.ellipse([(pos+3, 3), (pos+26, 26)], a)
    dib.ellipse([(pos+33, 3), (pos+56, 26)], b)
    dib.ellipse([(pos+3, 33), (pos+26, 56)], c)
    dib.ellipse([(pos+33, 33), (pos+56, 56)], d)
    dib.ellipse([(pos+3, 63), (pos+26, 86)], e)
    dib.ellipse([(pos+33, 63), (pos+56, 86)], f)

def convert(a):
    if a == '1':
        return 'A'
    if a == '2':
        return 'B'
    if a == '3':
        return 'C'
    if a == '4':
        return 'D'
    if a == '5':
        return 'E'
    if a == '6':
        return 'F'
    if a == '7':
        return 'G'
    if a == '8':
        return 'H'
    if a == '9':
        return 'I'
    return 'J'

def callCreate(c, i):
    if c == 'A':
        create('Black', 'White', 'White', 'White', 'White', 'White', i*90)
    elif c == 'B':
        create('Black', 'White', 'Black', 'White', 'White', 'White', i*90)
    elif c == 'C':
        create('Black', 'Black', 'White', 'White', 'White', 'White', i*90)
    elif c == 'D':
        create('Black', 'Black', 'White', 'Black', 'White', 'White', i*90)
    elif c == 'E':
        create('Black', 'White', 'White', 'Black', 'White', 'White', i*90)
    elif c == 'F':
        create('Black', 'Black', 'Black', 'White', 'White', 'White', i*90)
    elif c == 'G':
        create('Black', 'Black', 'Black', 'Black', 'White', 'White', i*90)
    elif c == 'H':
        create('Black', 'White', 'Black', 'Black', 'White', 'White', i*90)
    elif c == 'I':
        create('White', 'Black', 'Black', 'White', 'White', 'White', i*90)
    elif c == 'J':
        create('White', 'Black', 'Black', 'Black', 'White', 'White', i*90)

s = input()
chars = list(s)
nums = 0
areWeOnChars = True
for char in chars:
    if char is None or char.isdigit():
        if areWeOnChars:
            nums +=1
            areWeOnChars = False
    else:
        areWeOnChars = True

img = Image.new('RGB', (60*(len(s) + nums) + 30*(len(s)-1 + nums), 90), 'LightBlue')
dib = ImageDraw.Draw(img)

add = 0

for i in range(len(chars)):
    if chars[i] == ' ':
        create('White', 'White', 'White', 'White', 'White', 'White', i*90 + add*90)
    elif chars[i] is None or chars[i].isdigit():
        create('White', 'Black', 'White', 'Black', 'Black', 'Black', i*90 + add*90)
        add += 1
        j = i
        while j < len(chars) and (chars[j] is None or chars[j].isdigit()):
            chars[j] = convert(chars[j])
            j += 1
        callCreate(chars[i], i+add)
    else:
        callCreate(chars[i], i+add)

img.save('output.png')
img.show()
