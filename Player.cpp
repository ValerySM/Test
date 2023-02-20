#include "Player.h"
#include "iostream"
#include "sstream"
#include "Game.h"
Move UserPlayer::getNextMove(vector<vector<char>>, char curPlayer) {
    int row, col;
    cin >> row >> col;
    return Move{row,col};
}

string UserPlayer::getGameName() {
    stringstream gameName;
    gameName<<user->getUsername()<<'('<<user->getAnimal()->getSpecies()<<')';
    if (user->getChamp()>0)
        gameName<<" "<<"Champ "<<user->getChamp();
    return gameName.str();
}

UserPlayer::UserPlayer(User* user) {
    this->user = new User(*user);
}

UserPlayer::~UserPlayer()
{
    delete user;
}

UserPlayer::UserPlayer(const UserPlayer& other) {
    user = new User(*other.user);
}

UserPlayer& UserPlayer::operator=(const UserPlayer& other) {
    if (this != &other) {
        delete user;
        user = new User(*other.user);
    }
    return *this;
}

void UserPlayer::increment_score() {
    user->increment_score();
}

User *UserPlayer::getUser() const {
    return user;
}

Player::~Player() = default;

