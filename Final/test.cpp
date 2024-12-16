#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>


std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }
    return str.substr(first, last - first + 1);
}

int main() {
    std::ifstream file("reference.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open reference.txt" << std::endl;
        return 1;
    }

    
    std::map<int, std::string> references;
    std::string line;

    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        std::string source;
        if (iss >> number) {
            std::getline(iss, source);
            references[number] = trim(source);
        }
    }
    file.close();

    
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> query_numbers;
    std::string temp;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '[') {
            temp = "";
        } else if (input[i] == ']') {
            query_numbers.push_back(std::atoi(temp.c_str()));
        } else {
            temp += input[i];
        }
    }

    
    for (size_t i = 0; i < query_numbers.size(); ++i) {
        int ref_num = query_numbers[i];
        if (references.find(ref_num) != references.end()) {
            std::cout << "[" << ref_num << "] " << references[ref_num] << std::endl;
        } else {
            std::cout << "[" << ref_num << "] Unknown" << std::endl;
        }
    }

    return 0;
}