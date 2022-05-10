#include <stdio.h>
#include <unistd.h>
#include <pthread.h>



void *my_turn(void *arg)
{
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("Voce é fofo! %d\n", i);
	}
	return (NULL);
}

void *your_turn(){
	for (int i = 0; i < 8; i++)
	{
		sleep(2);
		printf("Não, voce que é! \n");
	}
}

int main()
{
	int status;
	pthread_t newthread;

	pthread_create(&newthread, NULL, my_turn, NULL);
	your_turn();

}