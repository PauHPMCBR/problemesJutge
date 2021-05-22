import keyboard
from random import randint as rng
import time

def printChar(x):
	keyboard.write(x)
	time.sleep(rng(1,5)/100)

time.sleep(1)

s = """Les Canàries és un arxipèlag de l'Atlàntic que conforma una de les disset
comunitats autònomes d'Espanya i una de les regions ultraperifèriques de la
Unió Europea. Està format per set illes principals: El Hierro, La Gomera,
La Palma i Tenerife, que formen la província de Santa Cruz de Tenerife, i
Fuerteventura, Gran Canària i Lanzarote, que componen la província de Las
Palmas. També formen part de Canàries els territoris insulars de
l'arxipèlag Chinijo. Les illes són d'origen volcànic i el seu clima és
subtropical. Les Canàries tenen quatre parcs nacionals i és un important
destí turístic per la seva gran bellesa natural, les seves platges i un
clima privilegiat"""

for i in s:
	printChar(i)