from PIL import Image, ImageDraw

def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)

x = int(input())
y = int(input())

img = Image.new('RGB', (x, 9*y), 'White')
dib = ImageDraw.Draw(img)


for n in range(9):
    if (n % 2) == 0:
        col = 'Yellow'
    else:
        col = 'Red'
    rect(0, n*y, x - 1, (n+1)*y, col)

img.save('output.png')
img.show()
