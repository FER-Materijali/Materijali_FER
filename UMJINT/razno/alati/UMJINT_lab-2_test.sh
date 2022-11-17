#!/bin/bash
umro=0
for i in {1..29}
do
echo "Prelazim level:$i"

#timeout nakon 10 sekundi za one layoute na kojima se ceka spas sa Paceartha
val=$(timeout 10s python pacman.py -l lay${i} -p PacardAgent -a fn=logicBasedSearch -g WumpusGhost --frameTime=0)
if [[ $val == *"died"* ]]; then
   echo "Pacard je umro :("
   umro=$(($umro+1))
fi
done

#na koliko levela je prezivio?
ziv=$((i - umro))
echo "Skor: $ziv/$i"
