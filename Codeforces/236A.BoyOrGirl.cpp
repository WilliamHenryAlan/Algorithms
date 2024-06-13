#include <iostream>
int main() {
    std::string str;
    std::getline(std::cin,str);
    char hash[26] = {0};
    for (char c:str)
        if (hash[c - 'a'] == 0) hash[c - 'a']++;
    int sum = 0;
    for (int val:hash) sum += val;
    sum %= 2;
    if (sum == 0) std::cout << "CHAT WITH HER!" << std::endl;
    else std::cout << "IGNORE HIM!" << std::endl;
}
