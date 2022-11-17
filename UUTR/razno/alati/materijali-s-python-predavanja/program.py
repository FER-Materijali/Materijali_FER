import fileinput

inp = fileinput.input()

unos = inp.readline().strip()


def zbroji(x, y, z = 10):
    return x + y*2 + z*3


zbroj = zbroji(1, 10)
print('zbroj je ' + str(zbroj))

zbroj = zbroji(1, 2, 3)

print('zbroj je ' + str(zbroj))

zbroj = zbroji(x = 10, z= 21, y = 18)


print('zbroj je ' + str(zbroj))
