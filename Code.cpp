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

