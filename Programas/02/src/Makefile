ALL: compile execute

compile: main.c list.c 
	gcc -o approx_subsetsum main.c list.c  -lm

execute: approx_subsetsum
	./approx_subsetsum

sample1: approx_subsetsum samples/sample1.txt
	./approx_subsetsum < samples/sample1.txt

sample2: approx_subsetsum samples/sample2.txt
	./approx_subsetsum < samples/sample2.txt

sample3: approx_subsetsum samples/sample3.txt
	./approx_subsetsum < samples/sample3.txt

sample4: approx_subsetsum samples/sample4.txt
	./approx_subsetsum < samples/sample4.txt

sample5: approx_subsetsum samples/sample5.txt
	./approx_subsetsum < samples/sample5.txt
clear:
	rm -v approx_subsetsum
	rm -v *.*~
