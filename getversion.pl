#!/usr/bin/perl

use warnings;
use strict;

my $versionnumber = `git describe`;
chomp $versionnumber;
print $versionnumber;
