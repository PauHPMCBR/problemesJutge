from PIL import Image, ImageDraw

def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)

n = input()

img = Image.new('RGB', (100*int(n), 100), 'White')
dib = ImageDraw.Draw(img)

col = list()
for x in range(0, int(n)):
    col.append(input())

col.sort()

for c in range(0, int(n)):
    rect(c*100, 0, c*100+100, 100, col[c])


img.save('output.png')
img.show()
