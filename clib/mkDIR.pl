#!/usr/bin/perl

#
# Read in "public" declarations to get a sense of what
# is where in the library.
open(INPUT, "grep -i 'INT' *.ASM |")
  || die "grep pipe: $!";
while (<INPUT>) {
  if (/(.*):\s*INT\s*(\w+)/i) {
    $module = $1;
    $name = $2;
    warn "$module:$name hides $public{$name}:$name\n" if defined $public{$name};
    $public{$name} = $module;
    $modules{$module} = 1;
  }
}

#
# Emit a macro to "USE" a library module
print <<Eof;
;
; Resolve all the symbols we can.
MACRO LIB file, name
  IF (FWD(R'name))
    R'OLD = .   ; Save current relocation context.
    . = R'file  ; Set up relocation for <file>.
    USE file
    . = R'OLD   ; Restore previous relocation context.
    RESOLVED = 1
  ENDIF
ENDMAC
Eof
#
# Emit a macro which invokes the LIB macro for each symbol
# that may be resolved by the library.  Then invoke it.
print <<Eof;
MACRO RESOLVER
  RESOLVED = 0
Eof
foreach $name (sort keys %public) {
  print "  LIB \"$public{$name}\",$name\n";
}
print <<Eof;
  IF RESOLVED
    RESOLVER
  ENDIF
ENDMAC
RESOLVER
Eof
#
# At this point, the symbols are resolved, but there are a
# pile of relocation contexts active, one per file possibly 
# included.
print <<Eof;
;
; Build up the initial map of free memory
; Pages are numbered 1..32, not 0..31 here.
MACRO SETROOM page
  IF . > page * #200
    ROOM'page = 0
  ELSE
    ROOM'page = page * 200 - .
    IF ROOM'page > #200
      ROOM'page = #200
    ENDIF
  ENDIF
ENDMAC
; SETROOM  1
; SETROOM  2
; SETROOM  3
; SETROOM  4
SETROOM  5
SETROOM  6
SETROOM  7
SETROOM  8
SETROOM  9
SETROOM 10
SETROOM 11
SETROOM 12
SETROOM 13
SETROOM 14
SETROOM 15
SETROOM 16
SETROOM 17
SETROOM 18
SETROOM 19
SETROOM 20
SETROOM 21
SETROOM 22
SETROOM 23
SETROOM 24
SETROOM 25
SETROOM 26
SETROOM 27
SETROOM 28
SETROOM 29
SETROOM 30
SETROOM 31
; SETROOM 32
;
; Finally, pack the modules
MACRO PACK page,file
  IF TYP(R'file) != 0 ; Was file used and still relocatable?
    IF ABS(R'file) < ROOM'page ; Yes, does it fit on the specified page?
      ; Reduce the space available on this page.
      ROOM'page = ROOM'page - ABS(R'file)
      ; Set the relocation base for the file.
      R'file = page*#200 - ROOM'page
      ; Remember that we allocated something
      PACKED = 1
    ENDIF
  ENDIF
ENDMAC
MACRO PFILE file
  ; PACK  1,file ; The first few pages are reserved for vm.c
  ; PACK  2,file ; Those locations are filled, so don't even try.
  ; PACK  3,file
  ; PACK  4,file
  PACK  5,file
  PACK  6,file
  PACK  7,file
  PACK  8,file
  PACK  9,file
  PACK 10,file
  PACK 11,file
  PACK 12,file
  PACK 13,file
  PACK 14,file
  PACK 15,file
  PACK 16,file
  PACK 17,file
  PACK 18,file
  PACK 19,file
  PACK 20,file
  PACK 21,file
  PACK 22,file
  PACK 23,file
  PACK 24,file
  PACK 25,file
  PACK 26,file
  PACK 27,file
  PACK 28,file
  PACK 29,file
  ; PACK 30,file ; Two pages reserved for stack
  ; PACK 31,file
  ; PACK 32,file ; Reserved for operating system
ENDMAC
MACRO PACKEM
  PACKED = 0
Eof
foreach $name (sort keys %modules) {
  print "  PFILE \"$name\"\n";
}
print <<Eof;
ENDMAC
PACKEM
Eof

exit 0
