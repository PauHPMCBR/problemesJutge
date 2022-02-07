from PIL import Image, ImageDraw

n = int(input())
b = input()
c = input()


img = Image.new('RGB', (n, n), b)
dib = ImageDraw.Draw(img)

for x in range(n//2):
    if (x % 2 == 0):
        if ((x+2 <= n//2) or (n % 2 == 1)):
            dib.line([(x, x+1), (n-x-2, x+1)], c)
            dib.line([(x+1, n-x-2), (n-x-2, n-x-2)], c)
    if (x % 2 == 1):
        dib.line([(n-x-1, x), (n-x-1, n-x-1)], c)
        if (x+2 <= n//2):
            dib.line([(x, x+2), (x, n-x-1)], c)


img = img.resize((50*n, 50*n), Image.BOX)

img.save('output.png')