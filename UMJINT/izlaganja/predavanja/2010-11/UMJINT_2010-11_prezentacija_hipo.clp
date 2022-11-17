(defrule hipotenuza (katete ?a ?b)
	=>
	(printout t "?a ?b => "
		
		(sqrt 
			(+
				(** ?a 2)
				(** ?b 2)
				)
			)
		
		crlf
	)
)
