import sys

kraj = False


def keyExistsInDict(dict, key):
    if key in dict:
        t = dict.get(key)
        splitArr = t.split(',')
        # check = all(item in konacni for item in splitArr)
        novoStanje.extend(splitArr)


konacni = []


def printHash(string):
    if string != '':
        # print(strin + "|", end="")
        konacni.append(string)
    else:
        # print('#' + "|", end="")
        konacni.append('#')


def printHashList(list):
    if list != '':
        # print(strin + "|", end="")
        konacni.append(list)
    else:
        # print('#' + "|", end="")
        konacni.append('#')


#arr = ['a,b,c,b,a,d\n', 's1,s2,s3,s4,s5,s6,s7\n', 'a,b,c,d\n', 's2,s5\n', 's1\n', 's1,$->s3,s6,s7\n', 's1,a->s1,s3\n', 's1,b->s5\n', 's1,c->s3\n', 's1,d->s3\n', 's2,$->s2\n', 's2,a->s3\n', 's2,b->s1,s5\n', 's2,c->s2,s2\n', 's2,d->s4\n', 's3,$->s3\n', 's3,a->#\n', 's3,b->s2,s3\n', 's3,c->s4,s5\n', 's3,d->s1\n', 's4,a->s4\n', 's4,b->s1,s4\n', 's4,c->s1,s5\n', 's5,a->s1\n', 's5,b->s5\n']

i = 0
arr = []

for line in sys.stdin:
    arr.insert(i, line)
    i = i + 1

ulaz = arr[0].strip()
states = arr[5:]
q0 = arr[4].strip()

x = ulaz.split('|')

dict = {}

for i in states:
    i = i.strip()  # makni \n

    y = i.split('->')
    z = y[0].split(',')
    z1 = y[1].split(',')

    if '#' in z or '#' in z1:
        continue
    else:
        dict[y[0]] = y[1]

novoStanje = []
trenutnoStanje = [q0]

for i in x:
    ulazniElList = i.split(',')  # a,pnp,a

    novoStanje = []
    trenutnoStanje = [q0]

    for znakElementa in ulazniElList:
        novoStanje = []

        for posebnaStanja in trenutnoStanje:
            key = posebnaStanja + ',' + '$'
            if key in dict:
                t = dict.get(key)
                splitArr = t.split(',')

                tempArr = []
                for x in splitArr:
                    if x not in tempArr and x not in trenutnoStanje:
                        tempArr.append(x)

                trenutnoStanje.extend(tempArr)


        trenutnoStanje.sort()
        strin = ((','.join(map(str, trenutnoStanje)).strip()))

        printHashList(strin)

        for posebnaStanja in trenutnoStanje:
            key = posebnaStanja + ',' + znakElementa
            if key in dict:
                t = dict.get(key)
                splitArr = t.split(',')
                tempArr = []
                for x in splitArr:
                    if x not in tempArr and x not in novoStanje:
                        tempArr.append(x)


                novoStanje.extend(tempArr)

        trenutnoStanje.clear()
        trenutnoStanje.extend(novoStanje)


    for posebnaStanja in trenutnoStanje:
        key = posebnaStanja + ',' + '$'
        if key in dict:
            t = dict.get(key)
            splitArr = t.split(',')
            tempArr = []
            for x in splitArr:
                if x not in tempArr and x not in trenutnoStanje:
                    tempArr.append(x)

            trenutnoStanje.extend(tempArr)

    trenutnoStanje.sort()
    strin = ((','.join(map(str, trenutnoStanje)).strip()))
    printHashList(strin)

    konacni = '|'.join(konacni)

    print(konacni)
    konacni = []






