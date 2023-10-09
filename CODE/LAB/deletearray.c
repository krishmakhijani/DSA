#include <stdio.h>

// Structure to store process information
typedef struct {
  int pid; 
  int bt; 
  int wt; 
  int tat; 
} Process;

void calculateWaitingTime(Process P[], int n) {
  P[0].wt = 0; // Waiting time for the first process is always 0
  for (int i = 1; i < n; i++) {
    P[i].wt = P[i - 1].bt + P[i - 1].wt;
  }
}

void calculateTurnaroundTime(Process P[], int n) {
  for (int i = 0; i < n; i++) {
    P[i].tat = P[i].bt + P[i].wt;
  }
}

void printProcessInfo(Process P[], int n) {
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", P[i].pid, P[i].bt, P[i].wt, P[i].tat);
  }
}

int main() {
  int n; 
  printf("Enter the number of processes: ");
  scanf("%d", &n);


  Process P[n];


  for (int i = 0; i < n; i++) {
    printf("Enter the process ID and burst time for process %d: ", i + 1);
    scanf("%d %d", &P[i].pid, &P[i].bt);
  }

  calculateWaitingTime(P, n);
  calculateTurnaroundTime(P, n);

  printProcessInfo(P, n);

  float avgWaitingTime = 0;
  float avgTurnaroundTime = 0;
  for (int i = 0; i < n; i++) {
    avgWaitingTime += P[i].wt;
    avgTurnaroundTime += P[i].tat;
  }
  avgWaitingTime /= n;
  avgTurnaroundTime /= n;


  printf("\nAverage waiting time: %f\n", avgWaitingTime);
  printf("Average turnaround time: %f\n", avgTurnaroundTime);

  return 0;
}