# FLASH makefile definitions for Ubuntu 24.04 x86_64 cloud hosts.
# Uses Ubuntu OpenMPI wrappers because Ubuntu's HYPRE2 package is OpenMPI-built.

MPI_PATH   = /usr
HDF4_PATH  =
HDF5_PATH  = /usr
HDF5_INC   = /usr/include/hdf5/openmpi
HDF5_LIB   = /usr/lib/x86_64-linux-gnu/hdf5/openmpi
HYPRE_PATH = /usr
HYPRE_INC  = /usr/include/hypre
HYPRE_LIB  = /usr/lib/x86_64-linux-gnu
LAPACK_PATH = /usr
ZLIB_PATH  = /usr
PAPI_PATH  =
PAPI_FLAGS =
NCMPI_PATH =
MPE_PATH   =

FCOMP   = mpif90.openmpi
CCOMP   = mpicc.openmpi
CPPCOMP = mpicxx.openmpi
LINK    = mpif90.openmpi

PP = -D
OPENMP = -fopenmp

FFLAGS_OPT = -ggdb -c -O2 -fallow-argument-mismatch -fallow-invalid-boz \
  -fdefault-real-8 -fdefault-double-8 -Wuninitialized

FFLAGS_DEBUG = -ggdb -c -O0 -fallow-argument-mismatch -fallow-invalid-boz \
  -fdefault-real-8 -fdefault-double-8 -pedantic -Wall -Waliasing \
  -Wsurprising -Wconversion -Wunderflow -ffpe-trap=invalid,zero,overflow \
  -fbounds-check -fimplicit-none -fstack-protector-all

FFLAGS_TEST = -ggdb -c -O0 -fallow-argument-mismatch -fallow-invalid-boz \
  -fdefault-real-8 -fdefault-double-8

FFLAGS_HYPRE = -I${HYPRE_INC}
F90FLAGS =

CFLAGS_OPT = -ggdb -c -O2 -Wuninitialized -D_FORTIFY_SOURCE=2
CFLAGS_DEBUG = -ggdb -c -O0 -Wno-div-by-zero -Wundef \
  -Wconversion -Wstrict-prototypes -Wunreachable-code \
  -pedantic -Wall -Winit-self -ftree-vrp -Wfloat-equal \
  -Wunsafe-loop-optimizations -Wpadded -fstack-protector-all
CFLAGS_TEST = -ggdb -O0 -c

CFLAGS_HYPRE = -I${HYPRE_INC}
CFLAGS_HDF5 = -I${HDF5_INC} -DH5_USE_16_API
CFLAGS_NCMPI =

LFLAGS_OPT   = -ggdb -o
LFLAGS_DEBUG = -ggdb -O0 -o
LFLAGS_TEST  = -ggdb -O0 -o

LIB_OPT   =
LIB_DEBUG =
LIB_TEST  =

LIB_HDF4  =
LIB_HDF5  = -L${HDF5_LIB} -lhdf5hl_fortran -lhdf5_hl -lhdf5_fortran -lhdf5 -lcrypto -lcurl -lsz -lz -ldl -lm
LIB_PAPI  =
LIB_MATH  =
LIB_MPI   =
LIB_NCMPI =
LIB_MPE   =
LIB_HYPRE = -L${HYPRE_LIB} -lHYPRE
LIB_LAPACK = -L/usr/lib/x86_64-linux-gnu -llapack -lblas

MACHOBJ =

MV = mv -f
AR = ar -r
RM = rm -f
CD = cd
RL = ranlib
ECHO = echo
