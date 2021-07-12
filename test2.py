import keyboard
from random import randint as rng
import time

def printChar(x):
	keyboard.write(x)
	time.sleep(rng(1,6)/100)

time.sleep(1)

s = """La Sagrada Família és una gran basílica catòlica de Barcelona, dissenyada
per l'arquitecte català Antoni Gaudí. Iniciada el 1882, encara està en
construcció. És l'obra mestra de Gaudí, i el màxim exponent de
l'arquitectura modernista catalana. El 1926 va morir Gaudí i només s'havia
construït una torre. Del projecte de l'edifici només es conservaven plànols
i un model en guix que va ser molt malmès durant la Guerra Civil espanyola.
Des de llavors han prosseguit les obres. La Sagrada Família va ser
declarada Patrimoni de la Humanitat per la UNESCO l'any 2005. El
Temple va ser consagrat i declarat Basílica menor el 7 de novembre del 2010
pel papa Benet XVI."""

for i in s:
	printChar(i)