#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 5 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# YACCparser.v
# YACC verbose file generated from YACCparser.y.
# 
# Date: 12/19/08
# Time: 16:39:45
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : cjeline $end

    1  cjeline : deklaracije DP pravila_prevodenja c_procedure

    2  deklaracije :
    3              | c_deklaracije unija poc_produkcija dzzp

    4  c_deklaracije :

    5  $$1 :

    6  c_deklaracije : POZ $$1 PZZ

    7  unija :
    8        | UNION

    9  poc_produkcija :
   10                 | START IDENTIFIKATOR

   11  dzzp : ponavljaj kljucne_rijeci oznaka niz

   12  ponavljaj :
   13            | dzzp

   14  kljucne_rijeci : TOKEN
   15                 | TYPE
   16                 | LEFT
   17                 | RIGHT
   18                 | NONASSOC

   19  oznaka :
   20         | '<' IDENTIFIKATOR '>'

   21  niz : izraz
   22      | niz izraz

   23  izraz : IDENTIFIKATOR

   24  pravila_prevodenja : POC_IDENTIFIKATOR ':' dsp prednost
   25                     | pravila_prevodenja produkcija

   26  produkcija : POC_IDENTIFIKATOR ':' dsp prednost
   27             | '|' dsp prednost

   28  dsp :
   29      | IDENTIFIKATOR dsp
   30      | dsp akcija

   31  $$2 :

   32  akcija : '{' $$2 '}'

   33  prednost :
   34           | PREC IDENTIFIKATOR
   35           | PREC IDENTIFIKATOR akcija
   36           | prednost ';'

   37  c_procedure :
   38              | DP


##############################################################################
# States
##############################################################################

state 0
	$accept : . cjeline $end
	deklaracije : .  (2)
	c_deklaracije : .  (4)

	POZ  shift 1
	DP  reduce 2
	.  reduce 4

	cjeline  goto 2
	deklaracije  goto 3
	c_deklaracije  goto 4


state 1
	c_deklaracije : POZ . $$1 PZZ
	$$1 : .  (5)

	.  reduce 5

	$$1  goto 5


state 2
	$accept : cjeline . $end  (0)

	$end  accept


state 3
	cjeline : deklaracije . DP pravila_prevodenja c_procedure

	DP  shift 6


state 4
	deklaracije : c_deklaracije . unija poc_produkcija dzzp
	unija : .  (7)

	UNION  shift 7
	.  reduce 7

	unija  goto 8


state 5
	c_deklaracije : POZ $$1 . PZZ

	PZZ  shift 9


state 6
	cjeline : deklaracije DP . pravila_prevodenja c_procedure

	POC_IDENTIFIKATOR  shift 10

	pravila_prevodenja  goto 11


state 7
	unija : UNION .  (8)

	.  reduce 8


state 8
	deklaracije : c_deklaracije unija . poc_produkcija dzzp
	poc_produkcija : .  (9)

	START  shift 12
	.  reduce 9

	poc_produkcija  goto 13


state 9
	c_deklaracije : POZ $$1 PZZ .  (6)

	.  reduce 6


state 10
	pravila_prevodenja : POC_IDENTIFIKATOR . ':' dsp prednost

	':'  shift 14


state 11
	cjeline : deklaracije DP pravila_prevodenja . c_procedure
	pravila_prevodenja : pravila_prevodenja . produkcija
	c_procedure : .  (37)

	'|'  shift 15
	POC_IDENTIFIKATOR  shift 16
	DP  shift 17
	.  reduce 37

	c_procedure  goto 18
	produkcija  goto 19


state 12
	poc_produkcija : START . IDENTIFIKATOR

	IDENTIFIKATOR  shift 20


state 13
	deklaracije : c_deklaracije unija poc_produkcija . dzzp
	ponavljaj : .  (12)

	.  reduce 12

	dzzp  goto 21
	ponavljaj  goto 22


state 14
	pravila_prevodenja : POC_IDENTIFIKATOR ':' . dsp prednost
	dsp : .  (28)

	IDENTIFIKATOR  shift 23
	.  reduce 28

	dsp  goto 24


state 15
	produkcija : '|' . dsp prednost
	dsp : .  (28)

	IDENTIFIKATOR  shift 23
	.  reduce 28

	dsp  goto 25


state 16
	produkcija : POC_IDENTIFIKATOR . ':' dsp prednost

	':'  shift 26


state 17
	c_procedure : DP .  (38)

	.  reduce 38


state 18
	cjeline : deklaracije DP pravila_prevodenja c_procedure .  (1)

	.  reduce 1


state 19
	pravila_prevodenja : pravila_prevodenja produkcija .  (25)

	.  reduce 25


state 20
	poc_produkcija : START IDENTIFIKATOR .  (10)

	.  reduce 10


state 21
	deklaracije : c_deklaracije unija poc_produkcija dzzp .  (3)
	ponavljaj : dzzp .  (13)

	DP  reduce 3
	.  reduce 13


