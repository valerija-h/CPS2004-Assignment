#ifndef ANIMALS_ANIMALS_H
#define ANIMALS_ANIMALS_H

#include "header.h"

//Animal - base class.
class Animal {
protected:
    string name;
    float length = 0;
public:
    void setName(string name);
    void setLength(float length);
    string getName();
    float getLength();
    virtual string displayAnimal();
    virtual string displayFeatures();
};

//Subclasses of animal - mammal, reptile and bird which are derived from the animal base class.
class Mammal: public Animal{
    int avgLitterSize;
public:
    Mammal(string name, float length, int avgLitterSize);
    //Overridden functions to display animal features.
    string displayAnimal() override;
    string displayFeatures() override;
};

class Reptile: public Animal{
    bool isVenomous;
public:
    Reptile(string name, float length, bool isVenemous);
    string boolToString( bool b );
    //Overridden functions to display animal features.
    string displayAnimal() override;
    string displayFeatures() override;
};

class Bird: public Animal{
    bool canFly;
public:
    Bird(string name, float length, bool canFly);
	string boolToString( bool b );
    //Overridden functions to display animal features.
    string displayAnimal() override;
    string displayFeatures() override;
};

#endif
