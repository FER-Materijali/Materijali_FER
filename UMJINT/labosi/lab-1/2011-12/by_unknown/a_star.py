from operator import itemgetter, attrgetter
from Queue import PriorityQueue
import time
import itertools

def goal(stanje):
    if len(stanje[0])==0:
        return True
    return False

def comp(stanje1, stanje2):
    if (stanje1[3]<stanje2[3]):
        return True
    return False

def myKeyFunction(state):
    label = stanje[3]
    return label

def MAX(a,b):
    if(a>b):
        return a
    else:
        return b
    
def expand(stanje):
    if stanje[2]=='L':
        all_permut = list(itertools.combinations(stanje[0],2))
        for i in range (len(all_permut)):
            new_state=list()
            new_state_left=list()
            new_state_right=list()
            new_state_price = max(all_permut[i][0],all_permut[i][1])+ stanje[3]
            new_state_flash = 'D';
            new_state_right.extend(stanje[1])
            new_state_right.append(all_permut[i][0])
            new_state_right.append(all_permut[i][1])
            new_state_left.extend(stanje[0])
            new_state_left.remove(all_permut[i][0])
            new_state_left.remove(all_permut[i][1])
            new_state.append(new_state_left)
            new_state.append(new_state_right)
            new_state.append(new_state_flash)
            h_n=0
            if len(new_state_left):
                h_n=max(new_state_left)
            f_n=new_state_price + h_n
            hash_str=str(new_state)
            if visited.has_key(hash_str):
                pass
            else:
                visited[hash_str] = new_state_price
                new_state.append(new_state_price)
                open_list.put((f_n,new_state))
                reconstruct[str(new_state)]=str(stanje)
                
                            
    else:

        fastest = min(stanje[1])
        j=stanje[1].index(fastest)
        new_state = list()
        new_state_left = list()
        new_state_right = list()
        new_state_price = stanje[3] + stanje[1][j]
        new_state_flash = 'L'
        new_state_left.extend(stanje[0])
        new_state_left.append(stanje[1][j])
        new_state_right.extend(stanje[1])
        new_state_right.pop(j)
        new_state.append(new_state_left)
        new_state.append(new_state_right)
        new_state.append(new_state_flash)
        h_n=0
        if len(new_state_left):
            f_n=new_state_price + h_n
        hash_str=str(new_state)
        if visited.has_key(hash_str):
            pass
        else:
            visited[hash_str] = new_state_price
            new_state.append(new_state_price)
            open_list.put((f_n,new_state))
            reconstruct[str(new_state)]=str(stanje)

def print_transitions(out1, out2):
    len1 = len(out1)
    len2 = len(out2)
    if out1[0]=='':
        print out2[0],' ',out2[1],' ->'
    elif out2[0]=='':
        print out1, '<-'
    else:
        if len1 > len2:
            for i in range(0,len2):
                out1.remove(out2[i])
            if len(out1) == 2:
                print out1[0],' ',out1[1],' ->'
            else:
                print out1[0],' <-'
            
        else:
            for i in range(0,len1):
                out2.remove(out1[i])
            if len(out2) == 2:
                print out2[0],' ',out2[1],' ->'
            else:
                print out2[0],' <-'
        
    
            
def format_output(str1):
    lista = list()
    str1 = str1.replace('[','|')
    str1 = str1.replace(']','|')
    str1 = str1[1:-1]
    str1 = str1.replace(',','')
    lista = str1.split('|')
    return lista[1].split(' ')

def reconstruct_path(str_node):
    if reconstruct.has_key(str_node):
        new_value=''
        new_value = reconstruct[str_node]
        reconstruct_path(new_value)
        lista=list()
        temp1 = str_node[:]
        temp2 = reconstruct[str_node][:]
        out1=list()
        out2=list()
        out1=format_output(temp1)
        out2=format_output(temp2)
        print_transitions(out1,out2)
        
   
        
open_list = PriorityQueue()
visited = dict()
reconstruct = dict()
initial=list()
str_initial=''

def main():
    stanje = list()
    lijevi = list()
    n=int(raw_input('Unesi broj studenata: '))
    for i in range(0, n):
        broj=int(raw_input())
        lijevi.append(broj)
    desni = list()
    flag = 'L'
    price = 0
    minimum = 0
    parent = list()
    stanje.append(lijevi);
    stanje.append(desni);
    stanje.append(flag)
    visited[str(stanje)] = price;
    stanje.append(price)
    initial = stanje
    str_initial = str(initial)
    open_list.put((stanje[3],stanje))
    start_time = time.time()
    current = list()
    while not open_list.empty():
        
        current = open_list.get()
        if (goal(current[1])):
            minimum = current[1][3]
            break
        visited[str(current[1][0:(len(current[1])-1)])]=current[1][3]
        expand(current[1])   
    print minimum
    print "broj stanja: ", len(visited)
    reconstruct_path(str(current[1]))

main()
