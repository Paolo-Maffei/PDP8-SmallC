#!/usr/bin/perl

$max = 0;

#open(STDERR, ">log") || die "log: $!";
#
# Open the first file in binary mode and read it in.
# BUGBUG: This doesn't check the checksum.
open(INPUT, $ARGV[0]) || die "$ARGV[0]: $!";
binmode(INPUT);
@core1 = (); $loc = $store = undef;
$sum = $add = $field = 0;
while (read(INPUT, $top, 1)) {
  $top = unpack("C", $top);
  next if $top == 0200;	# Leader or Trailer
  if ($top & 0200) { # Better be field setting!
    die "$ARGV[0]: Invalid field setting" unless $top >= 0300;
    die "$ARGV[0]: Invalid field setting" if $top & 0007;
    $field = ($top & 070) >> 3;
    next;
  }
  if (defined($store)) {
    $core1[$field*4096+$loc] = $store;
    $max = $field*4096+$loc unless $max > $field*4096+$loc;
    $store = undef;
    $loc = ($loc + 1) & 07777;
    $sum += $add;
  }
  read(INPUT, $bot, 1) || die "read: $!";
  $bot = unpack("c", $bot);
  die "$ARGV[0]: ".$bot." not in bin format ". tell(INPUT) unless $bot <= 077;
  $word = ($top << 6) + $bot;
  $add = $top + $bot; # Update checksum
  if ($word > 07777) {
    #
    # Change location counter
    $loc = $word & 07777;
#printf "Loc == %04o\n", $loc;
    $sum += $add;
  } else {
    die "$ARGV[0]: no location counter" unless defined($loc);
    $store = $word;
  }
}
close(INPUT);
$sum &= 07777;
printf "$ARGV[0]: Checksum is %04o, not %04o\n", $sum, $store if $sum != $store;
#printf STDERR "$ARGV[0]: Checksum is %04o, not %04o\n", $sum, $store if $sum != $store;

#
# Open the second file in binary mode and compare it.
# BUGBUG: This doesn't check the checksum.
# BUGBUG: This doesn't handle multiple fields.
open(INPUT, $ARGV[1]) || die "$ARGV[1]: $!";
binmode(INPUT);
@core2 = (); $loc = $store = undef;
$sum = $add = $field = 0;
while (read(INPUT, $top, 1)) {
  $top = unpack("C", $top);
  next if $top == 0200;	# Leader or Trailer
  if ($top & 0200) { # Better be field setting!
    die "$ARGV[0]: Invalid field setting" unless $top >= 0300;
    die "$ARGV[0]: Invalid field setting" if $top & 0007;
    $field = ($top & 070) >> 3;
    next;
  }
  if (defined($store)) {
    $core2[$field*4096+$loc] = $store;
    $max = $field*4096+$loc unless $max > $field*4096+$loc;
    $store = undef;
    $loc = ($loc + 1) & 07777;
    $sum += $add;
  }
  read(INPUT, $bot, 1) || die "read: $!";
  $bot = unpack("c", $bot);
  die "$ARGV[0]: ".$bot." not in bin format ". tell(INPUT) unless $bot <= 077;
  $word = ($top << 6) + $bot;
  $add = $top + $bot; # Update checksum
  if ($word > 07777) {
    #
    # Change location counter
    $loc = $word & 07777;
    $sum += $add;
  } else {
    die "$ARGV[0]: no location counter" unless defined($loc);
    $store = $word;
  }
}
close(INPUT);
$sum &= 07777;
printf "$ARGV[1]: Checksum is %04o, not %04o\n", $sum, $store if $sum != $store;
#printf STDERR "$ARGV[1]: Checksum is %04o, not %04o\n", $sum, $store if $sum != $store;

for ($loc = 0; $loc <= $max; $loc++) {
  next unless defined($core1[$loc]) || defined($core2[$loc]);
  if ($core1[$loc] != $core2[$loc]) {
    printf "%04o: %04o != %04o\n",
                  $loc, $core1[$loc], $core2[$loc];
#   printf STDERR "%04o: %04o != %04o\n",
#                 $loc, $core1[$loc], $core2[$loc];
  }
}

__END__
:endofperl
