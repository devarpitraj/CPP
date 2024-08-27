#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> vector1;
    vector <int> vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    cout << "Vector1 elements:" << vector1.at(0) << " " << vector1.at(1) << endl;
    cout << "Size of vector1:" << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);
    cout << "Vector2 elements:" << vector2.at(0) << " " << vector2.at(1) << endl;
    cout << "Size of vector2:" << vector2.size() << endl;

    vector <vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << "Elements in vector_2d are:\n" << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;

    cout << "Elements in vector_2d are:\n" << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    cout << "Vector1 elements:" << vector1.at(0) << " " << vector1.at(1) << endl;
    
    return 0;
}