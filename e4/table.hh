#ifndef TABLE_HH
#define TABLE_HH
#include <map>
#include <vector>
#include "tree.hh"

enum class Kind {
    LITERAL,
    VARIABLE,
    ARRANGE,
    FUNCTION
};

struct Symbol {
    int line_no;
    Kind kind;
    Type type; // Declarado em tree.hh
    size_t size;
    Node_p assoc_node;
};

typedef std::map<TokenVal, Symbol&> SymbolTable;

Type type_infer (Type symbol_1, Type symbol_2);

struct SymbolTableStack {;
    /*
     *  - função para buscar simbolo na pilha (getsymboltable): varre a pilha de cima para baixo procurando um simbolo
     *
     */
public :
    // funções para manipular stack;
    inline void push(SymbolTable& st) {
        this->stack.push_back(st);
    };
    inline void push_new() {
        this->stack.push_back(SymbolTable{});
    };
    inline void pop() {
        this->stack.pop_back();
    }; // deleta tabela de cima
    inline SymbolTable& top() {
        return this->stack.back();
    }; // retorna a table mais de cima
    int findSymbolTable(int key); // retorna indice na stack ou -1
private:
    std::vector<SymbolTable> stack;
};
// note https://cplusplus.com/reference/vector/vector/


#endif // TABLE_HH