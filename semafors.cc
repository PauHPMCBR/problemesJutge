from PIL import Image, ImageDraw

img = Image.new('RGB', (600, 900), 'SkyBlue')
dib = ImageDraw.Draw(img)

dib.polygon([(50, 50), (50, 849), (349, 849), (349, 50)], 'Orange')
dib.polygon([(350, 400), (350, 499), (599, 499), (599, 400)], 'DimGrey')

dib.ellipse([(100, 100), (299, 299)], 'Black')
dib.ellipse([(100, 350), (299, 549)], 'Black')
dib.ellipse([(100, 600), (299, 799)], 'Black')

v = input()
if (v == 'AC'):
    dib.ellipse([(100, 600), (299, 799)], 'Green')
    
elif (v == 'PE'):
    dib.ellipse([(100, 350), (299, 549)], 'Yellow')
    
else:
    dib.ellipse([(100, 100), (299, 299)], 'Red')

img.save('output.png')