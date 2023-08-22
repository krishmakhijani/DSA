#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 3

int sumn = 0;
int je, jo, evensum = 0, oddsum = 0, evenarr[50], oddarr[50];

void *Even(void *threadid) {
  int i, n;
  je = 0;
  n = (int)threadid;
  for (i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      evenarr[je] = i;
      evensum += i;
      je++;
    }
  }
}

void *Odd(void *threadid) {
  int i, n;
  jo = 0;
  n = (int)threadid;
  for (i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      oddarr[jo] = i;
      oddsum += i;
      jo++;
    }
  }
}

void *SumN(void *threadid) {
  int i, n;
  n = (int)threadid;
  for (i = 1; i <= n; i++) {
    sumn += i;
  }
}

int main() {
  pthread_t threads[NUM_THREADS];
  int i, t;

  printf("Enter a number\n");
  scanf("%d", &t);

  pthread_create(&threads[0], NULL, Even, (void *)t);
  pthread_create(&threads[1], NULL, Odd, (void *)t);
  pthread_create(&threads[2], NULL, SumN, (void *)t);

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("The sum of first %d natural numbers is %d\n", t, sumn);
  printf("The sum of first %d even numbers is %d\n", t, evensum);
  printf("The sum of first %d odd numbers is %d\n", t, oddsum);
  printf("The first %d Even numbers are: \n", t);
  for (i = 0; i < je; i++) {
    printf("%d\n", evenarr[i]);
  }
  printf("The first %d Odd numbers are: \n", t);
  for (i = 0; i < jo; i++) {
    printf("%d\n", oddarr[i]);
  }
  pthread_exit(NULL);
}