from PIL import Image, ImageDraw

#def triangle(x, y, mida, orientacio, r, g, b):
#    if mida == 1:
#        dib.point([x, y], r, g, b)
#        return
#    v = [[x,y],[x+mida,y],[x+mida,y+mida],[x,y+mida]]
#    a = v[orientacio]
#    b = v[orientacio-1]
#    c = v[orientacio-2]
#    dib.polygon([a[0], a[1], b[0], b[1], c[0], c[1]], r, g, b)

def lol(x1, y1, x2, y2, orientacio, it):
    x3 = x2
    y3 = y1
    #if orientacio == 1:

    dib.polygon([(x1, y1), (x1, y2-1), (x2-1, y2-1),(x2-1, y1)], 255, 255 it*30)
        

#f = input()
f = "Black"
#r = int(input())
#g = int(input())
#b = int(input())
it = int(input())
fib = [0]*it
for i in range(it):
    if i < 2:
        fib[i] = 1
    else:
        fib[i] = fib[i-1] + fib[i-2]

img = Image.new('RGB', [fib[i], fib[i-1]], f)
dib = ImageDraw.Draw(img)



n = fib[it-2]
m = fib[it-2]
for i in range(it):
    lol(0,0,n,m,1)
    

for i in fib:
    print(i)

img.show()
img.save('output.png')
