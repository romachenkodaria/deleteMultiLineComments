#pragma once
#include <string>
#include <regex>

class CodeString
{
public:
    std::string text;
    int singleLineCommentPosition;
    int multiLineCommentStartPosition;
    int multiLineCommentEndPosition;
    int stringStartLiteralPosition;
    int stringEndLiteralPosition;

    CodeString(const std::string& text) : text(text),
        singleLineCommentPosition(-1),
        multiLineCommentStartPosition(-1),
        multiLineCommentEndPosition(-1),
        stringStartLiteralPosition(-1),
        stringEndLiteralPosition(-1) {
        extractCommentsAndStrings();
    } 

    void extractCommentsAndStrings();

    bool containsStartOfMultiLineComment();

    bool containsEndOfMultiLineComment();
};

