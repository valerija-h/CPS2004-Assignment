#include "../include/parser.h"


void parsefile(string fileName){
    //Opening a file for reading using filename and returning if it can't be open.
    ifstream file(fileName);
    if(!file) { cerr << "Cannot open input file.\n"; return; }

    //Declaring an object of a the tree class that will store pointers to the animal class.
    Tree<Animal *> tree;

    //Reading and executing the file line by line.
    string line;
    while (getline(file, line)) {
        //Remove /r from end of line.
        if(line[line.size() - 1] == '\r'){
            line.resize(line.size()-1);
        }
	//If the current line is empty, continue reading the next line.
        if(line.empty()){ continue;}
        //Get the first argument in the line.
        string token = line.substr(0,line.find(' '));
        //Check whether the first argument is Insert, Find or Remove.
        if(token == "Insert"){
            //Tokenizes the string and checks there's a correct number of arguments.
            vector<string> tokens = getTokens(line);
            if(tokens.size() != 5){ throw invalid_argument("Invalid number of arguments.");}
            //Checks the type of animal to be inserted into the tree.
            if(tokens[1] == "mammal"){
                Animal *animal = getMammal(tokens);
                tree.insertNode(animal);
                continue;
            } else if (tokens[1] == "reptile"){
                Animal *animal = getReptile(tokens);
                tree.insertNode(animal);
                continue;
            } else if (tokens[1] == "bird"){
                Animal *animal = getBird(tokens);
                tree.insertNode(animal);
                continue;
            } else {
                throw invalid_argument("Can't recoginze command. " + tokens[1]);
            }
        } else if (token == "Find"){
            //Tokenizes the string and checks there's a correct number of arguments.
            vector<string> tokens = getTokens(line);
            if(tokens.size() != 2){ throw invalid_argument("Invalid number of arguments.");}
            //Checks if the animal exists in the tree.
            if(tree.findNode(tree.getRoot(),tokens[1]) == nullptr){
                cerr << "Could not find the animal " + tokens[1] + "\n";
            } else {
                //Displays information about the animal.
                cout << "Found the animal " + tokens[1] + ": ";
                cout << tree.findNode(tree.getRoot(),tokens[1])->displayFeatures() + "\n";
            }
        } else if (token == "Remove"){
            //Tokenizes the string and checks there's a correct number of arguments.
            vector<string> tokens = getTokens(line);
            if(tokens.size() != 2){ throw invalid_argument("Invalid number of arguments.");}
            //Checks if the animal exists in the tree, if it does, deletes the node using the found node.
            if(tree.findNode(tree.getRoot(),tokens[1]) == nullptr){
                cerr << "Could not find and delete the animal " + tokens[1] + "\n";
            } else {
                tree.deleteNode(tree.findNode(tree.getRoot(),tokens[1])->getAnimal());
            }
        } else {
            throw invalid_argument("Command not recognized. " + token);
        }
    }
    //If no nodes were inputted, notifies the user that the tree is empty, otherwise prints the inorder traversal of the tree.
    if(tree.getRoot() == nullptr){
        cerr << "Tree is empty - No nodes to display inorder traversal of the tree.\n";
    } else {
        cout << "End of file reached - Printing inorder traversal of the tree...\n";
        tree.inOrder(tree.getRoot());
    }
}

//Given a string of argument tokens, returns an object of Mammal class.
Mammal* getMammal(vector<string> tokens){
    float length = 0;
    int avgLitterSize = 0;
    //Tries to convert the animal length and litter size into a float and integer variable respectively.
    try {
        length = stof(tokens[3]);
        avgLitterSize = stoi(tokens[4]);
    } catch (const invalid_argument &ia) { cerr << "Invalid argument: " << ia.what() << '\n'; }
    //Create a new object of Mammal class using arguments.
    Mammal *mammal = new Mammal(tokens[2], length, avgLitterSize);
    return mammal;
}

//Given a string of argument tokens, returns an object of Reptile class.
Reptile* getReptile(vector<string> tokens){
    float length = 0;
    bool isVenomous;
    //Tries to convert the animal length into a float variable.
    try{
        length = stof(tokens[3]);
    } catch (const invalid_argument &ia) { cerr << "Invalid argument: " << ia.what() << '\n'; }
    //Tries to identify whether the animal is venomous or non-venomous.
    if(tokens[4] == "venomous"){
        isVenomous = true;
    } else if (tokens[4] == "non-venomous"){
        isVenomous = false;
    } else { throw invalid_argument("Can't read command :" + tokens[4]); }
    //Create a new object of Reptile class using arguments.
    Reptile *reptile = new Reptile(tokens[2], length, isVenomous);
    return reptile;
}

//Given a string of argument tokens, returns an object of Bird class.
Bird* getBird(vector<string> tokens){
    float length = 0;
    bool canFly;
    //Tries to convert the animal length into a float variable.
    try{
        length = stof(tokens[3]);
    } catch (const invalid_argument &ia) { cerr << "Invalid argument: " << ia.what() << '\n'; }
    //Tries to identify whether the animal can fly or not.
    if(tokens[4] == "can-fly"){
        canFly = true;
    } else if (tokens[4] == "cannot-fly"){
        canFly = false;
    } else { throw invalid_argument("Can't read command :"  + tokens[4]); }
    //Create a new object of Bird class using arguments.
    Bird *bird = new Bird(tokens[2], length, canFly);
    return bird;
}

//Splitting a string into tokens by ' ' character.
vector<string> getTokens(string line){
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while(getline(ss,token,' ')){
            tokens.push_back(token);
    }
    return tokens;
}

