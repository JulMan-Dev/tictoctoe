#include "grid.hh"
#include "case.hh"

#include <string>

using namespace std;

string HistoryRecord::format_position()
{
    string out = "";

    switch (this->x)
    {
    case 0:
        out += "A";
        break;

    case 1:
        out += "B";
        break;

    case 2:
        out += "C";
        break;

    default:
        throw "Invalid position";
    }

    switch (this->y)
    {
    case 0:
        out += "1";
        break;

    case 1:
        out += "2";
        break;

    case 2:
        out += "3";
        break;

    default:
        throw "Invalid position";
    }

    return out;
}

string Grid::format()
{
    string out = "";

    out += "    1   2   3\n";
    out += " A  " + this->cases[0][0].format() + " │ " + this->cases[0][1].format() + " │ " + this->cases[0][2].format() + "\n";
    out += "   ───┼───┼───\n";
    out += " B  " + this->cases[1][0].format() + " │ " + this->cases[1][1].format() + " │ " + this->cases[1][2].format() + "\n";
    out += "   ───┼───┼───\n";
    out += " C  " + this->cases[2][0].format() + " │ " + this->cases[2][1].format() + " │ " + this->cases[2][2].format() + "\n";

    return out;
}

Case Grid::query(int x, int y)
{
    return this->cases[x][y];
}

void Grid::update(Case c)
{
    this->cases[c.x][c.y] = c;
}

void Grid::init()
{
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            this->cases[x][y].player = Player::Empty;

    this->current_player = Player::X;
    this->history = vector<HistoryRecord>();
}

Player Grid::winner()
{
    for (int y = 0; y < 3; y++)
    {
        if (this->cases[0][y].player == this->cases[1][y].player &&
            this->cases[1][y].player == this->cases[2][y].player &&
            this->cases[0][y].player != Player::Empty)
            return this->cases[0][y].player;
    }

    for (int x = 0; x < 3; x++)
    {
        if (this->cases[x][0].player == this->cases[x][1].player &&
            this->cases[x][1].player == this->cases[x][2].player &&
            this->cases[x][0].player != Player::Empty)
            return this->cases[x][0].player;
    }

    if (this->cases[0][0].player == this->cases[1][1].player &&
        this->cases[1][1].player == this->cases[2][2].player &&
        this->cases[0][0].player != Player::Empty)
        return this->cases[0][0].player;

    if (this->cases[0][2].player == this->cases[1][1].player &&
        this->cases[1][1].player == this->cases[2][0].player &&
        this->cases[0][2].player != Player::Empty)
        return this->cases[0][2].player;

    return Player::Empty;
}

bool Grid::has_winner()
{
    return this->winner() != Player::Empty;
}

bool Grid::is_full()
{
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (this->cases[x][y].player == Player::Empty)
                return false;

    return true;
}
