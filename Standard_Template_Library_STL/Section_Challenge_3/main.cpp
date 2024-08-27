#include<iostream>
#include<set>
#include<map>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

void display_map(const std::map<std::string, int> &words) {
    std::cout << std::setw(10) << std::left << "Word"
                << std::setw(5) << std::right << "Count" << std::endl;
    std::cout << std::setfill('-') << std::setw(15) << "" << std::endl;

    std::cout << std::setfill(' ');
    for(const auto &elem:words) {
        std::cout << std::setw(10) << std::left << elem.first
                    << std::setw(5) << std::right << elem.second << std::endl;
    }
}

void display_map_set(const std::map<std::string, std::set<int>> &lines) {
    std::cout << std::setw(10) << std::left << "Word"
                << std::setw(20) << std::left << "Line Numbers" << std::endl
                << std::setfill('-') << std::setw(30) << "" << std::endl
                << std::setfill(' ');

    for(auto &elem:lines) {
        std::cout << std::setw(10) << std::left << elem.first
                    << std::left << "[ ";
        for(auto &i:elem.second) {
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
}

std::string clean_string(std::string &str) {
    std::string s{};
    for(auto &ch:str) {
        if(ch == '.' || ch == ',' || ch == ';' || ch == ':') continue;
        else s += ch;
    }
    return s;
}

void part1() {
    std::map<std::string, int> words;

    std::ifstream in_file{"words.txt"};

    if(!in_file) {
        std::cerr << "Error in opening file" << std::endl;
        exit(1);
    }

    std::string line{};
    std::string word{};
    while(std::getline(in_file, line)) {
        std::stringstream ss{line};
        while(ss >> word) {
            word = clean_string(word);
            words[word]++;
        }
    }

    in_file.close();
    display_map(words);
}

void part2() {
    std::map<std::string, std::set<int>> lines;
    std::ifstream in_file{"words.txt"};

    if(!in_file) {
        std::cerr << "Error in opening file" << std::endl;
        exit(1);
    }

    int line_num{};
    std::string line{};
    std::string word{};
    while(std::getline(in_file, line)) {
        line_num++;
        std::stringstream ss{line};

        while(ss >> word) {
            word = clean_string(word);
            lines[word].insert(line_num);
        }
    }

    in_file.close();
    display_map_set(lines);
}

int main() {
    part1();
    // part2();

    return 0;
}