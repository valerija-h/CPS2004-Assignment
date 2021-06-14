#ifndef ANIMALS_PARSER_H
#define ANIMALS_PARSER_H

#include "header.h"
//Including animal and tree object definitions.
#include "animals.h"
#include "tree.h"
#include "../src/tree.cpp"

void parsefile(string fileName);
Mammal* getMammal(vector<string> tokens);
Reptile* getReptile(vector<string> tokens);
Bird* getBird(vector<string> tokens);
vector<string> getTokens(string line);

#endif
