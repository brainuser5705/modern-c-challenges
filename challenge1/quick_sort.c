#include <stdio.h>
#include <stdlib.h> 
#include "quick_sort.h"
#include "util.h"

int main(int argc, char** argv){

    int num_values = argc-1; ++argv;

    double* array = get_inputs(num_values, argv);

    printf("Original array: \n");
    print_array(num_values, array);

    printf("Final array: \n");
    print_array(num_values, quick_sort(num_values, array));

    quick_sort(num_values, array);
    return 0;

}

double* quick_sort(int num_values, double* array){

    if (num_values == 0){
        return NULL;
    }

    // setting initial values 
    int numLess = 0;
    int numEqual = 0;
    int numGreater = 0;
    double* less = NULL;
    double* equal = NULL;
    double* greater = NULL;

    partition(num_values, array, &numLess, &less, &numEqual, &equal, &numGreater,
        &greater);

    double* sortedLess = quick_sort(numLess, less);
    double* sortedGreater = quick_sort(numGreater, greater);

    // less is the base array
    concat(numLess, &less, numEqual, &equal);
    concat(numLess + numEqual, &less, numGreater, &greater);

    print_array(numLess + numEqual, sortedLess);

    return sortedLess;
     
}

void partition(int num_values, double* array, int* numLess, double** less, 
    int* numEqual, double** equal, int* numGreater, double** greater){

    if (!num_values){
        return;
    }

    int pivot = array[0];

    for (int i = 0; i < num_values; i++){

        int value = array[i];

        if (value < pivot){
            append(value, *numLess, less);
            *numLess += 1;
        }else if (value == pivot){
            append(value, *numEqual, equal);
            *numEqual += 1;
        }else{
            append(value, *numGreater, greater);
            *numGreater += 1;
        }

    }
    
}

void append(double value, int array_size, double** array){

    // This function updates the array memory space first, then insert the value
    // at the end. It determines if it needs to malloc (make new memory) or
    // realloc (extend memory) based on its size prior to appending.

    if(array_size == 0){

        *array = (double*)malloc(1 * sizeof(double));

        if (*array == NULL){
            printf("Could not allocate any more memory.\n");
            exit(1); 
        }

        *array[0] = value;

    }else{

        // needs to reassign because realloc invalidates the original ptr
        *array = (double *)realloc((void *)*array, (array_size + 1) *
            sizeof(double)); 

        // must deference first bc indexing takes precedence
        (*array)[array_size] = value; 
    }
}

void concat(int array1_size, double** array1, int array2_size, 
    double** array2){

    // extend array1 memory to fit new elements from array2
    *array1 = (double *)realloc((void *)*array1, (array1_size + array2_size) *
                sizeof(double));

    if (*array1 == NULL){
        printf("Could not reallocate any more memory. \n");
        exit(1);
    }
    
    // placing elements of array2 into array1
    for (int i = 0; i < array2_size; i++){
        (*array1)[array1_size + i] = (*array2)[i];
    }

    // might not be necessary since orig pointer gets invalidated by realloc
    free(*array2);
}
