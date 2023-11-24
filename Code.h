#pragma once
#include <vector>
#include "CodeString.h"

class Code {
public:
    std::vector<CodeString> codeStrings;

    Code(const std::vector<std::string>& lines) {
        for (const std::string& line : lines) {
            codeStrings.emplace_back(line.c_str());
        }
    }


    int commentOpeningPos();

    int commentClosingPos();

};

