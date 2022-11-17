(defrule trazi1 (ime ~Mirko) => 
	(printout t "Netko tko nije Mirko." crlf))
(defrule trazi2 (ime Mirko|Slavko) => 
	(printout t "Mirko ili Slavko." crlf))
(defrule trazi3 (ime ~Mirko&~Slavko) => 
	(printout t "Ni Mirko ni Slavko." crlf))
