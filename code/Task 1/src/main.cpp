#include "../include/parser.h"

int main(int argc, char* argv[]) {
    //Executes the default test file or the given argument.
    if(argc == 1){
        cout << "No argument was provided...\n";
        parsefile("test.txt");
    } else {
        parsefile(argv[1]);
    }
    return 0;
}