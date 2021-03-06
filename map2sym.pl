#!/usr/bin/perl
# (C) Moth, clubycoder@yahoo.com
#

my $map_start        = "Linker script and memory map";
my $valid_addr_chars = '0123456789ABCDEF';

my $in_map   = 0;
my $addr     = '';
my $max_addr = 0;
my $sym      = '';
my $junk     = '';
my $valid    = '';
my $pos      = 0;
my @sym_list = ();
while (<>) {
     chomp;
     if ($in_map) {
          ($addr,$sym,$junk) = split(" ");
          $addr = uc($addr);
          if (substr($addr,0,2) eq '0X') {
               $addr = substr($addr,2);
          }
          if (($addr) and ($sym) and (!$junk)) {
               $valid = 1;
               for ($pos = 0;$pos < length($addr);$pos++) {
                    if (index($valid_addr_chars,substr($addr,$pos,1)) < 0) {
                         $valid = 0;
                    }
               }
               if ($valid) {
                    $addr = hex($addr);
                    $sym_list[$addr] = $sym;

                    if ($addr > $max_addr) {
                         $max_addr = $addr;
                    }
               }
          }
     } elsif (index($_,$map_start) >= 0) {
          $in_map = 1;
     }
}
for ($addr = 0;$addr <= $max_addr;$addr++) {
     if ($sym_list[$addr]) {
          print sprintf("%08X %s\n",$addr,$sym_list[$addr]);
     }
}

