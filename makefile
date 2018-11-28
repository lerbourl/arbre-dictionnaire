CC=gcc
RM=rm -f

CFLAGS=-g -Wall -Wextra -I.

EXEC=basique complet interface iterateur iteratif recursif routine
OBJ=dico.o iterateur.o lecteur.o

all: $(EXEC)

# %.out : %.c $(OBJ)
# 	$(CC) $< $(OBJ) -o $@

basique : test_basique.c $(OBJ)
	$(CC) $< $(OBJ) -o $@

complet : test_complet.c $(OBJ)
	$(CC) $< $(OBJ) -o $@

interface : test_interface.c $(OBJ)
	$(CC) $< $(OBJ) -o $@

iterateur: test_iterateur.c $(OBJ)
	$(CC) $< $(OBJ) -o $@

iteratif: test_iteratif.c $(OBJ)
	$(CC) $< $(OBJ) -o $@

recursif: test_recursif.c $(OBJ)
	$(CC) $< $(OBJ) -o $@

routine : test_routine.c $(OBJ)
	$(CC) $< $(OBJ) -o $@


%.o: %.c
	$(CC) $(CFLAGS) $< -c


clean :
	$(RM) *.o *~

mrpropre :
	$(RM) *.o *~ $(EXEC)
