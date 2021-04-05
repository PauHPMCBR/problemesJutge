from PIL import Image, ImageDraw

c = int(input())
f = int(input())
traspas = c
c = f
f = traspas

img = Image.new('RGB', (100*f, 100*c))
dib = ImageDraw.Draw(img)

for x in range(f):
    for y in range(c):
        if (x%2 == 1):
            if (y%2 == 1):
                dib.polygon([(x*100, y*100), ((x+1)*100-1, y*100), ((x+1)*100-1, (y+1)*100-1), (x*100, (y+1)*100-1)], 'Yellow')
            else:
                dib.polygon([(x*100, y*100), ((x+1)*100-1, y*100), ((x+1)*100-1, (y+1)*100-1), (x*100, (y+1)*100-1)], 'Green')
        else:
            if (y%2 == 1):
                dib.polygon([(x*100, y*100), ((x+1)*100-1, y*100), ((x+1)*100-1, (y+1)*100-1), (x*100, (y+1)*100-1)], 'Green')
            else:
                dib.polygon([(x*100, y*100), ((x+1)*100-1, y*100), ((x+1)*100-1, (y+1)*100-1), (x*100, (y+1)*100-1)], 'Yellow')


img.save('output.png')
img.show()
