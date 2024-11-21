float *read_data(int *rows, int *columns);
float *clean_delete(int *rows, int *columns, float (*array2D)[*columns]);
float *clean_impute(int *rows, int *columns, float (*array2D)[*columns]);
void output_data(int *rows, int *columns, float (*array2D)[*columns]);