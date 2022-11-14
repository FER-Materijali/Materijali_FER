#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<time.h>

static int pid;

void p_r( int sig ){
	kill(pid, SIGKILL);
	exit(0);
}

int main(int argc, char *argv[]){
	
	int i, j;
	pid = atoi(argv[1]);
	sigset(SIGINT, p_r);
	srand((unsigned)time(NULL));

	while(1){
		i = rand() % 3 + 3;
		sleep(i);
		j = rand () % 4 + 1;
		switch(j){
			case(1): kill(pid, SIGILL);
				break;
			case(2): kill(pid, SIGHUP);
				break;
			case(3): kill(pid, SIGALRM);
				break;
			case(4): kill(pid, SIGABRT);
				break;
		}
	}
	return 0;
}
