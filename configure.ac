#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

## Take all the options with the exception of --enable-install-req

AC_PREREQ(2.59)
AC_INIT(OpenFPM_numerics, 1.0.0, BUG-REPORT-ADDRESS)
AC_CANONICAL_SYSTEM
AC_CONFIG_SRCDIR([src/main.cpp])

AM_INIT_AUTOMAKE
AC_CONFIG_HEADER([src/config/config.h])
m4_ifdef([ACX_PTHREAD],,[m4_include([m4/acx_pthread.m4])])
m4_ifdef([ACX_MPI],,[m4_include([m4/acx_mpi.m4])])
m4_ifdef([AX_OPENMP],,[m4_include([m4/ax_openmp.m4])])
m4_ifdef([AX_CUDA],,[m4_include([m4/ax_cuda.m4])])
m4_ifdef([IMMDX_LIB_METIS],,[m4_include([m4/immdx_lib_metis.m4])])
m4_ifdef([IMMDX_LIB_PARMETIS],,[m4_include([m4/immdx_lib_parmetis.m4])])
m4_ifdef([AX_BOOST_BASE],,[m4_include([m4/ax_boost_base.m4])])
m4_ifdef([AX_BOOST_IOSTREAMS],,[m4_include([m4/ax_boost_iostreams.m4])])
m4_ifdef([AX_BOOST_PROGRAM_OPTIONS],,[m4_include([m4/ax_boost_program_options.m4])])
m4_ifdef([AX_BOOST_UNIT_TEST_FRAMEWORK],,[m4_include([m4/ax_boost_unit_test_framework.m4])])
m4_ifdef([AX_BLAS],,[m4_include([m4/ax_blas.m4])])
m4_ifdef([AX_LAPACK],,[m4_include([m4/ax_lapack.m4])])
m4_ifdef([AX_SUITESPARSE],,[m4_include([m4/ax_suitesparse.m4])])
m4_ifdef([AX_EIGEN],,[m4_include([m4/ax_eigen.m4])])
m4_ifdef([AX_LIB_HDF5],,[m4_include([m4/ax_lib_hdf5.m4])])
m4_ifdef([AX_LIB_PETSC],,[m4/ax_petsc_lib.m4])
m4_ifdef([AX_LIB_HILBERT],,[m4/ax_lib_hilbert.m4])

case $host_os in
   *darwin*|*macosx*)
        CXXFLAGS+=" --std=c++11 "
        AC_DEFINE([HAVE_OSX],[],[We have OSX])
        ;;
   *cygwin*)
        # Do something specific for cygwin
        CXXFLAGS+=" --std=gnu++11 "
        ;;
    *)
        #Default Case
        CXXFLAGS+=" --std=c++11 "
        ;;
esac

NVCCFLAGS=" "
INCLUDES_PATH=" "

# set default prefix
if test "$prefix" = "NONE"; then
   prefix="/usr/local"
fi

# Add openfpm_numerics to prefix forlder (if prefix end if openfpm_pdata remove that path)
if [ echo "$prefix" | grep -qE "/openfpm_pdata$" ]; then
  prefix=$(echo "$prefix" | sed 's/\(.*\)\/openfpm_pdata$/\1/g')
fi

prefix="$prefix/openfpm_numerics"
echo "Installation dir is: $prefix"

# Checks for programs.
AC_PROG_CXX

# Checks g++ flags

AC_CANONICAL_HOST

# Check that the compiler support mpi

AC_LANG_PUSH([C++])
AC_CHECK_HEADER(mpi.h,[],[echo "mpi.h not found"
                          exit 200])
AC_LANG_POP([C++])

# Check target architetture

#AX_GCC_ARCHFLAG([], [CXXFLAGS="$CXXFLAGS $ax_cv_gcc_archflag"], [])

###### Check for debug compilation

AC_MSG_CHECKING(whether to build with debug information)
debuger=no
AC_ARG_ENABLE(debug,
	AC_HELP_STRING(
	    [--enable-debug],
	    [enable debug data generation (def=no)]
	),
  	debuger="$enableval"
)

AC_MSG_RESULT($debuger)
if test x"$debuger" = x"yes"; then
	AC_DEFINE([DEBUG_MODE],[],[Debug])
	AC_DEFINE([DEBUG],[],[Debug])
	CXXFLAGS="$CXXFLAGS -g3  -Wall -O0 "
	NVCCFLAGS+="$NVCCFLAGS -g -O0 "
else
	CXXFLAGS="$CXXFLAGS -Wall -O3 -g3 -funroll-loops "
	NVCCFLAGS+="$NVCCFLAGS -O3 "
fi

#########

## Check for Metis
####### include openfpm_devices include path

IMMDX_LIB_METIS([],[echo "Cannot detect metis, use the --with-metis option if it is not installed in the default location"
                    exit 201])

## Check for parMetis

IMMDX_LIB_PARMETIS([],[echo "Cannot detect parmetis, use the --with-parmetis option if it is not installed in the default location"
                    exit 203])

