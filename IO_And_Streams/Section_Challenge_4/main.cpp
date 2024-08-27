#include<iostream>
#include<fstream>
#include<string>

int main() {
    std::ifstream in_file;
    std::ofstream out_file;

    in_file.open("romeoandjuliet.txt");
    out_file.open("copy.txt");

    if(!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    if(!out_file) {
        std::cerr << "Problem creating file" << std::endl;
        return 1;
    }

    std::string line{};
    int i{1};
    while(std::getline(in_file, line)) {
        if(line == "") out_file << std::endl;
        else
            out_file << i++ << "\t" << line << std::endl;
    }
    std::cout << "File copied" << std::endl;

    return 0;
}