from PIL import Image, ImageDraw

f = input()
c = input()
n = int(input())
p = input()

img = Image.new('RGB', (n, n), f)
dib = ImageDraw.Draw(img)

if (p == "dreta"):
    dib.polygon([(0, n-1), (n-1, n-1), (n-1, 0)], c)
else:
    dib.polygon([(0, n-1), (n-1, n-1), (0, 0)], c)

img.save('output.png')
img.show()
