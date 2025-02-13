#Moyartu Manley

CC=gcc -std=c11
run: scramble test.c binary_convert.c

scramble: scramble.c
	${CC} -o scramble scramble.c test.c binary_convert.c

clean: 
	rm scramble