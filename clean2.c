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

float *clean_delete(int *rows, int *columns, float (*array2D)[*columns])
{
    float (*arraycopy)[*columns] = malloc(*rows**columns * sizeof(float));
    int newRows = 0;

    if (arraycopy == NULL)
    {
        return NULL;
    }

    for (int i=0; i<*rows; i++) 
    {
        int remove = 0;
        for (int j=0; j<*columns; j++) 
        {
            if (isnan(array2D[i][j]))
            {
                remove = 1;
                break;
            }
        }

        if (remove == 0)
        {                
            for (int j=0; j<*columns; j++) 
            {
                arraycopy[newRows][j] = array2D[i][j];
            }
            newRows = newRows + 1;
        }
    }
    *rows = newRows;
    arraycopy = realloc(arraycopy, newRows* *columns *sizeof(float));
    return *arraycopy;
}

float *clean_impute(int *rows, int *columns, float (*array2D)[*columns])
{
    for (int j=0; j<*columns; j++) 
    {
        float total = 0;
        int count = 0;
        float average;
        for (int i=0; i<*rows; i++) 
        {
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

        else
        {
            average = 0;
        }

        for (int i=0; i<*rows; i++) 
        {
            if ((isnan(array2D[i][j])))
            {
                array2D[i][j] = average;
            }
        }
    }
    return *array2D;
}

void output_data(int *rows, int *columns, float (*array2D)[*columns]) 
{
    printf("%d %d\n", *rows, *columns);

    for (int r = 0; r < *rows; r++) {
        for (int c = 0; c < *columns; c++) {
            printf("%.3f ", array2D[r][c]);
        }
        puts("");
    }
}


