compile_alcance: alcance.c grafica.c
	gcc -o alcance alcance.c grafica.c

problema_alcance: compile_alcance
	./alcance

compile_sat: 3sat.c FOL.c
	gcc -o sat 3sat.c FOL.c

problema_3sat: compile_sat
	./sat
clear:
	rm alcance
	rm sat
