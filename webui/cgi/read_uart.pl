#!/usr/bin/perl

my $cgi_path = "/home/stesen/tmp/course/无线电实验/2/webui/cgi";
my @uart_data = `DISPLAY=:0.0 $cgi_path/uart_qt $ARGV[0]`;

my $line_data;
my $i = 0;

open(FILE,">/home/stesen/tmp/course/无线电实验/2/webui/cgi/data");

foreach $line_data (@uart_data) {
	printf FILE ("%d %e\n", $i, $line_data);
	$i++;
}
