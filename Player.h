

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include "vector"
#include "string"
#include "User.h"
using namespace std;
struct Move{
    int row, col;
};

class Player {

public:
    virtual string getGameName() = 0;
    virtual Move getNextMove(vector<vector<char>>, char curPlayer) = 0;
    virtual ~Player();
};

class UserPlayer: public Player{
    User* user;
public:
    User *getUser() const;

public:
    UserPlayer(User* user);
    Move getNextMove(vector<vector<char>>, char curPlayer);
    virtual string getGameName();
    UserPlayer(const UserPlayer& other);
    UserPlayer& operator=(const UserPlayer& other);
    void increment_score();
    virtual ~UserPlayer();
};



#endif //PROJECT_PLAYER_H
