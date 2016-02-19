GBDKN=./gbdk-n
CC=$(GBDKN)/bin/gbdk-n-compile.sh --std-c99
CL=$(GBDKN)/bin/gbdk-n-link.sh
CROM=$(GBDKN)/bin/gbdk-n-make-rom.sh

sweeper.gb: obj/main.rel obj/board.rel 
	$(CL) obj/main.rel obj/board.rel -o obj/a.ihx
	$(CROM) obj/a.ihx sweeper.gb

obj/main.rel: gbdk-n
	mkdir -p obj
	$(CC) -I "../../game_logic" main.c -o obj/main.rel

obj/board.rel: gbdk-n 
	mkdir -p obj
	$(CC) ../../game_logic/board.c -o obj/board.rel

gbdk-n:
	git clone https://github.com/rotmoset/gbdk-n
	$(MAKE) -C gbdk-n

.PHONY: clean
clean:
	rm -f obj/*
	rm -f sweeper.gb
	rm -rf gbdk-n

