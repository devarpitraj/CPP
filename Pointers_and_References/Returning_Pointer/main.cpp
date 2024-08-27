#include<iostream>

using namespace std;

int *create_array(int size, int init_value = 0) {
    int *new_storage{nullptr};

    new_storage = new int[size];
    for (size_t i{0}; i < size; i++)
        *(new_storage + i) = init_value;
    
    return new_storage;
}

void display(const int *const array, int size) {
    for(size_t i{0}; i < size; i++)
        cout << *(array + i) << endl;
}

int main() {
    int *my_array {nullptr};
    size_t size {};
    int init_value {};

    cout << "Enter size of array:";
    cin >> size;
    cout << "Enter the initialization value:";
    cin >> init_value;

    my_array = create_array(size, init_value);
    display(my_array, size);

    delete [] my_array;

    return 0;
}