#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include <semaphore.h>
#include <unistd.h>


pthread_mutex_t lock;
long sum = 0;
long prime_counter = 0;
int part = 0;
int counter_sta = 0;
int counter_fin = 0;




// to check if is prime number 
int is_prime(int num) {
   if (num <= 1) {   
	   return 0;
   }
   int x ;
   for (x = 2; x <= sqrt(num); x++)
   {
      if (num % x == 0)
      return 0;
   }
   return 1;
}

// to sum the prime numbers and to divide to parts.
void* sum_prime() {
	int random = 0;
	int start = counter_sta;
	int finish = counter_fin;
	counter_sta =counter_sta + part;
	counter_fin =counter_sta + part;
	int i = start;
	while (i < finish)
	{
		random = rand();
		if (is_prime(random)){
			pthread_mutex_lock(&lock);  //lock thread
			sum = sum + random;
			prime_counter++;
			pthread_mutex_unlock(&lock);  // open the thread
		}	
		i++;
    }
	return NULL;
}



int main(int argc, char *argv[]) {
	srand(atoi(argv[1])); 
    int error;    // expion
	int pro_counter = get_nprocs_conf(); // numbers of proccesores
	pthread_t tread [pro_counter];
	part = atoi(argv[2]) / pro_counter; //convert string to int 
	counter_fin =counter_fin + part;

	for(int i=0; i < pro_counter ;i++ ) {
        error = pthread_create(&(tread[i]), NULL, &sum_prime, NULL);   //create a thread
        if (error != 0) printf("\ncan not create a thread :[%s]", strerror(error));  //check
    }
	for (int j = 0; j < pro_counter; j++)
	{
		pthread_join(tread[j], NULL); 
	}
	
	printf("%ld,%ld \n", sum, prime_counter);
    exit(0);
}
