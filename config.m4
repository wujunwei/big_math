dnl $Id$
dnl config.m4 for extension big_math

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(big_math, for big_math support,
dnl Make sure that the comment is aligned:
dnl [  --with-big_math             Include big_math support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(big_math, whether to enable big_math support,
dnl Make sure that the comment is aligned:
dnl [  --enable-big_math           Enable big_math support])

if test "$PHP_BIG_MATH" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-big_math -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/big_math.h"  # you most likely want to change this
  dnl if test -r $PHP_BIG_MATH/$SEARCH_FOR; then # path given as parameter
  dnl   BIG_MATH_DIR=$PHP_BIG_MATH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for big_math files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       BIG_MATH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$BIG_MATH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the big_math distribution])
  dnl fi

  dnl # --with-big_math -> add include path
  dnl PHP_ADD_INCLUDE($BIG_MATH_DIR/include)

  dnl # --with-big_math -> check for lib and symbol presence
  dnl LIBNAME=big_math # you may want to change this
  dnl LIBSYMBOL=big_math # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $BIG_MATH_DIR/$PHP_LIBDIR, BIG_MATH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_BIG_MATHLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong big_math lib version or lib not found])
  dnl ],[
  dnl   -L$BIG_MATH_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(BIG_MATH_SHARED_LIBADD)

  PHP_NEW_EXTENSION(big_math, big_math.c, $ext_shared)
fi
