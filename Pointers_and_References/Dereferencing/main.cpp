#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int score{100};
    int *score_ptr{&score};

    cout << "*score_ptr = " << *score_ptr << endl;

    *score_ptr = 200;
    cout << "*score_ptr = " << *score_ptr << endl;
    cout << "score = " << score << endl;

    cout << endl << endl;
    string name {"Frank"};
    string *name_ptr{&name};

    cout << "*name_ptr = " << *name_ptr << endl;
    
    name = "James";
    cout << "*name_ptr = " << *name_ptr << endl;
    
    cout << endl << endl;
    vector<string> vec {"Larry", "Moe", "Curly"};
    vector<string> *vec_ptr{nullptr};

    vec_ptr = &vec;

    cout << "vec[1] = " << (*vec_ptr).at(1) << endl;

    cout << "Printing all elements of vec:" << endl;
    for(auto s:*vec_ptr)
        cout << s << endl;

    cout << endl << endl;
    
    return 0;
}