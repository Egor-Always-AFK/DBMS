#include <iostream>
#include <random>
#include <algorithm>


#define MAX_ARRAY 100
#define MIN_ARRAY 0


/**
 * Set numbers in a array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void fillArrayRandom(int *array, const int size);

/**
 * Get numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void printArray(const int *array, const int size);

/**
 * Get bubble sorting of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void bubbleSort(int *array, const int size);

/**
 * Get min numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int findMin(const int *array, const int size);

/**
 * Get max numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int findMax(const int *array, const int size);



int main(int argc, char** argv) {
    int size;

    std::cout << "Enter size of array: ";
    std::cin >> size;
    
    if (size <= 0) {
        std::cout << "Error!\nThe size of the array must be greater than 0!\nTry again!";
        std::cin >> size;
    }

    int *array = new int[size];
    fillArrayRandom(array, size);
    
    printArray(array, size);

    bubbleSort(array, size);
    std::cout << "Array after sort algo:\n";
    printArray(array, size);

    std::cout << "Min element in array: " << findMin(array, size) << "\nMax element in array: " << findMax(array, size);
}

void fillArrayRandom(int *array, int size) {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> uniformIntDistribution(MIN_ARRAY, MAX_ARRAY);

    for(std::size_t iter = 0; iter < size; iter++) 
        array[iter] = uniformIntDistribution(generator);
}

void printArray(const int *array, const int size) {
    std::cout << "Array: [ ";
    for (std::size_t iter = 0; iter < size - 1; iter++) {
        std::cout << array[iter] << ", ";
    }
    std::cout << array[size - 1] << "]\n";
}

void bubbleSort(int *array, const int size) {
    for (std::size_t i = 0; i < size; i++)
        for (std::size_t j = 0; j < size - i; j++) 
            if (array[j] > array[j + 1]) 
                std::swap(array[j], array[j + 1]);
}


int findMin(const int *array, const int size) {
    int min = array[0];
    for (std::size_t i = 0; i < size; i++)
        if (array[i] < min)
            min = array[i];
    
    return min; 
}

int findMax(const int *array, const int size) {
    int max = array[0];
    for (std::size_t i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}