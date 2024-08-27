#include<iostream>

using namespace std;

int main() {
    int high_score {100};
    int low_score {10};

    const int *score_ptr1 {&high_score};
    int *const score_ptr2 {&high_score};
    const int *const score_ptr3 {&high_score};

    //*score_ptr1 = 86; //Error const int* means data is constant but pointer's addressing can be changed
    score_ptr1 = &low_score;

    *score_ptr2 = 86;
    //score_ptr2 = &low_score;  //Error int *const means pointer's addressing can't be changed but data can be changed

    //*score_ptr3 = 86; //Error const int *const means both pointer's addressing and data can't be changed
    //score_ptr3 = &low_score;  //Error

    return 0;
}