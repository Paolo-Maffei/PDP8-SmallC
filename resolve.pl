#!/usr/bin/perl

#
# Read in "extrn" and "public" to get a sense of what
# is where in the library.

$program = $ARGV[0] || die "usage: $ARGV[0] <program>.ASM";
die "input must be .ASM file" unless $program =~ /\.asm/i;

open(INPUT, "egrep -i '(extrn|public)' clib/*.ASM $program |")
  || die "egrep pipe: $!";
while (<INPUT>) {
  if (/(.*):.*PUBLIC\s*(\w+)/i) {
    $module = $1;
    $name = $2;
    warn "$module:$name hides $public{$name}:$name\n" if defined $public{$name};
    $public{$name} = $module;
  } elsif (/(.*):.*EXTRN\s*(\w+):/i) {
    $module = $1;
    $name = $2;
    if (defined($extrn{$module})) {
      $extrn{$module} .= " $name";
    } else {
      $extrn{$module} = $name;
    }
  }
}

#
# Start with the given file.
@files = ($program);
@unresolved = split(/ /, $extrn{$program});
%included = ();
$included{$program} = 1;

#
# Work through the list of unresolved symbols
$errors = 0;
%unresolved = ();
while (@unresolved) {
  $next = shift @unresolved;
  if (defined $public{$next}) {
    next if defined $included{$public{$next}};
    push(@files, $public{$next});
#warn "Adding $public{$next} for $next\n";
    push(@unresolved, split(/ /, $extrn{$public{$next}}));
    $included{$public{$next}} = 1;
  } else {
    $unresolved{$next} = 1;
  }
}
@unresolved = sort keys %unresolved;
warn "Unresolved: @unresolved\n" if @unresolved;

#
# At this point, @files contains the list of files which
# must be compiled together.  Emit a suitable compile command.
grep(s/.asm$/.c/i, @files);
print "./smallcc @files\n";

exit @unresolved;
