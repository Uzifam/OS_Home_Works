#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
    //Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1 = 0;
    scanf("%d", &n1);

    //Create a new array of n1 int
    if (n1 < 0)
        n1 = 0;
    int *a1 = (int *) malloc(n1 * sizeof(int));/* Fill in*/
    int i;
    for (i = 0; i < n1; i++) {
        //Set each value in a1 to 100
        /*Fill in*/
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ",/*Fill in*/ a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    if (n2 < 0)
        n2 = 0;
    a1 = (int *) realloc(a1, n2 * sizeof(int));/* Fill in*/

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    if (n2 > n1)
        for (i = n1; i < n2; ++i)a1[i] = 0;
    /*
    Fill
    In
    */


    for (i = 0; i < n2; i++) {
        //Print each element out (to make sure things look right)
        printf("%d ",/* Fill in */a1[i]);
    }
    printf("\n");
    free(a1);

    //Done with array now, done with program :D

    return 0;
}
