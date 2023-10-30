/// Allocates memory for new partition
/// @param num_values   number of elements to be in the partition
double* create_array(int num_values);

/// Converts character values into doubles
/// @param num_values   number of characters to convert
/// @param values       characters in string pointer
double* get_inputs(int num_values, char** values);

/// Print out array to standard output
/// @param num_values   number of values to print out
/// @param array        the double pointer array to print out
void print_array(int num_values, double* array);
