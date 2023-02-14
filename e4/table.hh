#include <stack>
#include <map>
#include "tree.hh"

enum class Kind {
    LITERAL,
    VARIABLE,
    ARRANGE,
    FUNCTION
};

enum class Type {
    INTEGER,
    FLOATING,
    CHARACTER,
    BOOLEAN
};

struct Symbol {
    int line_no;
    Kind kind;
    Type type;
    size_t size;
    Node_p assoc_node;
};

std::stack<std::map<int, Symbol>> symbol_table_stack;