## Check for HDF5

AX_LIB_HDF5([parallel])
        
if test x"$with_hdf5" = x"no"; then
    echo "Cannot detect hdf5, use the --with-hdf5 option if it is not installed in the default location"
    exit 207
fi

#########

###### Check for test coverage

AC_MSG_CHECKING(whether to build with test coverage)
test_cov=no
AC_ARG_ENABLE(test-coverage,
        AC_HELP_STRING(
            [--enable-test-coverage],
            [enable test coverage]
        ),
        test_cov="$enableval"
)



AC_MSG_RESULT($test_cov)
if test x"$test_cov" = x"yes"; then
        AC_DEFINE([TEST_COVERAGE_MODE],[],[Test coverage mode])
        CXXFLAGS="$CXXFLAGS  -fprofile-arcs -ftest-coverage "
fi


## Check for quadmath

AC_LANG_PUSH([C++])

have_quad_lib=no
have_quad_head=no
AC_CHECK_LIB(quadmath, sinq, [have_quad_lib=yes], [])
AC_CHECK_HEADER(quadmath.h,[have_quad_head=yes],[])

if test x"have_quad_math" == x"yes"; then
    AC_DEFINE(HAVE_LIBQUADMATH,[],[Have quad math lib])
    LIBQUADMATH=" -lquadmath "
fi


AC_LANG_POP([C++])

###### RT runtime lib

AC_CHECK_LIB(rt, clock_gettime, [AC_DEFINE([HAVE_CLOCK_GETTIME],[],[Have clock time])
                                 OPT_LIBS="$OPT_LIBS -lrt"
                                ])

##########

## Check for LIBHILBERT

AX_LIB_HILBERT([],[echo "Cannot detect libhilbert, use the --with-libhilbert option if it is not installed in the default location"
                    exit 210])

####### include OpenFPM_numerics include path"

INCLUDES_PATH+=" -I/usr/local/include -I. -I../../openfpm_devices/src -I../../openfpm_data/src -I../../openfpm_io/src -I../../openfpm_vcluster/src -I../../src"

####### Detect OpenMP

AX_OPENMP([CFLAGS="$OPENMP_CFLAGS"
           LDFLAGS="$OPENMP_LDFLAGS"],[])

AC_SUBST(OPENMP_CFLAGS)
AC_SUBST(OPENMP_LDFLAGS)

###### Check for se-class1

AC_MSG_CHECKING(whether to build with security enhancement class1)
se_class1=no
AC_ARG_ENABLE(se-class1,
        AC_HELP_STRING(
            [--enable-se-class1],
            [enable security enhancement class1]
        ),
        se_class1="$enableval"
)



AC_MSG_RESULT($se_class1)
if test x"$se_class1" = x"yes"; then
        AC_DEFINE([SE_CLASS1],[],[Security enhancement class 1])
fi


###### Check for se-class 2

AC_MSG_CHECKING(whether to build with security enhancement class 2)
se_class2=no
AC_ARG_ENABLE(se-class2,
        AC_HELP_STRING(
            [--enable-se-class2],
            [enable security enhancement class 2]
        ),
        se_class2="$enableval"
)


AC_MSG_RESULT($se_class2)
if test x"$se_class2" = x"yes"; then
        AC_DEFINE([SE_CLASS2],[],[Security enhancement class 2])
fi

###### Check for se-class 3

AC_MSG_CHECKING(whether to build with security enhancement class 3)
se_class3=no
AC_ARG_ENABLE(se-class3,
        AC_HELP_STRING(
            [--enable-se-class3],
            [enable security enhancement class 3]
        ),
        se_class3="$enableval"
)



AC_MSG_RESULT($se_class3)
if test x"$se_class3" = x"yes"; then
        AC_DEFINE([SE_CLASS3],[],[Security enhancement class 3])
fi

action_on_e=continue
AC_ARG_WITH([action-on-error],
             AS_HELP_STRING([--with-action-on-error=stop,throw,continue],
             [specify the action to do in case of error]),
             [action_on_e="$withval"],
             [action_on_e=continue])

if test x"$action_on_e" = x"stop"; then
           AC_DEFINE([STOP_ON_ERROR],[],[If an error occur stop the program])
fi
if test x"$action_on_e" = x"throw"; then
           AC_DEFINE([THROW_ON_ERROR],[],[when an error accur continue but avoid unsafe operation])
fi

##### CHECK FOR BOOST ##############

AX_BOOST_BASE([1.52],[],[echo "boost not found"
                    exit 202])
AX_BOOST_UNIT_TEST_FRAMEWORK
AX_BOOST_PROGRAM_OPTIONS
AX_BOOST_IOSTREAMS

if test x"$ax_cv_boost_unit_test_framework" = x"no"; then
  echo "Notify boost not usable"
  exit 202
fi

if test x"$ax_cv_boost_iostreams" = x"no"; then
  echo "Notify boost not usable"
  exit 202
