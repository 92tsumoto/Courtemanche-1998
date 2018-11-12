#INCLUDES = syspara.h

bin_PROGRAMS = CRN98 
CRN98_CFLAGS = -O2 -Wall -axsse4.2 -mkl -parallel -par-report2 -vec-report2 -pg

CRN98_INCLUDE = -I./include
CRN98_LDADD = -L/opt/intel/mkl/lib/intel64 -liomp5 -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core ./lib/xhplot.o

CRN98_SOURCES = ./src/crn.c ./src/val_constants.c ./src/mem.c\
	./src/win_out.c ./src/eular.c ./src/input_para.c ./src/system.c ./src/currents.c\
	./src/eventloop.c ./src/exptable.c ./src/data_out.c ./src/syspara.h

