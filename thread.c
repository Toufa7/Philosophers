#include <pthread.h>
#include <stdio.h>
#include <limits.h>

int i = 0;

void	*function(void* ignore)
{
	pthread_mutex_t	*lock = ignore;
	int j = 0;
	while (j < 40000)
	{
		pthread_mutex_lock(lock);
        j++;
        pthread_mutex_unlock(lock);
	}
	return (0);
}

int main( void )
{
    pthread_t	idi[2];
	pthread_mutex_t	mutex;
	pthread_mutex_init(&mutex, NULL);
	
	int a = 0;
	while (a < 2)
	{
    	pthread_create(&idi[a], NULL, &function, &mutex);
		a++;
	}
	a = 0;
	while (a < 2)
		pthread_join(idi[a++], NULL);
	printf("%d\n",i);
}
