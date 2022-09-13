#include <stdio.h>
#include <string.h>
#include <math.h>

void read(char *h){
    for(int i = 0; *(h + i) = getchar(); ++i){
        if(*(h + i) == '\n'){
            *(h + i) = '\0';
            break;
        }
    }
}

int count(char line[], char boof){
    int answer = 0;
    for(int i = 0; i < strlen(line); ++i)
        if((boof == line[i]) || (abs(boof - line[i]) == abs('a' - 'A')))
            answer++;
    return answer;        
}

void countAll(char line[]){
    for(int i = 0; i < strlen(line); ++i){
        printf("%c:%d, ", line[i], count(line, line[i]));
    }
    printf("\n");
}

int main()
{
    char Line[300], Boof = 'i';
    
    printf("Enter your line: ");
    read(Line);
    
    countAll(Line);
    
    
    return 0;
}
