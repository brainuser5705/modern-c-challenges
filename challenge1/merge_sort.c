/// file: sort.c
/// description: merge sort algorithm with command line input for values
/// author: Ashley Liew
/// date: 10/19/2023

#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"
#include "util.h"

/// Gets numbers to sort from command line and converts to double. Initiates
/// call to merge sort.
/// @param argc         number of arguments including filename
/// @param argv         string arguments passed in from cmd-line
int main(int argc, char **argv){

    int num_values = argc-1;
    ++argv; 

    double* array = get_inputs(num_values, argv);

    printf("Initial array: ");
    print_array(num_values, array);

    double* new_array = merge_sort(num_values, array);
    free(array);

    printf("Final array: ");
    print_array(num_values, new_array);

    return 0;

}

double* merge_sort(int array_size, double* array){

    if (array_size < 2){
        return array;
    }else{

        int middle = (int)(array_size/2);

        double* left = split(0, middle, array);
        double* right = split(middle, array_size, array);

        int left_size = middle;
        int right_size = array_size - middle;

        double* sorted_left = merge_sort(left_size, left);
        double* sorted_right = merge_sort(right_size, right);

        return merge(left_size, sorted_left, right_size, sorted_right);

    } 

    return NULL;

}


double* merge(int arr1_size, double* arr1, int arr2_size, double* arr2){

    double* merged_array = create_array(arr1_size + arr2_size);

    int i = 0;
    int j = 0;

    while (i < arr1_size && j < arr2_size){
        if (arr1[i] < arr2[j]){
            merged_array[i+j] = arr1[i];
            i++;
        }else{
            merged_array[i+j] = arr2[j];
            j++;
        }
    }
    
    while (i < arr1_size){
        merged_array[i+j] = arr1[i];
        i++;
    }

    while (j < arr2_size){
        merged_array[i+j] = arr2[j];
        j++;
    }

    free(arr1);
    free(arr2);

    return merged_array;
}


double* split(int start_index, int end_index, double* array){

    double* partition = create_array(end_index-start_index);

    for (int i = start_index; i < end_index; i++){
        partition[i-start_index] = array[i];   
    }

    return partition;

}
