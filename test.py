from PIL import Image, ImageDraw

img = Image.new('RGB', [10,10], 'White')
dib = ImageDraw.Draw(img)

dib.point((0,0), 'Black')
dib.rectangle([(3,3),(6,4)], 'Red')

img = img.resize((100,100), Image.BOX)

img.show()