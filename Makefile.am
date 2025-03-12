#INCLUDES = syspara.h

bin_PROGRAMS = Atrial_AP
#Atrial_AP_CFLAGS = -O2 -Wall -axsse4.2 -mkl -parallel -par-report2 -vec-report2 -pg
Atrial_AP_CFLAGS = -fcommon\
					-fiopenmp\
					-fopenmp-targets=spir64\
					-flto\
					-Wall\
					-O2 -xCORE-AVX2\
					-qopt-zmm-usage=high\
					-qmkl=parallel\
					-finline -ipo -pg\
					-qopt-report-stdout
					-parallel-source-info=2

Atrial_AP_LDADD = -L/opt/intel/oneapi/mkl/lib/intel64 -liomp5 -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core /home/tsumoto/lib/icx2024/xhplot.o
#ORd_LDADD = /home/tsumoto/lib/xhplot.o

Atrial_AP_SOURCES = ./src/crn.c ./src/val_constants.c ./src/mem.c\
	./src/win_out.c ./src/eular.c ./src/runge.c ./src/input_para.c ./src/system.c ./src/currents.c\
	./src/eventloop.c ./src/exptable.c ./src/data_out.c ./src/syspara.h

