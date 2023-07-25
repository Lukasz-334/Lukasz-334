#include <iostream>
#include <stack>
#include <string>
 
bool checkingBracketing(const char& sign) {
    return (sign == '(' || sign == '[' || sign == '{' || sign == '<');
}
 
std::string bracketing(const std::string& str) {
    std::stack<char> stack;
    for (const auto& c : str) {
        if (checkingBracketing(c)) {
            stack.push(c);
        } else if ((stack.empty()) || (c == ')' && stack.top() != '(') || (c == ']' && stack.top() != '[') || (c == '}' && stack.top() != '{') || (c == '>' && stack.top() != '<')) {
            return "Nie";
        } else {
            stack.pop();
        }
    }
 
    if (stack.empty()) {
        return "Tak";
    }
    return "Nie";
}
 
int main() {
    std::string str;
    std::cin >> str;
    std::cout << bracketing(str);
 
    return 0;
}
 
