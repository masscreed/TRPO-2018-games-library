C = gcc
flag = -c -Wall -Werror -std=c99

all: ./bin/games ./bin/test

./bin/games: ./build/src/main.o ./build/src/matches.o ./build/src/bulls.o
	$(C) ./build/src/main.o  ./build/src/matches.o ./build/src/bulls.o -o ./bin/games

./build/src/main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/src/main.o

./build/src/matches.o: ./src/matches.c ./src/matches.h
	$(C) $(flag) -I thirdparty ./src/matches.c -o ./build/src/matches.o

./build/src/bulls.o: ./src/bulls.c ./src/bulls.h
	$(C) $(flag) -I thirdparty ./src/bulls.c -o ./build/src/bulls.o

./bin/test: build/test/games_test.o build/test/main.o build/src/matches.o build/src/bulls.o
	$(C) ./build/test/main.o ./build/test/games_test.o ./build/src/matches.o ./build/src/bulls.o -o ./bin/test

./build/test/main.o: ./test/main.c
	$(C) -Ithirdparty -Isrc -c ./test/main.c -o ./build/test/main.o

./build/test/games_test.o: ./test/games_test.c
	$(C) -Ithirdparty -Isrc -c ./test/games_test.c -o ./build/test/games_test.o

.PHONY: clean
clean:
	rm -rf ./build/*.o

.PHONY: test
test:
		./bin/test

