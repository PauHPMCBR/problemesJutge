from PIL import Image, ImageDraw

n = int(input())
m = int(input())
x = int(input())
y = int(input())
c = int(input())
p = int(input())

img = Image.new('RGB', (n, m), 'SkyBlue')
dib = ImageDraw.Draw(img)

for w in range(n):
    for z in range(m):
        i = abs(x-w)
        j = abs(y-z)
        if (n - abs(x-w) < abs(x-w)): i = n - abs(x-w)
        if (m - abs(y-z) < abs(y-z)): j = m - abs(y-z)
        d = i + j
        
        r = 0
        g = 0
        b = 0
        rnb = 1529-c*d
        if (rnb < 255):
            r = 255
            g = rnb
            b = 0
            
        elif (rnb < 510):
            r = 510-rnb
            g = 255
            b = 0
            
        elif (rnb < 765):
            r = 0
            g = 255
            b = rnb-510
                       
        elif (rnb < 1020):
            r = 0
            g = 1020-rnb
            b = 255
            
        elif (rnb < 1275):
            r = rnb-1020
            g = 0
            b = 255
            
        else:
            r = 255
            g = 0
            b = 1530-rnb
                                                      
        dib.point((w, z), (r, g, b))
dib.pieslice([x-p, y-p, x+p, y+p], 45, 315, 'Yellow')

img.save('output.png')
