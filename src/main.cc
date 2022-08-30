#include "grid.hh"
#include "case.hh"
#include "parser.hh"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Grid grid;

    grid.init();

    while (true)
    {
        // Clear the screen
        cout << "\x1B\x5B\x48\x1B\x5B\x32\x4A\x1B\x5B\x33\x4A";
        // Display the current playing grid
        cout << grid.format() << endl;

        // Show the game history
        if (grid.history.size() > 0)
        {
            for (HistoryRecord h : grid.history)
                cout << format_player(h.player) << " played at " << h.format_position() << endl;

            cout << endl;
        }

        if (grid.has_winner())
        {
            cout << "Winner: " << format_player(grid.winner()) << endl;
            break;
        }
        else if (grid.is_full())
        {
            cout << "Draw" << endl;
            break;
        }
        else
        {
            cout << "Player " << format_player(grid.current_player) << " turn" << endl
                 << endl;
        }

        // Ask for position until receive a valid input
        while (true)
        {
            string input;

            cout << "Enter a position (e.g. A2): ";
            cin >> input;

            try
            {
                int *parsed = parse_position(input);

                Case c = grid.query(parsed[0], parsed[1]);

                if (c.player == Player::Empty)
                {
                    Case clone;

                    clone.x = parsed[0];
                    clone.y = parsed[1];
                    clone.player = grid.current_player;

                    grid.update(clone);

                    grid.history.push_back(HistoryRecord(parsed[0], parsed[1], grid.current_player));

                    grid.current_player = opponent(grid.current_player);

                    delete parsed;

                    break;
                }
                else
                {
                    cout << "Error: Position already taken" << endl
                         << endl;
                }

                delete parsed;
            }
            catch (char const *e)
            {
                cout << "Error: " << e << endl
                     << endl;
            }
        }
    }
}
