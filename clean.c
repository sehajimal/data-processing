#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clean.h"

int main(int argc, char *argv[])
{
    int rows;
    int columns;

    float *array = read_data(&rows, &columns);          //calling in order to create 2Darray

    float (*array2D)[columns] = (float (*)[columns])array;      //cast it to the correct type ( float (*)[cols]) 

    if (argc == 1) 
    {
        float *array1 = clean_impute(&rows, &columns, array2D);
        float (*array1_2D)[columns] = (float (*)[columns])array1;
        output_data(&rows, &columns, array1_2D);
        free(array1_2D);
    }

    if (argc == 2 && strcmp(argv[1], "-d") == 0) 
    {
        float *array1 = clean_delete(&rows, &columns, array2D);
        float (*array1_2D)[columns] = (float (*)[columns])array1;
        output_data(&rows, &columns, array1_2D);
        free(array1_2D);
    }

    return EXIT_SUCCESS;
}