from PIL import Image, ImageDraw


def update():
    updates = 0
    for i in range(n):
        for j in range(m):
            if v[i][j] == 'C':
                if i > 0:
                    if v[i-1][j] == 'E' or v[i-1][j] == 'D':
                        v[i][j] = 'E'
                        updates += 1
                if i < n-1:
                    if v[i+1][j] == 'E' or v[i+1][j] == 'D':
                        v[i][j] = 'E'
                        updates += 1
                if j > 0:
                    if v[i][j-1] == 'E' or v[i][j-1] == 'D':
                        v[i][j] = 'E'
                        updates += 1
                if j < m-1:
                    if v[i][j+1] == 'E' or v[i][j+1] == 'D':
                        v[i][j] = 'E'
                        updates += 1

            if v[i][j] == 'B':
                if i > 0:
                    if v[i-1][j] == 'E' or v[i-1][j] == 'F' or v[i-1][j] == 'D':
                        v[i][j] = 'F'
                        updates += 1
                if i < n-1:
                    if v[i+1][j] == 'E' or v[i+1][j] == 'F' or v[i+1][j] == 'D':
                        v[i][j] = 'F'
                        updates += 1
                if j > 0:
                    if v[i][j-1] == 'E' or v[i][j-1] == 'F' or v[i][j-1] == 'D':
                        v[i][j] = 'F'
                        updates += 1
                if j < m-1:
                    if v[i][j+1] == 'E' or v[i][j+1] == 'F' or v[i][j+1] == 'D':
                        v[i][j] = 'F'
                        updates += 1
    return updates > 0

def setColor(c):
    if c == 'A':
        return 'Aqua'
    if c == 'B':
        return 'ForestGreen'
    if c == 'F':
        return 'LawnGreen'
    if c == 'C':
        return 'Black'
    if c == 'E':
        return 'Silver'
    if c == 'D':
        return 'Yellow'

m = int(input())
n = int(input())

v = [None] * n
p = [None] * n
for i in range(n):
    p[i] = input()
    v[i] = list(p[i])


while(update()):
    continue



img = Image.new('RGB', (30*m, 30*n))
dib = ImageDraw.Draw(img)

for i in range(m):
    for j in range(n):
        dib.polygon([(i*30, j*30), ((i+1)*30-1, j*30), ((i+1)*30-1, (j+1)*30-1), (i*30, (j+1)*30-1)], setColor(v[j][i]))

img.save('output.png')
img.show()
