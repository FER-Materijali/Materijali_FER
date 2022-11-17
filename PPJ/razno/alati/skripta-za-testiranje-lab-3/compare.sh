touch razlike.txt
echo "RAZLIKE:" > razlike.txt
for f in input/*.in
do
    name=${f:6:32}
    myfile="tvoj_output/"$name".out"
    hisfile="ocekivani_output/"$name".out" 
    echo $f >> razlike.txt
    echo "===========================================" >> razlike.txt
    diff $myfile $hisfile >> razlike.txt
done
echo "Usporedba gotova: pogledaj razlike.txt."
