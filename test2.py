import keyboard
from random import randint as rng
import time

def printChar(x):
	keyboard.write(x)
	time.sleep(rng(2,4)/100)

time.sleep(1)

s = """La mecanografia és fonamental avui en dia per millorar la qualitat i
velocitat del treball. El terme mecanografia prové de les paraules mecano
(Mecànic - Màquina) i grafia (Lletra), i és el procés d'introduir text a un
dispositiu mitjançant un teclat. El terme es va inventar per quan es van
començar a utilitzar les primeres màquines d'escriure mecàniques. El teclat
QWERTY és la distribució de teclat més comuna. El seu nom sorgeix de les
lletres de les primeres sis tecles de la fila superior. El curs disponible
a mecanografia.cat permet aprendre a teclejar amb els 10 dits sense mirar
el teclat. Amb la tècnica apresa i una mica de pràctica es poden aconseguir
velocitats sorprenents."""

for i in s:
	printChar(i)