# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# define targets
TARGETS=ninel vectsecv codeinvim nomogram

build: $(TARGETS)

ninel: ninel.c
	$(CC) $(CFLAGS) ninel.c -o ninel

vectsecv: vectsecv.c
	$(CC) $(CFLAGS) vectsecv.c -o vectsecv

codeinvim: codeinvim.c
	$(CC) $(CFLAGS) codeinvim.c -o codeinvim

nomogram: nomogram.c
	$(CC) $(CFLAGS) nomogram.c -o nomogram

pack:
	zip -FSr 313CA_MitranAndreiGabriel_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean