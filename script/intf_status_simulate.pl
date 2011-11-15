#!/usr/bin/perl -w 
use strict;
use lib("libmysql");
use DBI;

#Este script recebe o nome de uma interface e um hostname e seta o status para UP ou DOWN!

# ARG 0 = nome do host
# ARG 1 = nome da interface
# ARG 2 = status = Up|Down

die "Argumentos invalidos!\n " if (scalar(@ARGV) != 3);

#if(($ARGV[2] ne "Up") ||  ($ARGV[2] ne "Down")){
#	die "O status eh Up ou Down !!!!\n";
#}

my $database = "mydb";
my $host = "localhost";
my $user = "root";
my $password = "root";
my $table = "Interface";
my ($hostname,$interface,$status) = @ARGV;

if(lc($ARGV[2]) eq "up"){
	$status = "Up"; 
}elsif(lc($ARGV[2]) eq "down"){
	$status = "Down";
}else{
	die "Status invalido! Eh Up ou Down!\n";
}

my $dbh = DBI->connect("DBI:mysql:database=$database;host=$host", $user, $password, {RaiseError => 1});
$dbh->do("UPDATE $table SET status = '$status' where name = '$interface' AND id_hostname = '$hostname'");
$dbh->disconnect();
