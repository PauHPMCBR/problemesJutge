from PIL import Image, ImageDraw

f = input()
c1 = input()
c2 = input()
c3 = input()
c4 = input()
n = int(input())
a = int(input())

img = Image.new('RGB', (n,n), f)
dib = ImageDraw.Draw(img)

dib.polygon([(2*a,a),(3*a-1,a),(3*a-1,n-3*a-1),(2*a,n-3*a-1)], c1)
dib.polygon([(2*a,a),(n-2*a-1,a),(n-2*a-1, 2*a-1),(2*a, 2*a-1)], c1)
dib.polygon([(n-2*a,a),(n-2*a,2*a-1),(n-a-1,2*a-1)], c1)

dib.polygon([(3*a,2*a),(n-a-1,2*a),(n-a-1,3*a-1),(3*a,3*a-1)], c2)
dib.polygon([(n-2*a, 2*a),(n-a-1, 2*a),(n-a-1, n-2*a-1),(n-2*a, n-2*a-1)], c2)
dib.polygon([(n-2*a,n-2*a),(n-a-1,n-2*a),(n-2*a,n-a-1)], c2)

dib.polygon([(n-3*a,3*a),(n-2*a-1,3*a),(n-2*a-1,n-a-1),(n-3*a,n-a-1)], c3)
dib.polygon([(2*a,n-2*a),(n-2*a-1,n-2*a),(n-2*a-1,n-a-1),(2*a,n-a-1)], c3)
dib.polygon([(a,n-2*a),(2*a-1,n-2*a),(2*a-1,n-a-1)], c3)

dib.polygon([(a,2*a),(2*a-1,2*a),(2*a-1,n-2*a-1),(a,n-2*a-1)], c4)
dib.polygon([(a,n-3*a),(n-3*a-1,n-3*a),(n-3*a-1,n-2*a-1),(a,n-2*a-1)], c4)
dib.polygon([(2*a-1,a),(2*a-1,2*a-1),(a,2*a-1)], c4)



img.save('output.png')