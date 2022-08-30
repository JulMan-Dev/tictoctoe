#pragma once

#include <string>

using namespace std;

enum class Player
{
    X,
    O,
    Empty    
};

Player opponent(Player p);
string format_player(Player p);

struct Case
{
    Player player;
    int x;
    int y;

    string format();
};
