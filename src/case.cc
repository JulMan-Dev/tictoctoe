#include "case.hh"
#include <string>

using namespace std;

string Case::format()
{
    switch (player)
    {
    case Player::X:
        return "X";
    case Player::O:
        return "O";
    case Player::Empty:
        return " ";
    }

    return "";
}

Player opponent(Player p)
{
    switch (p)
    {
    case Player::X:
        return Player::O;
    case Player::O:
        return Player::X;
    case Player::Empty:
        return Player::Empty;
    }

    return Player::Empty;
}

string format_player(Player p)
{
    switch (p)
    {
    case Player::X:
        return "X";
    case Player::O:
        return "O";
    case Player::Empty:
        return " ";
    }

    return "";
}
