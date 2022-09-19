from PIL import Image, ImageDraw


f = input()
c = input()
n = int(input())
a = int(input())

img = Image.new('RGB', ((2*n+1)*a, (n+1)*a), f)
dib = ImageDraw.Draw(img)

v = [False] * (2*n+1)
for i in range(2*n+1):
    v[i] = [False] * (n+1)

v[n][0] = True

for y in range(n):
    for x in range(2*n+1):

        if (x == 0 or x == 2*n):
            if (y == n-1):
                v[x][y+1] = True

        elif (v[x-1][y] == True):
            if ((v[x][y] == False) and (v[x+1][y] == False)):
                v[x][y+1] = True

        elif (v[x-1][y] == False):
            if ((v[x][y] == True) or (v[x+1][y] == True)):
                v[x][y+1] = True


for o in range(2*n+1):
    for p in range(n+1):
        if (v[o][p] == True):
            dib.polygon([(o*a, p*a), ((o+1)*a-1, p*a), ((o+1)*a-1, (p+1)*a-1), (o*a, (p+1)*a-1)], c)

img.save('output.png')
img.show()
