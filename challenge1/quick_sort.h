void partition(int num_values, double* array, int* numLess, double** less, 
    int* numEqual, double** equal, int* numGreater, double** greater);

/// Concats two arrays of given size in order of the arguments into array1.
/// @param
 void concat(int array1_size, double** array1, int array2_size, 
    double** array2);

/// Appends value to given array of size. If array is NULL, then malloc memory 
/// of size 1. Else realloc to memory of its current size + 1. A pointer to the
/// array (double**) is necessary to persist changes to array after appending,
/// hence the dereferencing after the memory assignement and indexing.
/// @param value        the value to append
/// @param array_size   the size of the array prior to appending
/// @param array        pointer to array to append to
 void append(double value, int array_size, double** array);

 double* quick_sort(int num_values, double* array);
 
