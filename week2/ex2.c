#include <stdio.h>
#include <string.h>

int main( ) {
    char Line[257];
    int boof;
    
    for(int i = 0; boof = getchar(); ++i)
        if((boof == '.') || (boof =='\n')){
            Line[i] = '\0';
            break;
        }
            else Line[i] = (char)boof;
    
    
    for(int i = strlen(Line); i >= 0; --i) putchar(Line[i]);
    
    return 0;
}
