#include "string.h"
#include <cctype>
#include <cstdio>


void clearInputBuffer(void)
{

    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}