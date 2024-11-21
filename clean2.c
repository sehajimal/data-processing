/* Sehaj Ajimal, 400511220, 2024
 * Second .c file which is used to make the code more modular and contains all of the functions outside of main
 * These are the functions specified in the question to create an array and process it in two different ways
 * Then the array is outputted as specified.
 **/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* 
 * read_data
 * 
 * Reads the rows and columns and number of elements of a 2D array from standard input.
 *
 * Parameters: rows: Pointer to store the number of rows. columns: Pointer to store the number of columns.
 *
 * Return value: Pointer to the dynamically allocated array containing the input data.
 */
float *read_data(int *rows, int *columns)
{

    scanf("%d %d", rows, columns);
    long elements = *rows * *columns;

    // Allocate memory for the 2D array
    float (*p)[*columns] = malloc(elements * sizeof(float));
    
    if (p == NULL)
    {
        return NULL; // Return NULL if memory allocation fails
    } 

    // Populate the array with input data
    for (int i = 0; i < *rows; i++) 
    {
        for (int j = 0; j < *columns; j++) 
        {
            scanf("%f", &p[i][j]);
        }
    } 
    return *p;
}

/* 
 * clean_delete
 *
 * The purpose is to remove the rows containing nan from the 2D array.
 *
 * Parameters: rows: Pointer to the number of rows, updated after deletion. columns: Pointer to the number of columns. array2D: Pointer to the 2D array to process.
 *
 * Return value: Pointer to the new 2D array with rows containing nan values removed.
 */
float *clean_delete(int *rows, int *columns, float (*array2D)[*columns])
{
    // Allocate memory for the new array
    float (*arraycopy)[*columns] = malloc(*rows * *columns * sizeof(float));
    int newRows = 0;

    if (arraycopy == NULL)
    {
        return NULL; // Return NULL if memory allocation fails
    }

    // Process rows and exclude those with NaN values
    for (int i = 0; i < *rows; i++) 
    {
        int remove = 0;
        for (int j = 0; j < *columns; j++) 
        {
            if (isnan(array2D[i][j]))
            {
                remove = 1; // Mark row for removal if NaN is found
                break;
            }
        }

        if (remove == 0)
        {                
            // Copy the row to the new array
            for (int j = 0; j < *columns; j++) 
            {
                arraycopy[newRows][j] = array2D[i][j];
            }
            newRows++;
        }
    }

    *rows = newRows;
    arraycopy = realloc(arraycopy, newRows * *columns * sizeof(float)); // Resize memory
    return *arraycopy;
}

/* 
 * clean_impute
 *
 * The purpose is to replace the nan with the average of the columns in the 2D array.
 *
 * Parameters: rows: Pointer to the number of rows. columns: Pointer to the number of columns. array2D: Pointer to the 2D array to process.
 *
 * Return value: Pointer to the modified 2D array with NaN values replaced.
 */
float *clean_impute(int *rows, int *columns, float (*array2D)[*columns])
{
    for (int j = 0; j < *columns; j++) 
    {
        float total = 0;
        int count = 0;
        float average;

        // Calculate column average
        for (int i = 0; i < *rows; i++) 
        {
            if (!isnan(array2D[i][j]))
            {
                total += array2D[i][j];
                count++;
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

        // Replace NaN values with the column average
        for (int i = 0; i < *rows; i++) 
        {
            if (isnan(array2D[i][j]))
            {
                array2D[i][j] = average;
            }
        }
    }
    return *array2D;
}

/* 
 * output_data
 *
 * The purpose is to print the 2D array as specified
 *
 * Parameters: rows: Pointer to the number of rows. columns: Pointer to the number of columns. array2D: Pointer to the 2D array to output.
 */
void output_data(int *rows, int *columns, float (*array2D)[*columns]) 
{
    printf("%d %d\n", *rows, *columns);

    for (int r = 0; r < *rows; r++) 
    {
        for (int c = 0; c < *columns; c++) 
        {
            printf("%.3f ", array2D[r][c]); // Print each element with 3 decimal precision
        }
        puts("");
    }
}