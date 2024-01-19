#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double run(const char *path); 
char analysis_args(int argc, char *argv[]); 
size_t strlen();
char is_equals(const char *_str1 , const char *_str2);

char __sorting = 0 ; // Zero no sort , 1 ascending , 2 descending

int main(int argc, char *argv[])
{
    int start = 1;
    char output = analysis_args(argc , argv);
    printf("out = %d\n",output);
    if(output == 1) 
    {
        start = 2;
    }
    else if (output == 2) argc--;
    
    

    double times[argc];
    
    for (int i = start; i < argc; i++)
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

char analysis_args(int argc, char *argv[])
{
    size_t flag_index;
    if (argv[1][0] == '-')
        flag_index = 1;
    else if (argv[ argc -1 ][0] == '-')
        flag_index = argc -1 ;
    else return 0;

    if (is_equals(argv[flag_index] + 1 , "asc"))
    {
        __sorting = 1 ;
    }
    else if (is_equals(argv[flag_index] + 1 , "desc"))
    {
        __sorting = 2 ;
    }
    else{
        fprintf(stderr , "%d is not a flag\n");
        exit(EXIT_FAILURE);
    }
    
    return (flag_index == 1)? 1 : 2 ;
    
    
}

size_t strlen(const char *str){
    size_t i  = 0 ;
    while(str[i]) i++;
    return i ;
}

char is_equals(const char *_str1 , const char *_str2)
{
    if (strlen(_str1) != strlen(_str2))
        return 0;
    for (size_t i = 0; _str1[i]; i++)
        if (_str1[i] != _str2[i])
            return 0;
    return 1 ;
}