from PIL import Image, ImageDraw

n = int(input())
m = int(input())
c = input()
f = input()


img = Image.new('RGB', (25*n, 25*m), f)
dib = ImageDraw.Draw(img)

for j in range(m):
    dib.line([(12, 25*j + 12), (25*n - 12, 25*j + 12)], c)
    for i in range(n):
        dib.ellipse([(25*i + 5, 25*j + 5), (25*(i+1) - 6, 25*(j+1) - 6)], c)

for i in range(m-1):
    if i%2 == 1:
        dib.line([(12, 25*i+12), (12, 25*(i+1)+12)], c)
    else:
        dib.line([(25*n - 13, 25*i+12), (25*n - 13, 25*(i+1)+12)], c)

img.save('output.png')
img.show()
