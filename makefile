CC=gcc
RM=rm -f

CFLAGS=-g -Wall -Wextra -std=c99

EXEC=basique complet interface iterateur iteratif recursif routine

#SRC=dico.c iterateur.c lecteur.c
OBJ=dico.o iterateur.o lecteur.o

all: $(EXEC)

# %.out : %.c $(OBJ)
# 	$(CC) $< $(OBJ) -o $@

basique : test_basique.c $(OBJ)
	$(CC) $(CFLAGS) $< $(OBJ) -o $@

complet : test_complet.c $(OBJ)
	$(CC) $(CFLAGS) $< $(OBJ) -o $@

interface : test_interface.c $(OBJ)
	$(CC) $(CFLAGS) $< $(OBJ) -o $@

iterateur: test_iterateur.c $(OBJ)
	$(CC) $(CFLAGS) $< $(OBJ) -o $@

iteratif: test_iteratif.c $(OBJ)
	$(CC) $(CFLAGS) $< $(OBJ) -o $@

recursif: test_recursif.c $(OBJ)
	$(CC) $(CFLAGS) $< $(OBJ) -o $@

routine : test_routine.c $(OBJ)
	$(CC) $(CFLAGS) $< $(OBJ) -o $@


%.o: %.c
	$(CC) $(CFLAGS) $< -c


clean :
	$(RM) *.o *~

mrpropre :
	$(RM) *.o *~ $(EXEC)
