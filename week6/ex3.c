#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>

int queue[10000]; //it is crutch for queue
int CurrentElementOfQueue = 0, NumberOfElements = 0, left = 0;

void copy(int *, int *, int);

void zero(int *, int);

void readArrivalAndBurstTime(int* a, int* b, int n);

void SJNsort(int *a, int *b, int n);

void swap(int *, int*);

void SimulationRR(int *, int *, int *, int *, int *, int, int);

int max(int a, int b);

double makeAvarange(int *, int);

int main()
{
    int NumberOfProcesses, kvant;

    printf("Enter numbers of processes: ");
    scanf("%d", &NumberOfProcesses);

    printf("Enter kvant: ");
    scanf("%d", &kvant);

    int AT[NumberOfProcesses], BT[NumberOfProcesses];
    readArrivalAndBurstTime(AT, BT, NumberOfProcesses);

    int CT[NumberOfProcesses], TAT[NumberOfProcesses], WT[NumberOfProcesses];
    SJNsort(AT, BT, NumberOfProcesses);
    SimulationRR(AT, BT, CT, TAT, WT, NumberOfProcesses, kvant);

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

void SimulationRR(int *AT, int *BT, int *CT, int *TAT, int *WT, int n, int kvant){
    int NumberOfFinished = 0, flags[n], CurrentTime = *AT, BTcopy[n];
    copy(BT, BTcopy, n);
    zero(flags, n);
    queue[CurrentElementOfQueue] = 0;
    NumberOfElements = 1;

    while(NumberOfFinished < n){
        int id = queue[CurrentElementOfQueue];
        if(BTcopy[id] <= kvant){
            flags[id] = 1;
            NumberOfFinished++;
            NumberOfElements--;
            CurrentTime += BTcopy[id];
            TAT[id] =  CurrentTime - AT[id];
            CT[id] = CurrentTime;
            WT[id] = TAT[id] - BT[id];
            CurrentElementOfQueue++;
        }
        else {
            BTcopy[id] -= kvant;
            CurrentTime += kvant;
            queue[CurrentElementOfQueue + NumberOfElements] = id;
            CurrentElementOfQueue++;
        }

        for(int i = 0; i < n; ++i){
            if(!flags[i] && (CurrentTime >= AT[i])){
                queue[CurrentElementOfQueue + NumberOfElements] = i;
                NumberOfElements++;
                flags[i] = 1;
            }
        }
        if(NumberOfElements == 0){
            CurrentTime = 10000000;
            for(int i = 0; i < n; ++i)
                if(!flags[i])
                    if(CurrentTime > AT[i]){
                        CurrentTime = AT[i];
                        id = i;
                    }
            CurrentElementOfQueue++;
            queue[CurrentElementOfQueue] = id;
            NumberOfElements = 1;
        }
    }
}

double makeAvarange(int *List, int n){
    int sum = 0;
    for(int i = 0; i < n; ++i)sum += List[i];
    return 1.0 * sum / n;
}

void zero(int *ptr, int n){
    for(int i = 0; i < n; ++i)ptr[i] = 0;
}

void copy(int *a, int *b, int n){
    for(int i = 0; i < n; ++i)b[i] = a[i];
}
