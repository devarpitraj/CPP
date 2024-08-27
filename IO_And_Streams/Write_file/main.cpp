#include<iostream>
#include<fstream>

int main() {
    // std::ofstream out_file {"trunc_output.txt"};  //by default in truncate mode
    // std::ofstream out_file_1 {"app_output.txt", std::ios::app};   //append on each write
    // std::ofstream out_file_2 {"ate_output.txt", std::ios::ate}; //seek to eof

    // if(!out_file) {
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    // if(!out_file_1) {
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    // if(!out_file_2) {
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    // std::string line{};
    // std::cout << "Enter a line :";
    // std::getline(std::cin, line);

    // out_file << line << std::endl;  
    // out_file_1 << line << std::endl;
    // out_file_2 << line << std::endl;

    // out_file.close();

    std::ofstream out_file_poem{"poem_out.txt"};
    std::ifstream in_file_poem{"poem.txt"};

    if(!in_file_poem) {
        std::cerr << "Problem in file opening" << std::endl;
        return 1;
    }

    if(!out_file_poem) {
        std::cerr << "Problem in creating file" << std::endl;
        return 1;
    }

    std::string line{};
    // while(std::getline(in_file_poem, line))
    //     out_file_poem << line << std::endl;
    // std::cout << "File copied" << std::endl;

    char c;
    while(in_file_poem.get(c))
        out_file_poem.put(c);
    std::cout << "File copied" << std::endl;

    in_file_poem.close();
    out_file_poem.close();
    return 0;
}