#include "User.h"
#include <sstream>
#include "iostream"
std::string replaceCommasWithSpaces(const std::string& inputString);
User::User(string name, string password, Animal* animal) :gold(0),silver(0),bronze(0),score(0),champ(0)
{
    this->username=name;
    this->password=password;
    this->animal=animal;
}

User::User(string name, string password, Animal *animal, int gold, int silver, int bronze, int score, int champ)
{
    this->username=name;
    this->password=password;
    this->animal=animal;
    this->gold=gold;
    this->silver=silver;
    this->bronze=bronze;
    this->score=score;
    this->champ=champ;
}

string User::getAsString() {
    stringstream s;
    int a;
    s<<username<<
     ","<<password<<
     ","<<gold<<
     ","<<silver<<
     ","<<bronze<<
     ","<<score<<
     ","<<champ<<
     ","<<animal->getType()<<
     ","<<animal->getSpecies();
    return s.str();
}

User::User(const string csvString) {
    string stringWithSapceses = replaceCommasWithSpaces(csvString);
    stringstream inputStream(stringWithSapceses);
    string animalType, animalSpecies;
    inputStream>>username>>
               password>>
               gold>>
               silver>>
               bronze>>
               score>>
               champ>>
               animalType>>
               animalSpecies;

    this->animal = Animal::createAnimal(animalType, animalSpecies);
    //cout<<(void*)animal;
}

const string &User::getUsername() const {
    return username;
}

const string &User::getPassword() const {
    return password;
}

int User::getGold() const {
    return gold;
}

int User::getSilver() const {
    return silver;
}

int User::getBronze() const {
    return bronze;
}

int User::getScore() const {
    return score;
}

Animal *User::getAnimal() const {
    return animal;
}

User::~User() {
    delete animal;
}

User::User(const User &other) : username(other.username), password(other.password), gold(other.gold),
                                silver(other.silver), bronze(other.bronze), score(other.score), champ(other.champ) {
    if (other.animal) {
        animal = Animal::createAnimal(other.animal->getType(), other.animal->getSpecies());
    } else {
        animal = nullptr;
    }
}

User &User::operator=(const User &other) {
    if (this != &other) {
        // copy primitive data members
        username = other.username;
        password = other.password;
        gold = other.gold;
        silver = other.silver;
        bronze = other.bronze;
        score = other.score;
        champ = other.champ;
        // copy Animal object
        if (other.animal) {
            if (animal) {
                delete animal;
            }
            animal = Animal::createAnimal(other.animal->getType(), other.animal->getSpecies());
        } else {
            animal = nullptr;
        }
    }
    return *this;
}

int User::getChamp() const {
    return champ;
}

void User::increment_score() {
    score++;
    //TODO write change to file
}


std::string replaceCommasWithSpaces(const std::string& inputString) {
    std::string outputString = inputString;
    std::replace(outputString.begin(), outputString.end(), ',', ' ');
    return outputString;
}