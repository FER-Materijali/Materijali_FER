-module(ispit).

-export([go/3,master/3,exclude/0,divide/0]).

go(A, B, X) ->
	
	Pid_master = spawn(ispit, master, [A,B,X]),
	
	register(master, Pid_master).
	
master(A, B, X) ->
	Pid_exclude = spawn(ispit,exclude, []),
	Pid_divide = spawn(ispit,divide, []),
	
	register(exclude, Pid_exclude),
	register(divide, Pid_divide),
	
	exclude!{A, B, X},
	
	receive
		{C,D} ->
			io:format("Lista C: ~w~nLista D: ~w~n", [C, D])
	end.
	
exclude() ->
	receive 
		{A, B, X} ->
			io:format("Lista A: ~w~nLista B: ~w~n", [A, B]),
			
			A1 = [Y || Y <- A, Y =< X],
			B1 = [Y || Y <- B, Y >= X],
			
			divide!{A1,B1}
	end.
	
divide() ->
	receive
		{A1, B1} ->
			io:format("Lista A1: ~w~nLista B1: ~w~n", [A1, B1]),
			
			C1 = [Y || Y <- A1, Y rem 2 == 0],
			C2 = [Y || Y <- B1, Y rem 2 == 0],
			C  = lists:append(C1,C2),
			
			D1 = [Y || Y <- A1, Y rem 2 == 1],
			D2 = [Y || Y <- B1, Y rem 2 == 1],
			D = lists:append(D1, D2),
			
			master!{C,D}
	end.