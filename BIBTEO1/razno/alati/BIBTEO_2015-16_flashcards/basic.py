import sys, os
from random import shuffle

f = open(sys.argv[1], 'r')

state = 'none'
question = []
answer = []
Q = []

for l in f:
  line = l.strip()
  if line == '':
    if state == 'question':
      state = 'answer'
    elif state != 'none':
      Q.append(('\n'.join(question), '\n'.join(answer)))
      state = 'none'
  elif state == 'answer':
    answer.append(line)
  elif state == 'question':
    question.append(line)
  elif line[0].isdigit():
    state = 'question'
    question = [line]
    answer = []

f.close()

print Q

while True:
  shuffle(Q)
  os.system('clear')
  print "############Pocetak pitanja#################"
  raw_input()
  for q in Q:
    os.system('clear')
    print q[0]
    raw_input()
    print q[1]
    raw_input()
