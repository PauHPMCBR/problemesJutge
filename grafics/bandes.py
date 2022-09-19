from PIL import Image, ImageDraw

a = int(input())
k = int(input())
n = 255//k+1


img = Image.new('RGB', (2*a*n+a, 2*a*n+a), 'White')
dib = ImageDraw.Draw(img)

for i in range(n):
    dib.polygon([(0, a+a*2*i), (0, 2*a+2*a*i-1), (2*a*n+a-1, 2*a+2*a*i-1), (2*a*n+a-1, a+a*2*i)], (0, 0, k*i))

for i in range(n):
    dib.polygon([(a+a*2*i, 0), (2*a+2*a*i-1, 0), (2*a+2*a*i-1, 2*a*n+a-1), (a+a*2*i, 2*a*n+a-1)], (k*i, 0, 0))

img.save('output.png')
img.show()
