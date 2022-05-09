
#
# A program neve (ezt allitjuk elo)
PROG = main


PROG_O = $(PROG).o mvm.o string5.o date.o base.o  ugyfel.o szerzodes.o

PROG_H = mvm.h string5.h date.h base.h  ugyfel.h szerzodes.h set.hpp #

PROG_L =              # program libjei
MTRACE_O = memtrace.o # memtrace object fajl
MTRACE_H = memtrace.h # memtrace header fajlja

CXX = g++ # a C fordito neve

#fordítasi opciok
CXXFLAGS = -pedantic -Wall -DMEMTRACE
CXXFLAGS += -g # es legyeb debug info is
LDFLAGS = -g # debug a linkelesnel is kell

# osszes object, osszes header osszes lib egyutt
OBJS = $(PROG_O) $(MTRACE_O)
HEADS = $(PROG_H) $(MTRACE_H)
LIBS = $(PROG_L) $(MEMCHK_L)

# Alapertelmezett cel 
.PHONY: all
all: $(PROG)

# Eloallitjuk az objektekbol a PROG-ot
$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LIBS)

# Feltetelezzuk, hogy az osszes obj fugg az osszes headertol, ami nem feltetlenul igaz
$(OBJS): $(HEADS)

# Futtatas
.PHONY: test
test: $(PROG)
	./$(PROG)

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)

