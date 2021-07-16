o = input('introdueix la operacio (s, r, m, d): ')
x = int(input('introdueix el primer valor: '))
y = int(input('introdueix el segon valor: '))

print('La resposta a la operació és: ')
if (o == 's'):
    print(x+y)
elif (o == 'r'):
    print(x-y)
elif (o == 'm'):
    print(x*y)
elif (o == 'd'):
    print(x/y)
else:
    print('Que krak ka ets, no saps ascriura o ke kruk makinola?!')
