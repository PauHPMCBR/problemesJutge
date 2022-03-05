from PIL import Image, ImageDraw

f = input()
c1 = input()
c2 = input()
c3 = input()
n = int(input())

img = Image.new('RGB', (25 * pow(2, n), 25 * pow(2, n)), f)
size = 25 * pow(2, n)
dib = ImageDraw.Draw(img)

for x in range(n):
    dib.ellipse([size - size/pow(2, x), size - size/pow(2, x), size - size/pow(2, x+1)-1, size - size/pow(2, x+1)-1], c2)
    dib.ellipse([size - size/pow(2, x), size - size/(pow(2, x)*2), size - size/pow(2, x+1)-1, size-1], c1)
    dib.ellipse([size - size/(pow(2, x)*2), size - size/pow(2, x), size-1, size - size/pow(2, x+1)-1], c3)

img.save('output.png')
