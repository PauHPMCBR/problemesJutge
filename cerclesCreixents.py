from PIL import Image, ImageDraw

f = input()
r = int(input())
g = int(input())
b = int(input())
n = int(input())
a = int(input())

long = (n*(n+1))//2

img = Image.new('RGB', (a*long, a*n), f)
dib = ImageDraw.Draw(img)

start = 0


for i in range(n):
    dib.ellipse([(start, a*n-a*(i+1)), (start+a*(i+1)-1, a*n-1)], (r*(i+1), g*(i+1), b*(i+1)))
    start += a*(i+1)

img.save('output.png')
