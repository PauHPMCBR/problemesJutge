from PIL import Image, ImageDraw


f = input()
c = input()
n = int(input())
m = int(input())
x = 0
y = 0
mx = 1
my = 1

img = Image.new('RGB', (50*n, 50*m), f)
dib = ImageDraw.Draw(img)

dib.ellipse([(50*x, 50*y), (50*(x+1)-1, 50*(y+1)-1)], c)
x += mx
y += my
while (0==0):
    if (x == 0 or x == n-1):
        mx = mx*-1
        if (y == 0 or y == m-1):
            break
    elif (y == 0 or y == m-1):
        my = my*-1

    dib.ellipse([(50*x, 50*y), (50*(x+1)-1, 50*(y+1)-1)], c)
    x += mx
    y += my

dib.ellipse([(50*x, 50*y), (50*(x+1)-1, 50*(y+1)-1)], c)

img.save('output.png')
