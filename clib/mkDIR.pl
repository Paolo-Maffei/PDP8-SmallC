#!/usr/bin/perl

#
# Read in "public" declarations to get a sense of what
# is where in the library.
open(INPUT, "grep -i 'GLOBAL' *.ASM |")
  || die "grep pipe: $!";
while (<INPUT>) {
  if (/(.*).ASM:\s*GLOBAL\s*(\w+)/i) {
    $module = $1;
    $name = $2;
    warn "$module:$name hides $public{$name}:$name\n" if defined $public{$name};
    $public{$name} = $module;
    $modules{$module} = 1;
  }
}

#
# Emit a macro to "INCLUDE" a library module
print <<Eof;
/
/ Resolve all the symbols we can.
OCTAL
R=.
MACRO LIB file, name
  IF (FWD(R`name))
    INCLUDE file
    RESOLVED = 1
  ENDIF
ENDM
Eof
#
# Emit a macro which invokes the LIB macro for each symbol
# that may be resolved by the library.  Then invoke it.
print <<Eof;
MACRO RESOLVER
  RESOLVED = 0
Eof
foreach $name (sort keys %public) {
  print "  LIB \"$public{$name}.o\",$name\n";
}
print <<Eof;
  IF RESOLVED > 0
    RESOLVER
  ENDIF
ENDM
RESOLVER
Eof

exit 0
