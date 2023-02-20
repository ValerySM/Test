
#ifndef PROJECT_ANIMAL_H
#define PROJECT_ANIMAL_H


#include "string"

using namespace std;
class Animal {
public:
    enum class Kind{
        Mammal,
        Fish,
        Insect
    };
    static Animal* createAnimal(const string& type, const string& species);
    virtual string getSpecies() = 0;
    virtual string getType() = 0;
    virtual ~Animal() = default;;
};
class Mammal : public Animal
{
public:
    virtual string getSpecies() = 0;
    string getType();
    virtual ~Mammal() = default;;
};

class Fish : public Animal
{
public:
    virtual string getSpecies() = 0;
    string getType();
    virtual ~Fish()= default;;
};
class Insect: public Animal
{
public:
    virtual string getSpecies() = 0;
    string getType();
    virtual ~Insect()= default;;
};
class Dolphin : public Mammal
{
public:
    string getSpecies();
    ~Dolphin()= default;;
};

class Dog : public Mammal
{
public:
    string getSpecies();
    ~Dog()= default;;
};

class Cat : public Mammal
{
public:
    string getSpecies();
    ~Cat()= default;;
};


class Shark : public Fish
{
public:
    string getSpecies();
    ~Shark()= default;
};

class Barracuda : public Fish
{
public:
    string getSpecies();
    ~Barracuda()= default;
};
class Ant : public Insect
{
public:
    string getSpecies();
    ~Ant()= default;
};
class Grasshopper : public Insect
{
public:
    string getSpecies();
    ~Grasshopper()= default;
};
class Wasp : public Insect
{
public:
    string getSpecies();
    ~Wasp()= default;
};





#endif //PROJECT_ANIMAL_H
