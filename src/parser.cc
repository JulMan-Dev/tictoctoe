#include "parser.hh"

#include <string>

using namespace std;

int *parse_position(string position)
{
    int *re = new int[2];

    if (position.length() != 2)
        throw "Invalid position";

    char first = position[0];

    switch (first)
    {
    case 'A':
        re[0] = 0;
        break;

    case 'B':
        re[0] = 1;
        break;

    case 'C':
        re[0] = 2;
        break;

    default:
        throw "Invalid position";
    }

    char second = position[1];

    switch (second)
    {
    case '1':
        re[1] = 0;
        break;

    case '2':
        re[1] = 1;
        break;

    case '3':
        re[1] = 2;
        break;

    default:
        break;
    }

    return re;
}