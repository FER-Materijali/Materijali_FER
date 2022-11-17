import  sys

i = 0
arr = []

for line in sys.stdin:
    arr.insert(i, line)
    i = i + 1

#arr =['a,a,b\n', 'q0,q1,q2\n', 'a,b\n', 'K,X\n', 'q2\n', 'q0\n', 'K\n', 'q0,a,K->q0,XK\n', 'q0,$,X->q1,XX\n', 'q1,$,X->q1,KX\n', 'q1,a,K->q1,K\n', 'q1,b,K->q2,K\n', 'q2,$,K->q2,XK\n']



ulaz = arr[0].strip()

prihvatljivaStanja=arr[4].strip()
pocetnoStanje=arr[5].strip()
znakStacka=arr[6].strip()

pocetnoStanjeCopy=pocetnoStanje
pocZnakStackaCopy=znakStacka

states = arr[7:]

ulazniZnakovi = ulaz.split('|')

dict = {}

for i in states:
    i = i.strip()  # makni \n

    y = i.split('->')
    dict[y[0]] = y[1]

solution=[]



for input in ulazniZnakovi:

    printFirstTime = True
    input=input.replace(',','')
    znakStacka=pocZnakStackaCopy
    pocetnoStanje=pocetnoStanjeCopy
    praznoStanje=False

    while True:
        if len(input) > 0:
            firstLetter = input[0]
            dictKey = pocetnoStanje+','+firstLetter+','+znakStacka
            if printFirstTime:
                znakStacka=pocZnakStackaCopy
                solution.append(pocetnoStanje+'#'+znakStacka)
                printFirstTime = False
                dictKey = pocetnoStanje + ',' + firstLetter + ',' + znakStacka

            if len(znakStacka)>1:
                dictKey = pocetnoStanje + ',' + firstLetter + ',' + znakStacka[0]
            elif znakStacka=='':
                dictKey = pocetnoStanje + ',' + firstLetter + ',' + '$'

            dicKeySplitPraznimStanjem= dictKey.split(',')
            dictSaPraznimStanjem=dicKeySplitPraznimStanjem[0]+','+'$'+','+dicKeySplitPraznimStanjem[2]

            if dictKey in dict or dictSaPraznimStanjem in dict:

                if input == '$':
                   if pocetnoStanje in prihvatljivaStanja:
                      solution.append('1')
                      print('|'.join(solution))
                      break

                valueDict=dict.get(dictKey)
                if valueDict== None:
                    valueDict = dict.get(dictSaPraznimStanjem)
                    praznoStanje=True
                stateQ=valueDict.split(',')
                znakStacka=znakStacka[1:]
                znakStacka=stateQ[1]+znakStacka
                if znakStacka[0]=='$':
                    znakStacka=znakStacka.replace('$','')
                    if znakStacka=='':
                        znakStacka='$'
                pocetnoStanje=stateQ[0]
                if not praznoStanje:
                    firstLetter=input[1:]
                    input=input[1:]

                praznoStanje=False
                if input=='':
                    input='$'
                solution.append(pocetnoStanje+'#'+znakStacka)

            elif input == '$':
                if pocetnoStanje in prihvatljivaStanja:
                    solution.append('1')
                    print('|'.join(solution))

                else:
                    solution.append('0')
                    print('|'.join(solution))

                solution = []
                break
            else:
                solution.append('fail|0')
                print('|'.join(solution))
                solution=[]
                break
