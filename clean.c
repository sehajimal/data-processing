/* Sehaj Ajimal, 400511220, 2024 
 * SE 2XC3 Data Processing Assignment
 * 
 * The purpose is to process a 2D array by reading the data and cleaning it 
 * We can get rid of nan values by finding the average of the values in the column or by completley deleting the row.
 * Each function handles different aspects by reading, computing and outputting the array
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clean.h"

/* Main
 * 
 * The purpose of the main is to run the functions in a certain order to output the 2Darray.
 * if -d flag is used then I use the deletion strategy otherwise the imputation strategy
 *
 * Parameters: argc: The number of command-line arguments. argv: An array of command-line arguments.
 *
 * Return value: EXIT_SUCCESS on successful execution.
 */
int main(int argc, char *argv[])
{
    int rows;
    int columns;

    // Read and store the data into a 2D array
    float *array = read_data(&rows, &columns);          
    float (*array2D)[columns] = (float (*)[columns])array; // Cast to the correct 2D type

    if (argc == 1) 
    {
        // Perform imputation strategy
        float *array1 = clean_impute(&rows, &columns, array2D);
        float (*array1_2D)[columns] = (float (*)[columns])array1;
        output_data(&rows, &columns, array1_2D);
        free(array1_2D);
    }

    if (argc == 2 && strcmp(argv[1], "-d") == 0) 
    {
        // Deletion strategy
        float *array1 = clean_delete(&rows, &columns, array2D);
        float (*array1_2D)[columns] = (float (*)[columns])array1;
        output_data(&rows, &columns, array1_2D);
        free(array1_2D);
    }

    return EXIT_SUCCESS;
}