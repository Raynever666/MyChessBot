//.h file for Uci class

#ifndef UCI_H

#define UCI_H

#include <string>
#include <map>

using namespace std;

class Uci {
    public:
        Uci();
        ~Uci();
        void executeCommand(std::string command);
        void loop();
        void processPosition(std::string parameter);
        void processGo(std::string parameter);
        void processStop();

        bool debug = false;

    private:

        const std::map<std::string, int> CommandList = {
            {"uci", 0},
            {"DEBUG", 1},
            {"isready", 2},
            {"ucinewgame", 3},
            {"position", 4},
            {"go", 5},
            {"stop", 6},
            {"quit", 7},
            {"d", 8},
        };
};

#endif