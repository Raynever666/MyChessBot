// UCI handler

// ref: https://github.com/SebLague/Chess-Coding-Adventure/blob/Chess-V2-UCI/Chess-Coding-Adventure/src/EngineUCI.cs

// aims to provide a bare bone UCI interface for the engine

#include "Uci.h"
#include <iostream>
#include <string>

using namespace std;

Uci::Uci() {
    // constructor
    // cout << "Uci constructor" << endl;
}

// read command
void Uci::executeCommand(std::string command) {
    // command list map exist as a constant defined in .h file
    // if command is not found, print error
    // if command is found, execute the command

    // split the command into tokens by " "
    // the first token is the command
    // the rest are the parameters
    string parameter;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = command.find(delimiter)) != string::npos) {
        token = command.substr(0, pos);
        parameter = command.substr(pos + 1, command.length());
        break;
    }
    if (token != ""){
        command = token;
    } 

    // a conversion from string to int(index) is required
    // so that we can use switch case
    int commandIndex = -1;
    try {
        commandIndex = CommandList.at(command);
    } catch (const std::exception &e) {
        // // an unknown command was entered
        // cout << "Unrecognised command !!! Either unsupported or incorrect UCI syntax" << endl;
    }

    // switch case for commandIndex
    switch (commandIndex) {
        case 0:
            // uci
            cout << "id name MyChessEngine(name undecided)" << endl;
            cout << "id author Ray Lai (Raynever666/Raynever123)" << endl;
            cout << "uciok" << endl;
            break;
        case 1:
            // debug
            // internal use only, not compatible with UCI protocol
            break;
        case 2:
            // isready
            cout << "readyok" << endl;
            break;
        case 3:
            // ucinewgame
            // reset the board
            //...
            break;
        case 4:
            // position
            processPosition(parameter);
            break;
        case 5:
            // go
            processGo(parameter);
            break;
        case 6:
            // stop
            processStop();
            break;
        case 7:
            // quit
            exit(0);
            break;
        default:
            // unknown command
            cout << "Unrecognised command !!! Either unsupported or incorrect UCI syntax" << endl;
            break;
    }
}

// process the "position" command
void Uci::processPosition(std::string parameter){
    // position command is followed by a FEN string
    // or "startpos" keyword
    // or "moves" keyword followed by a list of moves

    // process the parameter
    if (parameter.find("startpos") != std::string::npos) {
        // start a new game
        int a = 1;
    } else if (parameter.find("fen") != std::string::npos) {
        // set the board to the FEN string
        int a = 1;
    } else {
        // wrong position command
        int a = 1;
    }

}

// process the "go" command
void Uci::processGo(std::string parameter){
    // go command is followed by a list of parameters
    // such as movetime, wtime, btime, etc.
    // e.g. go movetime 1000
    // e.g. go wtime 1000 btime 1000

    // Check if the parameter contains "movetime"
    if (parameter.find("movetime") != std::string::npos) {

        int a = 1;
        // Extract the value after "movetime"
        size_t pos = parameter.find("movetime");
        std::string value = parameter.substr(pos + 9);

        // Convert the value to an integer
        int movetime = std::stoi(value);

        // Perform the search with the given movetime
        // core.performSearch(movetime);
    } else {
        // Handle other parameters or perform a default search
        int a = 1;
        // core.performSearch();
    }
    
    
}

// process the "stop" command
void Uci::processStop(){
    // stop the search
    int a = 1;
    // core.stopSearch();
}

// main loop
void Uci::loop() {
    // loop
    while (1) {
        // read command from user
        std::string command;
        getline(cin, command);
        executeCommand(command);
    }
}