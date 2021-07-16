from PIL import Image, ImageDraw

def dibCircle(x, y, colorID):
    color = 'White'
    if colorID == 0:
        color = 'DodgerBlue'
    elif colorID == 1:
        color = 'Lime'
    elif colorID == 2:
        color = 'Magenta'
    elif colorID == 3:
        color = 'Red'
    dib.ellipse([(50*y + 5, 50*x + 5), (50*(y+1) - 6, 50*(x+1) - 6)], color)

def increase(v, i, j, currentLetter):
    p = i-2
    if p >= 0:
        if v[p][j] == v[p+1][j]:
            if currentLetter == v[p][j]:
                return True
    p = j-2
    if p >= 0:
        if v[i][p] == v[i][p+1]:
            if currentLetter == v[i][p]:
                return True
    p = i+2
    if p < f:
        if v[p][j] == v[p-1][j]:
            if currentLetter == v[p][j]:
                return True
    p = j+2
    if p < c:
        if v[i][p] == v[i][p-1]:
            if currentLetter == v[i][p]:
                return True

    if i < f-1 and i > 0:
        if v[i-1][j] == v[i+1][j]:
            if v[i-1][j] == currentLetter:
                return True

    if j < c-1 and j > 0:
        if v[i][j-1] == v[i][j+1]:
            if v[i][j-1] == currentLetter:
                return True
    return False


c = int(input())
f = int(input())

img = Image.new('RGB', (50*c, 50*f), 'Black')
dib = ImageDraw.Draw(img)

v = [None] * f
for i in range(f):
    v[i] = [None] * c
    a = input()
    for j in range(c):
        if a[j] == '.':
            continue
        else:
            if a[j] == 'D':
                v[i][j] = 0
            elif a[j] == 'L':
                v[i][j] = 1
            elif a[j] == 'M':
                v[i][j] = 2
            elif a[j] == 'R':
                v[i][j] = 3
            elif a[j] == 'W':
                v[i][j] = 4

for i in range(f):
    for j in range(c):
        if v[i][j] == None:
            currentLetter = 0
            while (increase(v, i, j, currentLetter)):
                currentLetter += 1

            v[i][j] = currentLetter

        dibCircle(i, j, v[i][j])


img.save('output.png')
