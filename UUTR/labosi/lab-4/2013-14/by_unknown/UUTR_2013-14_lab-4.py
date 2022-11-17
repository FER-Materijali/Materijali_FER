import sys

ulaz = raw_input()

def neS():
    global ulaz
    sys.stdout.write("S")
    if len(ulaz) == 0: # provjera jel kraj niza
        return False

    if ulaz[:1] == 'a':
        ulaz = ulaz[1:]
        if neA() and neB() is True:
            return True
        else:
            return False
    elif ulaz[:1] == 'b':
        ulaz = ulaz[1:]
        if neB() and neA() is True:
            return True
        else:
            return False
    else:
        return False

def neA():
    global ulaz
    sys.stdout.write("A")
    if len(ulaz) == 0:
        return False

    if ulaz[:1] == 'b':
        ulaz = ulaz[1:]
        if neC() is True:
            return True
        else:
            return False
    elif ulaz[:1] == 'a':
        ulaz = ulaz[1:]
        return True
    else:
        return False

def neB():
    global ulaz
    sys.stdout.write("B")
    if len(ulaz) == 0:
        return True

    if ulaz[:1] == 'c':
        if ulaz[:2] == 'cc':
            ulaz = ulaz[2:]
            if (neS() and (ulaz[:2]=='bc')) is True:
                ulaz = ulaz [2:]
                return True
            else:
                return False
        else:
            return True
    else:
        return True

def neC():
    global ulaz
    sys.stdout.write("C")
       # if len(ulaz) == 0:
          #  return False

    if neA() and neA() is True:
        return True
    else:
        return False





if neS() and not ulaz:
    print
    print "DA"
else :
    print
    print "NE"