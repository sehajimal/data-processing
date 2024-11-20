#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

float *clean_delete(int *rows, int *columns, float *array2D[*columns])
{
    float (*arraycopy)[*columns] = malloc(*rows**columns * sizeof(float));
    int count = 0;
    int newRows = 0;
    long new_size = newRows * *columns;

    if (arraycopy == NULL)
    {
        return NULL;
    }

    for (int i=0; i<*rows; i++) 
    {
        for (int j=0; j<*columns; j++) 
        {
            if (!isnan(array2D[i][j]))
            {
                count = count + 1;
            }
        }

        if (count == *columns)
        {
            rows = rows + 1;
            for (int j=0; j<*columns; j++) 
            {
                arraycopy[i][j] = array2D[i][j];
            }
        }
    }
    arraycopy = realloc(arraycopy, new_size*sizeof(float));
    return *arraycopy;
}

float *clean_impute(int *rows, int *columns, float *array2D[*columns])
{
    for (int i=0; i<*columns; i++) 
    {
        float total;
        int count;
        float average;
        for (int j=0; j<*rows; j++) 
        {
            total = 0;
            count = 0;
            if (!(isnan(array2D[i][j])))
            {
                total += array2D[i][j];
                count = count + 1;
            }
        }
        if (count > 0)
        {
            average = (total /count);
        }
        else{
            average = 0;
        }

        for (int j=0; j<*rows; j++) 
        {
            if ((isnan(array2D[i][j])))
            {
                array2D[i][j] = average;
            }
        }
    }
    return *array2D;
}

//output_data() 
//{

//}


