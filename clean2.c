#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

float *read_data(int *rows, int *columns)
{
    scanf("%d %d", rows, columns);
    long elements = *rows * *columns;

    float (*p)[*columns] = malloc(elements * sizeof(float));
    
    if (p == NULL)
    {
        return NULL;
    } 

    for (int i=0; i<*rows; i++) 
    {
        for (int j=0; j<*columns; j++) 
        {
            scanf("%f", &p[i][j]);
        }
    } 
    return *p;
}

float *clean_delete(int *rows, int *columns, long elements, float *array2D[*columns])
{
    float (*arraycopy)[*columns] = malloc(elements * sizeof(float));
    
    if (arraycopy == NULL)
    {
        return NULL;
    }

    for (int i=0; i<*rows; i++) 
    {
        for (int j=0; j<*columns; j++) 
        {
            arraycopy[i][j] = array2D[i][j];
        }
    }
    return arraycopy;
}

//clean_impute() 
//{

//}

//output_data() 
//{

//}


