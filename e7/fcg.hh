#ifndef FCG_HH
#define FCG_HH

#include <vector>
#include <string>
#include "iloc.hh"

using namespace std;

class FCG {
private:
    vector<int> nodes;
    vector<pair<int, int>> edges;

public:
    void fromILOC(std::vector<ILOC_Code::Command> code);
    void toDOT(string filename);
};


#endif
