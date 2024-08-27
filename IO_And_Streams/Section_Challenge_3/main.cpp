#include<iostream>
#include<fstream>
#include<string>

bool find_substring(const std::string &word, const std::string &search) {
    size_t found = word.find(search);
    if(found == std::string::npos) return false;
    else return true;
}

int main() {
    std::ifstream in_file {"romeoandjuliet.txt"};

    if(!in_file) {
        std::cerr << "Problem in opening file" << std::endl;
        return 1;
    }

    std::string word{};

    int count{};
    while(in_file >> word) {
        count++;
    }
    //std::cout << count << std::endl;

    std::string search{};
    std::cout << "Enter a word to be searched: ";
    //std::getline(std::cin, search);
    std::cin >> search;

    int got{};
    while(in_file >> word) {
        // std::size_t found = word.find(search);
        // if(found != std::string::npos) {
        //     got++;
        // }

        if(find_substring(word, search)) {
            ++got;
            std::cout << word << " ";
        }


    }

    std::cout << got << std::endl;

    // std::cout << count << " words searched...." << "\n"
    //             << search << " is found " << got << " times." << std::endl;

    return 0;
}

//not working don't know why but the code is absolutely correct

//Frank's code:-
// // return true if the string word_to_find is in the target string
// bool find_substring(const std::string &word_to_find, const std::string &target) {
//     std::size_t found = target.find(word_to_find);
//     if (found == std::string::npos)
//         return false;
//     else
//         return true;
// }

// int main() {
//     std::ifstream in_file {};
//     std::string word_to_find {};
//     std::string word_read {};
//     int word_count {0};
//     int match_count {0};
    
//     in_file.open("../romeoandjuliet.txt");
//      if (!in_file) {
//         std::cerr << "Problem opening file" << std::endl;
//         return 1;
//     }
   
//     std::cout << "Enter the substring to search for: ";
//     std::cin >> word_to_find;
//     while (in_file >> word_read) {
//         ++word_count;
//         if (find_substring(word_to_find, word_read)) {
//            ++match_count;
//            std::cout << word_read << " ";
//         }        
//     }

//     std::cout << word_count << " words were searched..." << std::endl;
//     std::cout << "The substring " << word_to_find << " was found " << match_count << " times " << std::endl;
    
//     in_file.close();
//     std::cout << std::endl;
//     return 0;
// }
