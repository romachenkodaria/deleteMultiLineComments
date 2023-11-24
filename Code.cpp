#include "Code.h"


int Code::commentOpeningPos()
{
	int pos = -1;
	int i = 0;
	while (pos == -1 && i < codeStrings.size())
	{
		if (codeStrings[i].containsStartOfMultiLineComment())
			pos = i;
		i++;
	}
	return pos;
}

int Code::commentClosingPos()
{
	int pos = -1;
	int i = commentOpeningPos();
	while (pos == -1 && i < codeStrings.size())
	{
		if (codeStrings[i].containsEndOfMultiLineComment())
			pos = i;
		i++;
	}
	return pos;
}

void Code::removeComment(int start, int end)
{
	if (start < end) {
		codeStrings[start].text.erase(codeStrings[start].multiLineCommentStartPosition);
		codeStrings[end].text.erase(0, codeStrings[end].multiLineCommentEndPosition + 2);
		codeStrings.erase(codeStrings.begin() + 1 + start, codeStrings.begin() + end);
	}
	else if (start == end)
		codeStrings[start].text.erase(codeStrings[start].multiLineCommentStartPosition, codeStrings[start].multiLineCommentEndPosition + 2 - codeStrings[start].multiLineCommentStartPosition);
	codeStrings[start] = CodeString(codeStrings[start].text);
	codeStrings[end] = CodeString(codeStrings[end].text);
}

void Code::removeMultiLineComments()
{
	if (commentOpeningPos() != -1)
		while (commentOpeningPos() != -1)
		{
			removeComment(commentOpeningPos(), commentClosingPos());
		}
}

