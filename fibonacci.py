from PIL import Image, ImageDraw



f = input()
r = int(input())
g = int(input())
b = int(input())
k = int(input())
fib = [0]*(k+1)
for i in range(k+1):
    if i < 2:
        fib[i] = 1
    else:
        fib[i] = fib[i-1] + fib[i-2]

img = Image.new('RGB', [fib[i], fib[i-1]], f)
dib = ImageDraw.Draw(img)

fib.reverse()
x1 = 0
y1 = 0
x2 = fib[0]-1
y2 = fib[1]-1
fib.pop(0)

for i in range(k):
    if i%4 == 0:
        coords = [(x1+fib[i]-1,y1), (x1+fib[i]-1,y1+fib[i]-1), (x1,y1+fib[i]-1)]
        x1 += fib[i]
    elif i%4 == 1:
        coords = [(x1,y1), (x1+fib[i]-1,y1+fib[i]-1), (x1,y1+fib[i]-1)]
        y1 += fib[i]
    elif i%4 == 2:
        coords = [(x2-fib[i]+1,y1), (x2,y1), (x2-fib[i]+1,y1+fib[i]-1)]
        x2 -= fib[i]
    else:
        coords = [(x1,y2-fib[i]+1), (x1+fib[i]-1,y2-fib[i]+1), (x1+fib[i]-1,y2)]
        y2 -= fib[i]
    if i+2 >= k:
        dib.point((coords[0]), ((k-i)*r, (k-i)*g, (k-i)*b))
    else:
        dib.polygon(coords, ((k-i)*r, (k-i)*g, (k-i)*b))


img.save('output.png')
