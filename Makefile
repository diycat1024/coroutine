all : main

main : main.c coroutine.c
	gcc -g -Wall -o $@ $^

clean :
	rm main
	
test : test.c coroutine.c
	gcc -g -Wall -o $@ $^