#!/bin/sh

#    link xx.o yy.o zz.o
#    produces output to link.o

if [ "" = $1"" ]
then
  exec $0 -help
fi
if [ -help = $1 ]
then
echo "link [a.o ...]
 links smal8 object files named on the command line (with clib)
 into a new loadable file called link.o"
exit 1
fi

echo TITLE smallink $* > link.a
echo .=#11230 >> link.a
while [ $# -gt 0 ]; do
  echo INCLUDE \"$1\" >> link.a
  shift
done
echo INCLUDE \"clib/DIR\" >> link.a
echo C=. >> link.a
echo RUNUSED=C >> link.a
./smal8 -D -L link.a
rm link.a
sort +2 -3 link.d > link.map

