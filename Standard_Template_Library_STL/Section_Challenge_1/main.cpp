#include<iostream>
#include<string>
#include<deque>
#include<cctype>
#include<algorithm>
#include<vector>
#include<iomanip>

bool is_palindrome(const std::string &s) {
    std::deque<char> str;
    for(auto ch:s) {
        if(isalpha(ch)) {
            str.push_back(std::toupper(ch));
        }
    }

    char front{};
    char back{};
    while(str.size() > 1) {
        front = str.front();
        back = str.back();
        if(front == back) {
            str.pop_back();
            str.pop_front();
        } else return 0;
    }
    return 1;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;

}