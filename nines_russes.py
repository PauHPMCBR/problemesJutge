from PIL import Image, ImageDraw

n = int(input())
c = int(input())

img = Image.new('RGB', (50*n, 50*n))
dib = ImageDraw.Draw(img)

colors = [None] * c

for x in range(c):
    colors[x] = input()

if (n%2 == 1): d = (n//2 + 1)
else: d = n//2

for y in range(d):
    dib.polygon([(y*50, y*50), (y*50, (n-y)*50-1), ((n-y)*50-1, (n-y)*50-1), ((n-y)*50-1, y*50)], colors[y%c])

img.save('output.png')
img.show()
