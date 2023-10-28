#pragma once
#include <string>
#include <regex>

class CodeString
{
public:
    const std::string text;
    int singleLineCommentPosition;
    int multiLineCommentStartPosition;
    int multiLineCommentEndPosition;
    int stringLiteralPosition;

    CodeString(const std::string& text) : text(text),
        singleLineCommentPosition(-1),
        multiLineCommentStartPosition(-1),
        multiLineCommentEndPosition(-1),
        stringLiteralPosition(-1) {
        extractCommentsAndStrings();
    } 

    void extractCommentsAndStrings();
};

