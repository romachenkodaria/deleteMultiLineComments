#include "CodeString.h"

void CodeString::extractCommentsAndStrings() {
    // ���������� ��������� ��� ������ ������������ � ��������� ���������.
    std::regex singleLineCommentRegex("(.*)//");
    std::regex multiLineCommentStartRegex("/\\*");
    std::regex multiLineCommentEndRegex("\\*/");
    std::regex stringLiteralRegex("\"(.*?)\"");

    // ����� � ���������� ������������ ������������.
    std::smatch match;
    if (std::regex_search(text, match, singleLineCommentRegex)) {
        singleLineCommentPosition = static_cast<int>(match.position(1));
    }

    // ����� � ���������� ������ ������������� ������������.
    if (std::regex_search(text, match, multiLineCommentStartRegex)) {
        multiLineCommentStartPosition = static_cast<int>(match.position());
    }

    // ����� � ���������� ����� ������������� ������������.
    if (std::regex_search(text, match, multiLineCommentEndRegex)) {
        multiLineCommentEndPosition = static_cast<int>(match.position());
    }

    // ����� � ���������� ��������� ���������.
    if (std::regex_search(text, match, stringLiteralRegex)) {
        stringLiteralPosition = static_cast<int>(match.position(1));
    }
}
