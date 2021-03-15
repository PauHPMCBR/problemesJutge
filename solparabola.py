from PIL import Image, ImageDraw


def f(x):
    return (a*x*x + b*x + c)//z


a = int(input())
b = int(input())
c = int(input())
z = int(input())
e = int(input())
d = int(input())

mn = mx = f(e)
for x in range (e + 1, d + 1):
    y = f(x)
    mn = min(mn, y)
    mx = max(mx, y)

m = mx - mn + 1

img = Image.new('RGB', (d - e + 1, m), 'Beige')
dib = ImageDraw.Draw(img)


for x in range (e, d + 1):
    dib.point((x - e, m - (f(x) - mn) - 1), 'Blue')


img.save("output.png")
img.show()
