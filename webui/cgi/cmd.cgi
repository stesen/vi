#!/usr/bin/perl

my ($data, $i, @datas, $key, $val, %FORM);

$data = $ENV{'QUERY_STRING'};

@datas = split(/&/,$data);

foreach $i (0 ..$#datas) {
    $datas[$i] =~ s/\+/ /g;
    ($key, $val) = split(/=/,$datas[$i],2);
    $key =~ s/%(..)/pack("c",hex($1))/ge;
    $val =~ s/%(..)/pack("c",hex($1))/ge;
    $val =~ s/<!--(.|\n)*-->//g;
    $FORM{$key} .= "\0" if (defined($FORM{$key}));
    $FORM{$key} .= $val;
}

if ( $FORM{"cmd"} ) {
    print "Content-type: text/html\n\n";

    print "<html>\n";
    print "<head>\n";
    print "<title>CGI</title>\n";
    print "</head>\n";
    print "<body bgcolor=white>\n";

    print "<hr>\n";

    print "cmd = $FORM{'cmd'}<br>\n";

    print "<hr>\n";

    print "</body>\n";
    print "</html>\n";
}
