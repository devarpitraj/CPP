#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
#include<queue>

bool is_palindrome(const std::string &s) {
    std::stack<char> stack;
    std::queue<char> queue;
    for(auto &ch:s) {
        if(isalpha(ch)) {
            stack.push(std::toupper(ch));
            queue.push(std::toupper(ch));
        }
    }

    char top{};
    char front{};

    while(!stack.empty()) {
        top = stack.top();
        front = queue.front();

        stack.pop();
        queue.pop();
        
        if(top != front) return false;
    }

    return true;
}

int main() {
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