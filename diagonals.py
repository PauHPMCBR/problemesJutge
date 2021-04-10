from PIL import Image, ImageDraw

f = input()
n = int(input())
a = int(input())
r1 = int(input())
g1 = int(input())
b1 = int(input())
r2 = int(input())
g2 = int(input())
b2 = int(input())

img = Image.new('RGB', (n*a, n*a), f)
dib = ImageDraw.Draw(img)



img.save('output.png')
img.show()
