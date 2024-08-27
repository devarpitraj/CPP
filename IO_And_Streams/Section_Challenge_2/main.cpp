#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

int main() {
    std::ifstream in_file;
    in_file.open("responses.txt");

    if(!in_file) {
        std::cerr << "Problem in file opening" << std::endl;
        return 1;
    }

    std::string answer_key{};
    std::string line{};
    std::string copy{};
    std::vector<std::string> students;
    std::vector<std::string> answers;

    std::getline(in_file, answer_key);
    //std::cout << answer_key << std::endl;

    bool i{true};
    while(std::getline(in_file, line)) {
        copy = line;
        if(i) {
            students.push_back(copy);
            i = false;
        }
        else {
            answers.push_back(copy);
            i = true;
        }
    }

    // for(auto i:student)
    //     std::cout << i << std::endl;
    // for(auto i:answer)
    //     std::cout << i << std::endl;

    std::vector<int> marks;
    for(auto answer:answers) {
        int count{};
        for(size_t i = 0; i < 5; i++) {
            if(answer[i] == answer_key[i]) count++;
        }
        marks.push_back(count);
    }
    
    // for(auto i:marks)
    //     std::cout << i << std::endl;
    
    const int total_width{40};
    const int field1_width{20}; //student
    const int field2_width{20}; //score

    std::cout << std::setw(field1_width) << std::left << "Student"
                << std::setw(field2_width) << std::right << "Score" << std::endl
                << std::setw(total_width) << std::setfill('-')<< ""
                << std::endl;
    std::cout << std::setfill(' ');

    for(size_t i = 0; i < marks.size(); i++) {
        std::cout << std::setw(field1_width) << std::left << students[i]
                    << std::setw(field2_width) << std::right << marks[i]
                    << std::endl;
    }
    std::cout << std::setw(total_width) << std::setfill('-')<< ""
                << std::endl;
    std::cout << std::setfill(' ');

    int sum{};
    for(auto i:marks) {
        sum += i;
    }
    double average = static_cast<double>(sum) / marks.size();

    std::cout << std::setw(field1_width) << std::left << "Average Score"
                << std::setw(field2_width) << std::right << average << std::endl;

    return 0;
}