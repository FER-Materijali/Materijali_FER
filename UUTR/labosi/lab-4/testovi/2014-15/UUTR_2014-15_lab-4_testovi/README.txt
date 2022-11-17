test0 i test00 su integracijski testovi primjer1 i primjer2
test01 do test20 su sluzbeni ispitni primjerci s ferweba
test21 do test1046 su ispitni primjerci iz ove datoteke http://materijali.fer2.net/File.16458.aspx pomaknuti za 20, tj. 1 odgovara test21, 2 odgovara test22 itd...

Parser.py je parser koji je stavljen na ferwebu zajedno s ispitnim primjercima.
Svi testovi testirani su s tim parserom, kao dokaz da svi primjerci prolaze, rezultati ispitivanja dostupni su u datoteci test_primjerka.txt

UTR_Evaluator_1.1.py je ovaj evaluator http://materijali.fer2.net/File.23862.aspx prilagoden za format datoteka u ovim testovima

Pokretati sa naredbom
>>UTR_Evaluator_1.1.py Parser

Buduci da se u konzoli nece zapamtiti svi rezultati pojedinih testova nego samo zadnjih ~200, pozeljno je preusmjeriti izlaz skripte u datoteku
>>UTR_Evaluator_1.1.py Parser > rezultati_ispitivanja.txt