#!/usr/bin/perl
use CGI;

my $q = new CGI;
my $params = $q->Vars;
my $mod = $params->{"mod"};

my $cgi_path = "/home/stesen/tmp/course/无线电实验/2/webui/cgi";
my $html_path = "/home/stesen/tmp/course/无线电实验/2/webui/html";
my $cmd;

$cmd = "vdc" if ($mod eq "dv");
$cmd = "vac" if ($mod eq "av");
$cmd = "adc" if ($mod eq "di");
$cmd = "aac" if ($mod eq "ai");
$cmd = "freq" if ($mod eq "fq");
$cmd = "ohms" if ($mod eq "re");

`rm -f ${html_path}/txt`;
`rm -f ${cgi_path}/data`;
`$cgi_path/read_uart.pl $cmd`;
my $pdata = `$cgi_path/data.pl $cgi_path/${mod}.m $cgi_path/data`;
open(FILE,">/home/stesen/tmp/course/无线电实验/2/webui/html/txt");
printf FILE ("$pdata\n");

sleep(2);
exec "$cgi_path/redirect.cgi", "/html/$mod.html";
