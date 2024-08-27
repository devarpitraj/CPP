#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

int main() {
    std::ifstream in_file;
    in_file.open("test.txt");

    if(!in_file) {
        std::cerr << "File opening error" << std::endl;
        return 1;
    }

     std::string line{};

    // std::getline(in_file, line);
    // std::cout << line << std::endl;

     char c;
    // in_file.get(c);
    // std::cout << c << std::endl;

    // while(!in_file.eof()) {
    //     in_file >> line;
    //     std::cout << line << std::endl;
    // }

    // while(in_file >> line) {
    //     std::cout << line << std::endl;
    // }

    int num{};
    double total{};

    // while(in_file >> line >> num >> total) {
    //     std::cout << std::setw(10) << std::left << line 
    //                 << std::setw(10) << num 
    //                 << std::setw(10) << total << std::endl;
    // }

    // test.txt :-
    //     Hello 
    //     100.22
    //     213
    // int num read 100.22 as int and stored 100,
    // double total read 0.22 as double and stored it
    // after that 
    // string line read 213 
    // but num read nothing so it returned false and while conditionn got falsed
    //OUTPUT :-
    //Hello     100       0.22 


    // while(!in_file.eof()) {
    //     in_file >> line >> num >> total;
    //     std::cout << std::setw(10) << std::left << line 
    //                  << std::setw(10) << num 
    //                  << std::setw(10) << total << std::endl; 
    // }

    // test.txt :-
    //     Hello 
    //     100.22
    //     213
    // now here we looped till end of file
    // thus, 
    // string line read Hello
    // int num read 100
    // double total read 0.22
    // string line read 213
    // and eof reached
    //OUTPUT :-
    //Hello     100       0.22      213       100       0.22 

    in_file.close();

    in_file.open("poem.txt");
    // while(std::getline(in_file, line))
    //     std::cout << line << std::endl;
    // std::cout << std::endl;

    while(in_file.get(c))
        std::cout << c;
    std::cout << std::endl;

    in_file.close();

    return 0;
}