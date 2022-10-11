#include <stdio.h>
#include <stdlib.h>
// I need to find CT, TAT, WT, Average TAT, Average WT
void readArrivalAndBurstTime(int* a, int* b, int n);

void SJNsort(int *a, int *b, int n);

void swap(int *, int*);

void SimulationJSN(int *, int *, int *, int *, int *, int);

int max(int a, int b);

double makeAvarange(int *, int);

int main()
{
    int NumberOfProcesses;

    printf("Enter numbers of processes: ");
    scanf("%d", &NumberOfProcesses);

    int AT[NumberOfProcesses], BT[NumberOfProcesses];
    readArrivalAndBurstTime(AT, BT, NumberOfProcesses);

    int CT[NumberOfProcesses], TAT[NumberOfProcesses], WT[NumberOfProcesses];
    SJNsort(AT, BT, NumberOfProcesses);
    SimulationJSN(AT, BT, CT, TAT, WT, NumberOfProcesses);

    double AvarageTAT = makeAvarange(TAT, NumberOfProcesses), AvarangeWT = makeAvarange(WT, NumberOfProcesses);

    printf("AT  BT  CT  TAT  WT\n");
    for(int i = 0; i < NumberOfProcesses; ++i){
        printf("%d   %d   %d   %d   %d\n", AT[i],  BT[i],  CT[i],  TAT[i],  WT[i]);
    }
    printf("AvarageTAT: %f     AvarangeWT: %f", AvarageTAT, AvarangeWT);
}

void readArrivalAndBurstTime(int *a, int* b, int n){
    for(int i = 0; i < n; ++i){
        printf("Enter Arrival and Burst time of process %d:\n", i + 1);
        scanf("%d %d", &a[i], &b[i]);
        printf("\n");
    }
}

void SJNsort(int *a, int *b, int n){
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(a[j] < a[i] || (a[j] == a[i] && b[j] < b[i])){
                swap(&a[i], &a[j]);
                swap(&b[i],&b[j]);
            }
}

int max(int a, int b){
    if(a > b)
        return a;
    else return b;
}

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void SimulationJSN(int *AT, int *BT, int *CT, int *TAT, int *WT, int n){
    if(n > 0){
        *CT = *AT + *BT;
        *TAT = *BT;
        *WT = 0;
    }

    for(int i = 1; i < n; ++i){
        CT[i] = max(CT[i - 1], AT[i]) + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
}

double makeAvarange(int *List, int n){
    int sum = 0;
    for(int i = 0; i < n; ++i)sum += List[i];
    return 1.0 * sum / n;
}
