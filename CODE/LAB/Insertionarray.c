#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int pid;
  int bt;
  int wt;
  int tat;
} Process;

void sortProcessesByBurstTime(Process P[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (P[i].bt > P[j].bt) {
        Process temp = P[i];
        P[i] = P[j];
        P[j] = temp;
      }
    }
  }
}

void calculateWaitingAndTurnaroundTime(Process P[], int n) {
  P[0].wt = 0; 
  P[0].tat = P[0].bt;
  for (int i = 1; i < n; i++) {
    P[i].wt = P[i - 1].tat;
    P[i].tat = P[i].wt + P[i].bt;
  }
}

void printProcessInfo(Process P[], int n) {
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", P[i].pid, P[i].bt, P[i].wt, P[i].tat);
  }
}

// Main function
int main() {
  int n; 
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  Process P[n];

  for (int i = 0; i < n; i++) {
    printf("Enter the process ID and burst time for process %d: ", i + 1);
    scanf("%d %d", &P[i].pid, &P[i].bt);
  }

  sortProcessesByBurstTime(P, n);

  calculateWaitingAndTurnaroundTime(P, n);

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