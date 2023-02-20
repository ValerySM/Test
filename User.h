//
// Created by valery-sm on 2/20/2023.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H


#include "string"
#include "Animal.h"

using namespace std;
class User {
private:
    string username;
    string password;
    int gold;
public:
    int getChamp() const;

private:
    int silver;
    int bronze;
    int score;
    int champ;
    Animal *animal;
public:
    const string &getUsername() const;

    const string &getPassword() const;

    int getGold() const;

    int getSilver() const;

    int getBronze() const;

    int getScore() const;

    Animal *getAnimal() const;
    void increment_score();

    ~User();


public:

    void Register();
    void PrintType();

    User(string name, string password,Animal* animal);
    User(string name, string password, Animal *animal, int gold, int silver, int bronze, int score, int champ);
    User(string csvString);
    User(const User &other);
    User &operator=(const User &other);
    string getAsString();

};

#endif //PROJECT_USER_H
