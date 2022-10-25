# include <stdio.h>
#include <malloc.h>

int main() {
    char **s;
    char foo[] = "Hello World ";
    int a = sizeof (foo);
    s = (char**) malloc(a);
    *s = foo;
    printf("s is %s \n ", *s);
    s[0] = foo;
    printf("s [0] is %s \n ", s[0]);
    free(s);
    return (0);
}
