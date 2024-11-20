#include <stdio.h>
#include <stdlib.h>
#include "clean.h"

int main()
{
    int rows;
    int columns;

    float *array = read_data(&rows, &columns);          //calling in order to create 2Darray

    float (*array2D)[columns] = (float (*)[columns])array;      //cast it to the correct type ( float (*)[cols]) 

     for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            printf("%.3f ", array2D[r][c]);
        }
        puts("");
    }



    return EXIT_SUCCESS;

}