//Ping => 0
//Pong => 1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 2;

pthread_t thred[N];
int zadnje;
pthread_mutex_t m;
pthread_cond_t ping;
pthread_cond_t pong;

void d_ping(pthread_cond_t u_ping){
	while(1){
		pthread_mutex_lock(&m);
		while (!zadnje){
			pthread_cond_wait(&u_ping,&m);
		}
		printf ("ping\n");
		zadnje=0;
		sleep(1);
		pthread_cond_signal(&u_pong);
		pthread_mutex_unlock(&m); 
	}
}

void d_pong(pthread_cond_t u_pong){
	while(1){
		pthread_mutex_lock(&m);
		while(zadnje){
			pthread_cond_wait(&u_pong,&m);
		}
		printf ("pong\n");
		zadnje=1;
		sleep(1);
		pthread_cond_signal(&u_ping);
		pthread_mutex_unlock(&m);
	}
}

int main(){
	int i;
	int niz[N];
	pthread_mutex_init(&m,NULL);
	zadnje=1;
	niz[0]=0;
	niz[1]=1;
	pthread_create(&thred[0],NULL,(void *)d_ping,&ping);//šalješ
	pthread_create(&thred[1],NULL,(void *)d_pong,&pong);//uvjet
	pthread_join(thred[0],NULL);
	pthread_join(thred[1],NULL);
	return 0;
}
