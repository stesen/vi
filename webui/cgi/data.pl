#!/usr/bin/perl

my @a = `$ARGV[0] $ARGV[1]`;

my @b = split(/ /, $a[2]);
chomp ($a[0]);
chomp ($a[1]);
chomp ($a[2]);

print "均值: ", $a[0], "\n";
print "方差: ", $a[1], "\n";
print "当前值: ", $b[-2], "\n";
print "采样值: ", $a[2], "\n";
