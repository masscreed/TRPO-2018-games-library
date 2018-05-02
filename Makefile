C = gcc
flag = -c -Wall -Werror -std=c99

./bin/games: ./build/main.o ./build/matches.o ./build/bulls.o
	$(C) ./build/main.o  ./build/matches.o ./build/bulls.o -o ./bin/games

./build/main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/main.o

./build/matches.o: ./src/matches.c ./src/matches.h
	$(C) $(flag) -I thirdparty ./src/matches.c -o ./build/matches.o

./build/bulls.o: ./src/bulls.c ./src/bulls.h
	$(C) $(flag) -I thirdparty ./src/bulls.c -o ./build/bulls.o


.PHONY: clean
clean:
	rm -rf ./build/*.o

