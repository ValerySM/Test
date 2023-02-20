
#include "Animal.h"
#include "Animal.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Animal* Animal::createAnimal(const string& type, const string& species) {
    Animal* animal;
    if (type == "Mammal")
    {
        if (species == "Dolphin")
        {
            animal = new Dolphin();
        }
        else if (species == "Dog")
        {
            animal = new Dog();
        }
        else if (species == "Cat")
        {
            animal = new Cat();
        }
        else
        {
            return nullptr;
        }
    }
    else if (type == "Fish")
    {
        if (species == "Shark")
        {
            animal = new Shark();
        }
        else if (species == "Barracuda")
        {
            animal = new Barracuda();
        }
        else
        {
            return nullptr;
        }
    }

    if (type == "Insect")
    {

        if (species == "Ant")
        {
            animal = new Ant();
        }
        else if (species == "Grasshopper")
        {
            animal = new Grasshopper();
        }
        else if (species == "Wasp")
        {
            animal = new Wasp();
        }
        else
        {
            return nullptr;
        }
    }

    return animal;
}

string Mammal::getType() {
    return "Mammal";
}

string Dolphin::getSpecies() {
    return "Dolphin";
}

string Dog::getSpecies() {
    return "Dog";
}

string Cat::getSpecies() {
    return "Cat";
}

string Fish::getType() {
    return "Fish";
}


string Insect::getType() {
    return "Insect";
}

string Grasshopper::getSpecies() {
    return "Grasshopper";
}

string Barracuda::getSpecies() {
    return "Barracuda";
}

string Wasp::getSpecies() {
    return "Wasp";
}

string Ant::getSpecies() {
    return "Ant";
}

string Shark::getSpecies() {
    return "Shark";
}
