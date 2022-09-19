from PIL import Image, ImageDraw

n = int(input())
k = 250//n

img = Image.new('RGB', (1000, 1000), 'White')
dib = ImageDraw.Draw(img)

for i in range(n+1):
    if (i == 0): continue
    dib.ellipse([(500-2*k*i, 2*k*(i-1)), (499+2*k*i, 999-2*k*(i-1))], (250-(k*(i-1)), 0, k*i), 'Black')

img.save('output.png')
img.show()
