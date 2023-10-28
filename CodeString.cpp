#include "CodeString.h"

void CodeString::extractCommentsAndStrings() {
    // Регулярные выражения для поиска комментариев и строковых литералов.
    std::regex singleLineCommentRegex("(.*)//");
    std::regex multiLineCommentStartRegex("/\\*");
    std::regex multiLineCommentEndRegex("\\*/");
    std::regex stringLiteralRegex("\"(.*?)\"");

    // Поиск и извлечение однострочных комментариев.
    std::smatch match;
    if (std::regex_search(text, match, singleLineCommentRegex)) {
        singleLineCommentPosition = static_cast<int>(match.position(1));
    }

    // Поиск и извлечение начала многострочных комментариев.
    if (std::regex_search(text, match, multiLineCommentStartRegex)) {
        multiLineCommentStartPosition = static_cast<int>(match.position());
    }

    // Поиск и извлечение конца многострочных комментариев.
    if (std::regex_search(text, match, multiLineCommentEndRegex)) {
        multiLineCommentEndPosition = static_cast<int>(match.position());
    }

    // Поиск и извлечение строковых литералов.
    if (std::regex_search(text, match, stringLiteralRegex)) {
        stringLiteralPosition = static_cast<int>(match.position(1));
    }
}
