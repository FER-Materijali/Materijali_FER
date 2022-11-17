
$what = "brontosaurus steak";
$n = 3;
print "fred ate $n $what.\n"; # varijabla je $whats
print "fred ate $n ${what}s.\n"; # sad je ime $what
print "fred ate $n $what" . "s.\n"; # moze i ovako

if("0" lt "Z"){
	print "manje";
}

$count = 0;
while ($count < 10) {
$count += 1;
print "broj je sada $count\n";
# ispisuje brojeve 1 do 10
}

@rocks = qw{ flintstone slate rubble };
print "\n\nquartz @rocks limestone\n";
print "Three rocks are: @rocks.\n";
print "Zagrade (@rocks) su prazne.\n";

@fred = qw(hello dolly);
$y = 2;
$x = "This is $fred[1]\x{2019}s place";
print "\n".$x;
# "This is dolly\x{2019}s place"
$x = "This is $fred[$y-1]\x{2019}s place"; # same thing
print "\n".$x;

$y = "0*2";
$x = "This is $fred[$y+1]\x{2019}s place"; # same thing
print "\n".$x."\n";

@fred = qw(eating rocks is wrong);
$fred = "right";
# we are trying to say "this is right[3]"
print "this is $fred[3]\n";   # prints "wrong" using $fred[3]
print "this is ${fred}[3]\n"; # prints "right"
print "this is $fred"."[3]\n";# right again (different string)
print "this is $fred\[3]\n";  # right again (backslash hides it)

@rocks = qw/ bedrock slate lava /;
print "The rocks are:\n", @rocks;
foreach $rock (@rocks) {
$rock = "\t$rock"; # tab prije svake rijeci
$rock .= "\n"; # novi red iza rijeci
}
print "The rocks are:\n", @rocks;

@polje = (1..10);
print @polje,"\n";
@polje = reverse 1..10;
print @polje,"\n";