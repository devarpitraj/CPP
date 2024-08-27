#include<iostream>

using namespace std;

int *apply_all(int array1[], int size1, int array2[], int size2) {
    int *new_array {nullptr};
    new_array = new int[size1*size2];
    int k{0};
    for(size_t i{0}; i < size1 * size2; i++) {
        *(new_array + i) = 0;
    }
    for(size_t i{0}; i < size2; i++) {
        for(size_t j{0}; j < size1; j++) {
            new_array[k++] = *(array1 + j) * *(array2 + i);
        }
    }

    return new_array;
}

void print (int array[], int size) {
    cout << "[ ";
    for(size_t i{0}; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "]";
    cout << endl;
}

int main() {
    int array1[5] {1, 2, 3, 4, 5};
    int array2[3] {10, 20, 30};

    int *results = apply_all(array1, 5, array2, 3);

    print(array1, 5);
    print(array2, 3);
    print(results, 15);

    return 0;
}