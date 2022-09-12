#include <stdio.h>
#include <string.h>

void read(char *h){
    for(int i = 0; *(h + i) = getchar(); ++i){
        if(*(h + i) == '\n'){
            *(h + i) = '\0';
            break;
        }
    }
}

int power(int a, int b){
    int answer = 1;
    for(int i = 0; i < b; ++i)answer *= a;
    return answer;
}

void convert(int Number, int From, int To){
    //First check
    if(!(2 <= From && 10 >= From && 2 <= To && 10 >= To)){
        printf("IOE: some of From or To are broken");
        return ;
    }
    //Check that all digits from Number less then From and convert to decimal
    int a = 0, b = 0;
    for(int i = 0; Number > 0; ++i){
        a = Number % 10;
        if(a > From){
            printf("IOE: some of From or To are broken");
            return ;
        }
        Number /= 10;
        b = b + a * power(From, i);
    }
    //Convert decimal number to To
    char Line[256];
    int boof = 0;
    for(int i = 0; b > 0; ++i){
        Line[i + 1] = '\0';
        boof += sprintf(Line + boof ,"%d", b % To);
        b /= To;
    }
    printf("The answer :");
    for(int i = strlen(Line) - 1; i >= 0; --i)printf("%c", Line[i]);
    printf("\n");
}

int main()
{
    char Line[300];
    int Number, From, To;
    
    printf("Enter your number: ");
    read(Line);
    sscanf(Line, "%d", &Number);
    
    printf("From numeral system (2 - 10): ");
    read(Line);
    sscanf(Line, "%d", &From);
    
    printf("To numeral system (2 - 10): "); 
    read(Line);
    sscanf(Line, "%d", &To);
    
    convert(Number, From, To);
    return 0;
}
