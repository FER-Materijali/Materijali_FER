#!perl

while($student = <>){
	@pom = split /;/, $student;
	@term = split / /, $pom[3];
	@zaklj = split / /, $pom[4];
	@sat1 = split /:/, $term[1];
	@sat2 = split /:/, $zaklj[1];
	
	if ( ($sat1[0]+1 <= $sat2[0] && ($sat2[1] > 0 || $sat2[2] > 0)) || ($term[0] ne $zaklj[0]) && $pom[0] =~ /\d/ ){
		#($sat1[0]*60+sat1[1]+60 < $sat2[0]*60+$sat2[1])
		print "\n$pom[0] $pom[1] $pom[2] - PROBLEM: $term[0] $term[1] --> $zaklj[0] $zaklj[1]"
	}
}