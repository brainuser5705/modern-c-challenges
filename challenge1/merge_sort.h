/// Performs merge sort on array of given size
/// @param array        array to be sorted
/// @param array_size   size of the array to be sorted
double* merge_sort(int array_size, double* array);

/// Gets subarray of given array given start and end index. Split step of merge
/// sort.
/// @param array        array to get subarray from 
/// @param start_index  index of first element of subarray
/// @param end_index    index of last element of subarray
double* split(int start_index, int end_index, double* array);

/// Merges two arrays into one to created sorted array of increasing order.
/// @param arr1_size    size of first array
/// @param arr1         first array
/// @param arr2_size    size of second array
/// @param arr2         second array
double* merge(int arr1_size, double* arr1, int arr2_size, double* arr2);


