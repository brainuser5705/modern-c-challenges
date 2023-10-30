/// file: util.c
/// description: utility functions for sorting algorithms
/// author: Ashley Liew
/// date: 10/24/23

#include <stdlib.h>
#include <stdio.h>
#include "util.h"

double* create_array(int num_values){
   
    if (num_values == 0){
        return NULL;
    }

    double* new_array;
    new_array = (double*)malloc(num_values * sizeof(double));
    
    if (new_array == NULL){
        printf("Could not allocate any more memory.\n");
        exit(1);
    }

    return new_array;

}

double* get_inputs(int num_values, char **values){
   
   double* array = create_array(num_values);
   for (int i = 0; i < num_values; i++){
        array[i] = strtod(values[i], 0);
    }

    return array;
}

void print_array(int num_values, double* array){
    if (num_values == 0){
        printf("Empty array");
    }else{
        for (int i = 0; i < num_values; i++){
            printf("%.2f, ", array[i]);
        }
    }
    printf("\n");
}
