#
# Makefile du projet

#
# definition de variables
# le compilateur
CC = gcc

# flags
# -g ajoute les informations de debug (gdb par exemple)
# -Wall active tous les warnings (aide à un code plus propre)
CFLAGS = -Wall -g

# librairies
LIBS = -lm

# les sources C
SRCS = *.c

# les objets C
OBJS = $(SRCS:.c=.o)

# l'executable
EXC = bin

#
# build generique
all:	$(EXC)
		@echo executable est compilé avec succès!!

bin: $(OBJS)
		$(CC) -o $@ $^ $(LIBS)

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		$(RM) *.o *~ $(EXC)
