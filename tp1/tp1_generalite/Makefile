# le(s) programme(s) à générer
cible    := graphe_oriente
# options de compilation
CFLAGS = -g -Wall
# fichiers dans ./include
inc_h    := $(wildcard include/*.h)
inc_c    := $(wildcard include/*.c)
# fichiers objets à générer
inc_obj  := $(inc_c:.c=.o)
# fichiers à effacer lors d'un make clean
toclean := $(cible) $(inc_obj)

.PHONY: all
all: $(cible)

# les fichiers objets dépendent de tous les .h
$(inc_obj): $(inc_h)

# la cible dépend de tous les fichiers objets
$(cible): $(inc_obj) $(inc_objf)

.PHONY: clean
clean:
	rm -f $(toclean)

