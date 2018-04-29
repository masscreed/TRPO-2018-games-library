C = gcc
flag = -c -Wall -Werror -std=c99

./bin/matches: ./build/main.o ./build/matches.o 
	$(C) ./build/main.o  ./build/matches.o -o ./bin/matches

./build/main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/main.o

./build/matches.o: ./src/matches.c
	$(C) $(flag) ./src/matches.c -o ./build/matches.o

.PHONY: clean
clean:
	rm -rf ./build/*.o