fi

if test x"$ax_cv_boost_programs_options" = x"no"; then
  echo "Notify boost not usable"
  exit 202
fi

### Unfortunately a lot of linux distros install a pretty old MPI in the system wide folder,
### override such MPI with the installed one is extremely difficult and tricky, because we want
### to include "some" system library but exclude mpi. One possibility is to give specifically
### the wanted libmpi.so directly to the linker. But this is not possible because this lib is
### given by mpic++ in the form -L/path/to/mpi -lmpi, the other is completely eliminate every
### -L with a system default library
###

# eliminate any /usr/lib and and /usr/include from $BOOST_LIB and $BOOST_INCLUDE

BOOST_LDFLAGS=$(echo "$BOOST_LDFLAGS" | sed -e 's/ -L\/usr\/lib64[ \b]//g' | sed -e 's/ -L\/usr\/lib[ \b]//g')
BOOST_CPPFLAGS=$(echo "$BOOST_CPPFLAGS" | sed -e 's/-I\/usr\/include[ \b]//g')

AC_SUBST(BOOST_LDFLAGS)
AC_SUBST(BOOST_CPPFLAGS)

###### Checking for OpenBLAS

AX_BLAS([],[])

AX_LAPACK([],[])

###### Checking for SUITESPARSE

AX_SUITESPARSE([],[])

##########

## Check for PETSC

AX_LIB_PETSC()

###### Checking for EIGEN

AX_EIGEN([],[])

###### Checking for libquadmath and libifcore

AC_CHECK_LIB(ifcore, for_cpystr, [ LIBIFCORE=-lifcore  ], [ LIBIFCORE= ])
AC_CHECK_LIB(quadmath, sinq, [ LIBQUADMATH=-lquadmath  ], [ LIBQUADMATH= ])
AC_SUBST(LIBQUADMATH)
AC_SUBST(LIBIFCORE)

###### Checking for compiler flags -fext-numeric-literals

AC_LANG_PUSH([C++])

my_save_cflags="$CXXFLAGS"
CXXFLAGS=-fext-numeric-literals
AC_MSG_CHECKING([whether CXX supports -fext-numeric-literals])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([])],
    [AC_MSG_RESULT([yes])]
    [AM_CXXFLAGS=-fext-numeric-literals],
    [AC_MSG_RESULT([no])]
)
AC_LANG_POP([C++])
CXXFLAGS="$my_save_cflags"
AC_SUBST([AM_CXXFLAGS])



####### Checking for GPU support

AX_CUDA

## detect for NVCC

if test x"$NVCC_EXIST" = x"yes"; then
  AC_MSG_CHECKING(whether to build with GPU support)
  gpu_support=yes
  AC_ARG_ENABLE(gpu,
	AC_HELP_STRING(
	    [--enable-gpu],
	    [enable gpu support]
	),
  	gpu_support="$enableval"
  )

  AC_MSG_RESULT($gpu_support)
  if test x"$gpu_support" = x"yes"; then
	AC_DEFINE([GPU],[],[GPU support])
  else
	CUDA_LIBS=""
	CUDA_CFLAGS=""
  fi
else
  gpu_support=no
fi

if test x$gpu_support = x"no"; then
     CUDA_LIBS=""
     CUDA_CFLAGS=""
fi

# Set this conditional if cuda is wanted

AM_CONDITIONAL(BUILDCUDA, test ! x$NVCC = x"no")

###########################

# Define that there is MPI

AC_DEFINE([HAVE_MPI],[],[MPI Enabled])

AC_SUBST(NVCCFLAGS)
AC_SUBST(INCLUDES_PATH)
AC_SUBST(LIBQUADMATH)
AC_SUBST(OPT_LIBS)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile ])
AC_OUTPUT
echo ""
echo   "***********************************"
echo   "*                                 *"
if [ test x"$profiler" = x"yes" ]; then
  echo "*    profiler: yes                *"
else
  echo "*    profiler: no                 *"
fi
if [ test x"$memcheck" = x"yes" ]; then
  echo "*    memcheck: yes                *"
else
  echo "*    memcheck: no                 *"
fi
if [ test x"$debuger" = x"yes" ]; then
  echo "*    debug: yes                   *"
else
  echo "*    debug: no                    *"
fi
if [ test x"$se_class1" = x"yes" ]; then
  echo "*    se-class1: yes               *"
else
  echo "*    se-class1: no                *"
fi
if [ test x"$se_class2" = x"yes" ]; then
  echo "*    se-class2: yes               *"
else
  echo "*    se-class2: no                *"
fi
if [ test x"$se_class3" = x"yes" ]; then
  echo "*    se-class3: yes               *"
else
  echo "*    se-class3: no                *"
fi
if [ test x"$gpu_support" = x"no" ]; then
  echo "*    gpu: no                      *"
else
  echo "*    gpu: yes                     *"
fi
echo   "*                                 *"
echo   "***********************************"

