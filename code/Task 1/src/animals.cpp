#include "../include/animals.h"

//Animal - base class.
void Animal::setName(string name){
    this->name = move(name);
}
void Animal::setLength(float length){
    this->length = length;
}
string Animal::getName(){
    return name;
}
float Animal::getLength(){
    return length;
}
//Virtual members - can be redefined in a derived class.
string Animal::displayAnimal(){
    return " ";
}
string Animal::displayFeatures(){
    return " ";
}

//Subclasses of animal - mammal, reptile and bird which are derived from the animal base class.
Mammal::Mammal(string name, float length, int avgLitterSize) {
    this->length = length;
    this->name = move(name);
    this->avgLitterSize = avgLitterSize;
}
//Redefinition of base class function - overridden functions.
string Mammal::displayAnimal(){return "Name:"+name+" Type:Mammal";}
string Mammal::displayFeatures() { return "Name:"+name+" Type:Mammal Length:"+to_string(length)+" Average Litter Size:"+to_string(avgLitterSize)+"";}

Reptile::Reptile(string name, float length, bool isVenemous) {
    this->length = length;
    this->name = move(name);
    this->isVenomous = isVenemous;
}
//Convert a boolean into true or false.
string Reptile::boolToString(bool b) { return b ? "true" : "false";}
//Redefinition of base class function - overridden functions.
string Reptile::displayAnimal() {return "Name:"+name+" Type:Reptile";}
string Reptile::displayFeatures() {return "Name:"+name+" Type:Reptile Length:"+to_string(length)+" Is Venemous:"+boolToString(isVenomous)+"";}

Bird::Bird(string name, float length, bool canFly) {
    this->length = length;
    this->name = move(name);
    this->canFly = canFly;
}
//Convert a boolean into true or false.
string Bird::boolToString(bool b) { return b ? "true" : "false"; }
//Redefinition of base class function - overridden functions.
string Bird::displayAnimal() {return "Name:"+name+" Type:Bird";}
string Bird::displayFeatures() {return "Name:"+name+" Type:Bird Length:"+to_string(length)+" Can Fly:"+boolToString(canFly)+"";}
