#include "Code.h"

// TODO: функция определения начала/конца комментария
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
