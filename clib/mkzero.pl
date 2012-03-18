#!/usr/bin/perl

#
# Read vm.c and emit vm.h.
open(INPUT, "grep -i 'public' vm.asm |") || die "grep vm.asm: $!";
open(STDOUT, ">../vm.h") || die "../vm.h: $!"; 
$loc = 0;
while (<INPUT>) {
  next unless /GLOBAL (\w+)/i;
  print "  outline(\"$1 = $loc+1\");\n";
  $loc = $1;
}

exit 0;
