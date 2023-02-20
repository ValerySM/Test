#ifndef PROJECT_LEAGUE_H
#define PROJECT_LEAGUE_H


#include "Player.h"
#include "Game.h"
using namespace std;

class Match {
public:
    Match(UserPlayer* p1, UserPlayer* p2, int size) : p1(p1), p2(p2), size(size) {}
    UserPlayer* p1;
    UserPlayer* p2;
    int size;
    int result;
};
class League {
public:
    League(int size) : size(size) {}
    // add a player to the league
    void addPlayer(UserPlayer* player);
    // play all matches in the league
    void playMatches();
    // print the league tree
    void printTree();

private:
    // simulate a match between two players on a board of a specified size
    int playMatch(UserPlayer* p1, UserPlayer* p2, int size) {
        Game game = Game(p1, p2, size);
        game.Run();
        return 0;//TODO
    }

    vector<UserPlayer*> players;
    vector<Match> matches;
    int size;
};
// define a League class to manage the league


#endif //PROJECT_LEAGUE_H
