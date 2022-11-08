#include <bits/types/FILE.h>
#include <stdio.h>

void SimulationOfAgeing(int*, int*, int);

void switching(int pInt[], int i);

void someFunction(int numberPageFrame);

int main() {

    someFunction(10);
    someFunction(50);
    someFunction(100);

    return (0);
}

void someFunction(int numberPageFrame) {
    int hits = 0, misses = 0;
    SimulationOfAgeing(&hits, &misses, numberPageFrame);

    printf("Number of Page Frame: %d;\nHits: %d;\nMisses: %d.\n\n", numberPageFrame, hits, misses);
}

void SimulationOfAgeing(int *hit, int *miss, int pageFrame){

    FILE *f1 = fopen("/home/nfedorovich/OS_C/Help/input.txt", "r");
    int simulationOfPagesFrameId[pageFrame], simulationOfPagesFrameBits[pageFrame];
    for(int i = 0; i < pageFrame; ++i)simulationOfPagesFrameId[i] = -1;
    for(int i = 0; i < pageFrame; ++i)simulationOfPagesFrameBits[i] = 100000000; // I have 9 bits
    int idBits = 0; // for swapping

    while(!feof(f1)){
        int currentNewPage;
        fscanf(f1, "%d", &currentNewPage);

        int  flag = 0, minimum = 999999999, idForMin;

        //Let the CPU refresh rate coincide with the time of checking for "novelty"
        for(int i = 0; i < pageFrame; ++i)
            if(currentNewPage == simulationOfPagesFrameId[i]){
                idBits = i;
                flag = 1;
                break;
            }
            else if(simulationOfPagesFrameId[i] == -1){
                flag = 2;
                idForMin = i;
                break;
            }
            else if(minimum > simulationOfPagesFrameBits[i]){
                minimum = simulationOfPagesFrameBits[i], idForMin = i;
            }

        if(flag == 2){
            (*miss)++;
            simulationOfPagesFrameId[idForMin] = currentNewPage;
            simulationOfPagesFrameBits[idForMin] = 100000000;
            continue;
        }

        switching(simulationOfPagesFrameBits, pageFrame);
        if(flag == 1){
            simulationOfPagesFrameBits[idBits] += 100000000;
            (*hit)++;
        }
        else{
            (*miss)++;
            simulationOfPagesFrameId[idForMin] = currentNewPage;
            simulationOfPagesFrameBits[idForMin] = 100000000;
        }
    }
}

void switching(int pInt[], int n) {
    for(int i = 0; i < n; ++i)pInt[i] /= 10;
}