state 22
	dzzp : ponavljaj . kljucne_rijeci oznaka niz

	TOKEN  shift 27
	LEFT  shift 28
	RIGHT  shift 29
	NONASSOC  shift 30
	TYPE  shift 31

	kljucne_rijeci  goto 32


state 23
	dsp : IDENTIFIKATOR . dsp
	dsp : .  (28)

	IDENTIFIKATOR  shift 23
	.  reduce 28

	dsp  goto 33


state 24
	pravila_prevodenja : POC_IDENTIFIKATOR ':' dsp . prednost
	dsp : dsp . akcija
	prednost : .  (33)

	'{'  shift 34
	PREC  shift 35
	.  reduce 33

	prednost  goto 36
	akcija  goto 37


state 25
	produkcija : '|' dsp . prednost
	dsp : dsp . akcija
	prednost : .  (33)

	'{'  shift 34
	PREC  shift 35
	.  reduce 33

	prednost  goto 38
	akcija  goto 37


state 26
	produkcija : POC_IDENTIFIKATOR ':' . dsp prednost
	dsp : .  (28)

	IDENTIFIKATOR  shift 23
	.  reduce 28

	dsp  goto 39


state 27
	kljucne_rijeci : TOKEN .  (14)

	.  reduce 14


state 28
	kljucne_rijeci : LEFT .  (16)

	.  reduce 16


state 29
	kljucne_rijeci : RIGHT .  (17)

	.  reduce 17


state 30
	kljucne_rijeci : NONASSOC .  (18)

	.  reduce 18


state 31
	kljucne_rijeci : TYPE .  (15)

	.  reduce 15


state 32
	dzzp : ponavljaj kljucne_rijeci . oznaka niz
	oznaka : .  (19)

	'<'  shift 40
	.  reduce 19

	oznaka  goto 41


state 33
	dsp : IDENTIFIKATOR dsp .  (29)
	dsp : dsp . akcija

	'{'  shift 34
	.  reduce 29

	akcija  goto 37


state 34
	akcija : '{' . $$2 '}'
	$$2 : .  (31)

	.  reduce 31

	$$2  goto 42


state 35
	prednost : PREC . IDENTIFIKATOR
	prednost : PREC . IDENTIFIKATOR akcija

	IDENTIFIKATOR  shift 43


state 36
	pravila_prevodenja : POC_IDENTIFIKATOR ':' dsp prednost .  (24)
	prednost : prednost . ';'

	';'  shift 44
	.  reduce 24


state 37
	dsp : dsp akcija .  (30)

	.  reduce 30


state 38
	produkcija : '|' dsp prednost .  (27)
	prednost : prednost . ';'

	';'  shift 44
	.  reduce 27


state 39
	produkcija : POC_IDENTIFIKATOR ':' dsp . prednost
	dsp : dsp . akcija
	prednost : .  (33)

	'{'  shift 34
	PREC  shift 35
	.  reduce 33

	prednost  goto 45
	akcija  goto 37


state 40
	oznaka : '<' . IDENTIFIKATOR '>'

	IDENTIFIKATOR  shift 46


state 41
	dzzp : ponavljaj kljucne_rijeci oznaka . niz

	IDENTIFIKATOR  shift 47

	niz  goto 48
	izraz  goto 49


state 42
	akcija : '{' $$2 . '}'

	'}'  shift 50


state 43
	prednost : PREC IDENTIFIKATOR .  (34)
	prednost : PREC IDENTIFIKATOR . akcija

	'{'  shift 34
	.  reduce 34

	akcija  goto 51


state 44
	prednost : prednost ';' .  (36)

	.  reduce 36


state 45
	produkcija : POC_IDENTIFIKATOR ':' dsp prednost .  (26)
	prednost : prednost . ';'

	';'  shift 44
	.  reduce 26


state 46
	oznaka : '<' IDENTIFIKATOR . '>'

	'>'  shift 52


state 47
	izraz : IDENTIFIKATOR .  (23)

	.  reduce 23


state 48
	dzzp : ponavljaj kljucne_rijeci oznaka niz .  (11)
	niz : niz . izraz

	IDENTIFIKATOR  shift 47
	.  reduce 11

	izraz  goto 53


state 49
	niz : izraz .  (21)

	.  reduce 21


state 50
	akcija : '{' $$2 '}' .  (32)

	.  reduce 32


state 51
	prednost : PREC IDENTIFIKATOR akcija .  (35)

	.  reduce 35


state 52
	oznaka : '<' IDENTIFIKATOR '>' .  (20)

	.  reduce 20


state 53
	niz : niz izraz .  (22)

	.  reduce 22


##############################################################################
# Summary
##############################################################################

22 token(s), 20 nonterminal(s)
39 grammar rule(s), 58 state(s)


##############################################################################
# End of File
##############################################################################
