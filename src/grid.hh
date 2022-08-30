#pragma once

#include "case.hh"

#include <string>
#include <vector>

using namespace std;

struct HistoryRecord
{
    int x;
    int y;
    Player player;

    inline HistoryRecord(int x, int y, Player player)
    {
        this->x = x;
        this->y = y;
        this->player = player;
    }

    string format_position();
};

struct Grid
{
    Case cases[3][3];
    vector<HistoryRecord> history;
    Player current_player;

    string format();
    Case query(int x, int y);
    void update(Case c);
    void init();

    Player winner();
    bool has_winner();
    bool is_full();
};
