#!/usr/bin/perl

# ARG 0 = ID MAXIMO DAS INTERFACES!
# ARG 1 = Qnt de inserts a ser gerados!
# ARG 2 = BYTES_IN_MAX
# ARG 3 = BYTES_OUT_MAX
# ARG 4 = DELTA T em segundos a cada iteracao!
# ARG 5 = DATA FUTURA SOMENTE =>=> YYYY-MM-DD, se deixado em branco sera a data atual.

use strict;
use lib("libmysql");
use DBI;

### ESTE SCRIPT GERA VALORES ALEATORIOS BASEADO EM ALGUNS ARGUMENTOS E CADA INSERCAO EH COLOCADA NO BANCO COM O TEMPO ATUAL|FUTURO yyyy-mm-dd Alem disso UM DELTA A CADA ITERACAO A IDEIA EH SIMULAR UM INSERCAO AO LONGO DO TEMPO!

die "Argumentos invalidos!\n " if (scalar(@ARGV) < 5);

my $database = "mydb";
my $host = "localhost";
my $user = "root";
my $password = "root";
my $table = "HistBw";
my $dbh = DBI->connect("DBI:mysql:database=$database;host=$host", $user, $password, {RaiseError => 1});
my ($ids,$n,$bytesIn,$bytesOut,$delta,$date_future) = @ARGV;

$date_future = "\'$date_future\'";
if ($date_future eq ""){
	$date_future = "NOW()";
}

my $temp_delta = 0;

#$dbh->do("insert into HistBw (date,bw_in,bw_out,id_intf) values (TIMESTAMPADD(SECOND,0,'2014-4-4'),300,300,1)");

for(my $i = 0; $i<$n ;$i++){
        my $temp_id = 1+int(rand($ids)); # 1 ate ids inclusive
        my $temp_in = 1+int(rand($bytesIn)); # 1 ate bytesIn inclusive

        my $temp_out = 1+int(rand($bytesOut)); # 1 ate bytesOut inclusive
	$dbh->do("INSERT INTO $table (date,bw_in,bw_out,id_intf) VALUES (TIMESTAMPADD(SECOND,$temp_delta,$date_future),?,?,?)",undef,"$temp_in","$temp_out","$temp_id");
	$temp_delta+=$delta;
}

$dbh->disconnect();
