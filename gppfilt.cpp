#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<memory>
#include<stdexcept>
#include<array>
#include<stdlib.h>

#include"patterns.hpp"

// https://stackoverflow.com/a/24315631/14639101
std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main(int argc, char** argv) {
    //int previous = atoi(exec("echo \"${PIPESTATUS[0]}\"").c_str());
    //std::cout<<previous<<std::endl;
    std::vector<std::string> lines = {};

    std::string s;

    while (getline(std::cin, s))
        lines.push_back(s);

    int ln = -1;

    for (std::string& line : lines) {
        for (const std::vector<std::string>& pattern : pattern::rpatterns) {
            //std::regex  re          (pattern.first);
            std::string original = pattern[0];
            std::string replacement = pattern[1];

            //std::replace(line.begin(), line.end(), original.c_str(), replacement.c_str());

            line = replaceAll(line, original, replacement);

            //std::regex_replace(line, re, replacement);
        }
        ln++;
        lines[ln] = line;
    }

    ln = -1;

    for (std::string& line : lines) {
        for (const std::vector<std::string>& pattern : pattern::cpatterns) {
            //std::regex  re          (pattern.first);
            std::string original = (pattern[0]);
            std::string replacement = (pattern[1] + pattern[0] + "\033[0m");

            //std::replace(line.begin(), line.end(), original.c_str(), replacement.c_str());

            line = replaceAll(line, original, replacement);

            //std::regex_replace(line, re, replacement);
        }
        ln++;
        lines[ln] = line;
    }

    for (std::string& line : lines) {
        std::cout << line << std::endl;
    }

    //return previous;
}