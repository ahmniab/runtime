#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double run(const char *path); 

int main(int argc, char *argv[])
{
    double times[argc];

    for (int i = 1; i < argc; i++)
    {
        printf("running %d (%s) ....\n" , i , argv[i]);  
        times[ i - 1 ] = run(argv[i]);
        printf("\n");
    }
    printf("Run times :\n"); 
    for (int i = 0; i < argc - 1 ; i++)
    {
        printf("%2d - (%s) - Time : %3.4lf\n", i + 1 , argv[ i+1 ] , times[i]); 
    }
    
    
}


double run(const char *path) 
{
    clock_t start_time = clock();

    system(path);

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    return elapsed_time;
}