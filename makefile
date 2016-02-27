GBDKN=./gbdk-n
CC=$(GBDKN)/bin/gbdk-n-compile.sh --std-c99 -I "libminesweeper/include"
CL=$(GBDKN)/bin/gbdk-n-link.sh
CROM=$(GBDKN)/bin/gbdk-n-make-rom.sh

bin/sweeper.gb: obj/main.rel obj/libminesweeper.rel obj/start.rel obj/game.rel obj/about.rel obj/graphics.rel obj/utils.rel
	$(CL) obj/main.rel obj/start.rel obj/game.rel obj/libminesweeper.rel obj/about.rel obj/graphics.rel obj/utils.rel -o obj/a.ihx
	mkdir -p bin
	$(CROM) obj/a.ihx bin/sweeper.gb

obj/utils.rel: utils.c
	mkdir -p obj
	$(CC) utils.c -o obj/utils.rel

obj/main.rel: main.c gbdk-n
	mkdir -p obj
	$(CC) main.c -o obj/main.rel

obj/start.rel: start.c gbdk-n
	mkdir -p obj
	$(CC) start.c -o obj/start.rel

obj/about.rel: about.c gbdk-n
	mkdir -p obj
	$(CC) about.c -o obj/about.rel

obj/game.rel: game.c gbdk-n
	mkdir -p obj
	$(CC) game.c -o obj/game.rel

obj/graphics.rel: graphics.c gbdk-n
	mkdir -p obj
	$(CC) graphics.c -o obj/graphics.rel

obj/libminesweeper.rel: libminesweeper/lib/minesweeper.c gbdk-n 
	mkdir -p obj
	$(CC) libminesweeper/lib/minesweeper.c -o obj/libminesweeper.rel


.PHONY: gbdk-n
gbdk-n: gbdk-n/lib/gb.lib

gbdk-n/lib/gb.lib: 
	$(MAKE) -C gbdk-n

.PHONY: clean
clean:
	rm -rf obj
	rm -rf bin

