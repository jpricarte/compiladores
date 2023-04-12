#ifndef FCG_HH
#define FCG_HH

#include <vector>
#include <string>
#include "iloc.hh"

class FCG {
private:
    vector<int> nodes;
    vector<pair<int, int>> edges;

public:
    void fromILOC(ILOC_Code::CodeElement);
    string toDOT();
};


#endif
