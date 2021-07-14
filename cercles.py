from PIL import Image, ImageDraw

c1 = input()
c2 = input()
c3 = input()
n = int(input())
k = int(input())

img = Image.new('RGB', (n, n), c1)
dib = ImageDraw.Draw(img)

for x in range(n//(2*k) + 1):
    if (x*k < n-x*k):
        dib.ellipse([x*k, x*k, n-x*k-1, n-x*k-1], c2, c3)

img.save('output.png')
