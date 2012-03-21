#!/usr/bin/perl

#
# Read a .o file and emit the traditional .bin format.
# Abort if relocation information is found.

foreach $f (@ARGV) {
    open(INPUT, $f) || die "$f: $!";
    $bin = $f; $bin =~ s/.o$//; $bin =~ s/$/.bin/;
    die "$bin == $f!" if $bin eq $f;
    open(OUTPUT, ">$bin") || die "$bin: $!";
    binmode(OUTPUT);
    print "$bin\n";
    for ($i = 0; $i < 32; $i++) {
      print OUTPUT pack("c", 0200);
    }
    $checksum = 0;
    undef($loc);
    $field = 0;
    while (<INPUT>) {
      # Ignore <symbol>=<stuff>
      next if /^\w+/;
      # .=#nnnnn sets the address.
      if (/^[.]=#*(\d+)/) {
        $addr = oct($1);
        die "Bad address $addr" unless ($addr >= 0) && ($addr <= 077777);
        $nf = $addr >> 12;
        print OUTPUT pack("c", 0300 + ($nf<<3)) unless $nf == $field;
        $field = $nf;
        $loc = $addr & 07777;
        print OUTPUT pack("c", 0100 + ($loc>>6));
        print OUTPUT pack("c", $loc & 077);
        $checksum += 0100 + ($loc>>6) + ($loc & 077);
        next;
      }
      # Other lines attempting to set "." will undef $loc.
      if (/^[.]=/) {
        undef $loc;
        next;
      }
      # It better be a constant!
      die "Unrecognised input: $_" unless /^#*(\d+)\r*$/;
      $data = oct($1);
      die "Bad data $data" unless ($data >= 0) && ($data <= 07777);
      die "No location counter!\n" unless defined $loc;
      print OUTPUT pack("c", ($data>>6));
      print OUTPUT pack("c", $data & 077);
      $checksum += ($data>>6) + ($data & 077);
    }
    $checksum = $checksum & 07777;
    print OUTPUT pack("c", ($checksum>>6));
    print OUTPUT pack("c", $checksum & 077);
    for ($i = 0; $i < 32; $i++) {
      print OUTPUT pack("c", 0200);
    }
    close(OUTPUT) || die "$bin: $!";
}
