import itertools
import re
import sys
from collections import defaultdict

data = [line.strip() for line in sys.stdin.readlines() if len(line)]
relationsMatrix = defaultdict(list)
matchingMatrix = defaultdict(lambda: False)

def tablicaprijelaza(prijelazi):
    rezultat={}
    for prijelaz in prijelazi:
        r=re.match("^(.+?),(.+?)->(.+)$",prijelaz)
        sadasnje=r.group(1)
        znak=r.group(2)
        iduce=r.group(3)
        rezultat[(sadasnje,znak)]=iduce
      
    return rezultat

def nadjidohvatljiva(transitionDict, symbols, initial):
    dohvatljiva = []
    zaprobat = [pocetno]

    while (len(zaprobat)):
        trenutno = zaprobat.pop()

        if not (trenutno in dohvatljiva):
            dohvatljiva.append(trenutno)

            for znak in znakovi:
                zaprobat.append(tabprij[(trenutno, znak)])
    dohvatljiva.sort()
    return dohvatljiva

def nadjidohvprij(tabprij, dohvatljiva):
  dohvatljiviprij = {}

  for stanje, znak in tabprij.iteritems():
    if stanje[0] in dohvatljiva:
      dohvatljiviprij[stanje] = znak

  return dohvatljiviprij

def markRecursive(pair):
  matchingMatrix[pair] = True

  for relation in relationsMatrix[pair]:
    if not matchingMatrix[relation]:
      markRecursive(relation)

  relationsMatrix[pair] = []

def makePair(p, q):
  return (min(p, q), max(p,q ))

# def debug(states):
#   for i in states:
#     for j in states:
#       print "{:5b} ".format(matchingMatrix[(i, j)]),
#     print ""
#   print "-" * 80

def minimaze(transitions, states, finites):
  # run minimization algorithm
  for p in states:
    for q in states:
        if p != q and (not p in finites and q in finites or p in finites and not q in finites):
          matchingMatrix[(p, q)] = True

  for p in states:
    for q in states:
      if (p in finites and q in finites or not (p in finites) and not (q in finites)):
        # debug(states)
        isMarked = False
  
        for a in znakovi:
          if matchingMatrix[(transitions[(p, a)], transitions[(q, a)])]:
            isMarked = True

        if isMarked:
            markRecursive((p, q))
        else:
          for a in znakovi:
            if transitions[(p, a)] != transitions[(q, a)]:
              relationsMatrix[(transitions[(p, a)], transitions[(q, a)])].append((p, q))

  # join same states (p0, p1) and (p1, p2) should be (p0, p1, p2)
  joinedStates = []
  for p in states:
    for q in states:
      if p != q and not matchingMatrix[(p, q)]:
        found = False

        for item in joinedStates:
          if p in item or q in item:
            item.append(p)
            item.append(q)
            found = True

        if not found:
          joinedStates.append([p, q])

  # map each name to new state
  joinDict = {}
  for joinedStates in [sorted(list(set(item))) for item in joinedStates]:
    for item in joinedStates:
      joinDict[item] = joinedStates[0]

  return joinDict

def replaceElements(equalStates, elements):
  newElements = []

  for element in elements:
    if equalStates.has_key(element):
      newElements.append(equalStates[element])
    else:
      newElements.append(element)

  return sorted(list(set(newElements)))

def replaceElementsDict(equalStates, elements):
  newElements = {}

  for key, value in elements.iteritems():
    newKey = key
    newValue = value

    if equalStates.has_key(value):
      newValue = equalStates[value]

    if equalStates.has_key(key[0]):
      newKey = (equalStates[key[0]], key[1])

    newElements[newKey] = newValue

  return newElements


if __name__ == "__main__":
  stanja = data[0].split(",")
  znakovi = data[1].split(",")
  znakovi.sort()
  zavrsna = data[2].split(",")
  pocetno = data[3]
  tabprij = tablicaprijelaza(data[4:])

  dohvatljiva = nadjidohvatljiva(tabprij, znakovi, pocetno)
  dohvatljivafinalna = []
  for stanje in zavrsna:
        if stanje in dohvatljiva:
            dohvatljivafinalna.append(stanje)
  dohvatljivafinalna.sort()

  dohvtabprij = nadjidohvprij(tabprij, dohvatljiva)

  istovjetna = minimaze(dohvtabprij, dohvatljiva, zavrsna)

  novastanja = replaceElements(istovjetna, dohvatljiva)
  novafinalna = replaceElements(istovjetna, dohvatljivafinalna)
  novopocetno = replaceElements(istovjetna, [pocetno])[0]
  novatabprij = replaceElementsDict(istovjetna, dohvtabprij)  
  
  print ",".join(novastanja)
  print ",".join(znakovi)
  print ",".join(novafinalna)
  print novopocetno
  for stanje in novastanja:
    for znak in znakovi:
      print "{},{}->{}".format(stanje, znak, novatabprij[(stanje, znak)])


  
