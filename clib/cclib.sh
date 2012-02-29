for i in *.c; do
  ../smallcc $i -m -a -p || touch $i.err
done
