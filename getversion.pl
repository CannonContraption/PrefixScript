#!/usr/bin/perl
my $versionnumber = `git describe`;
chomp $versionnumber;
print $versionnumber;
