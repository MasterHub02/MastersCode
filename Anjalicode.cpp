#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
/**
* @brief A template class for a sortable dynamic array with exception handling.
*
* @tparam T The type of elements in the array (e.g., int, double, std::string).
*/
template <typename T>

class SortableArray {
private:
std::vector<T> data;
public:
/**
* @brief Constructor for the SortableArray.
* @param arr A vector of elements to initialize the array.
*/
SortableArray(const std::vector<T>& arr) : data(arr) {}
/**
* @brief Sorts the array using the standard library's sort algorithm.
* @note This relies on the data type T having a defined comparison operator (<).
*/
void sort() {
if (data.empty()) {
throw std::runtime_error("Cannot sort an empty array.");
}
// std::sort is efficient and handles various data types correctly.
std::sort(data.begin(), data.end());
}
/**
* @brief Prints the elements of the array to standard output.
* @throws std::runtime_error if the array is empty.
*/
void print() const {
if (data.empty()) {
throw std::runtime_error("Cannot print an empty array.");
}
std::cout << "[";
for (size_t i = 0; i < data.size(); ++i) {
std::cout << data[i] << (i == data.size() - 1 ? "" : ", ");
}
std::cout << "]" << std::endl;
}
/**
* @brief Clears all elements from the array.
*/
void clear() {
data.clear();
}
};
int main() {

// --- Example 1: Sorting integers ---
try {
std::vector<int> int_data = {5, 2, 8, 1, 9};
SortableArray<int> int_array(int_data);
std::cout << "Original integers: ";
int_array.print();
int_array.sort();
std::cout << "Sorted integers: ";
int_array.print();
// Demonstrate exception for empty array after clear
int_array.clear();
int_array.sort(); // This will throw an exception
} catch (const std::runtime_error& e) {
std::cerr << "Caught exception in integer example: " << e.what() << std::endl;
}
std::cout << "--------------------------" << std::endl;
// --- Example 2: Sorting strings ---
try {
std::vector<std::string> string_data = {"banana", "apple", "cherry", "date"};
SortableArray<std::string> string_array(string_data);
std::cout << "Original strings: ";
string_array.print();
string_array.sort();
std::cout << "Sorted strings: ";
string_array.print();
} catch (const std::runtime_error& e) {
std::cerr << "Caught exception in string example: " << e.what() << std::endl;
}
return 0;
}