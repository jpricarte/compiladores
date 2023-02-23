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
    Type type;
    size_t size;
    Node_p assoc_node;
};

typedef std::map<int, Symbol&> symbol_table;

// todo Type type_infer (symb_1, symb_2)


Type type_infer (Type symbol_1, Type symbol_2) {
/*
 *  Dado dois simbolos, faz inferência e retorna o tipo.
 */

    if (symbol_1 == symbol_2) {
        if (symbol_1 == Type::INTEGER)
            return Type::INTEGER;
        if (symbol_1 == Type::FLOATING)
            return Type::FLOATING;
        if (symbol_1 == Type::BOOLEAN)
            return Type::BOOLEAN;
    }

    if (symbol_1 == Type::FLOATING || symbol_2 == Type::FLOATING)
        return Type::FLOATING;

    if (symbol_1 == Type::INTEGER || symbol_2 == Type::INTEGER)
        return Type::INTEGER;
}

struct SymbolTableStack {;
    /*
     *  - função para buscar simbolo na pilha (getsymboltable): varre a pilha de cima para baixo procurando um simbolo
     *
     */
public :
    // funções para manipular stack;
    inline void push(symbol_table& st) {
        this->stack.push_back(st);
    };
    inline void pop() {
        this->stack.pop_back();
    }; // deleta tabela de cima
    inline symbol_table& top() {
        return this->stack.back();
    }; // retorna a table mais de cima
    int findSymbolTable(int key); // retorna indice na stack ou -1
private:
    std::vector<symbol_table> stack;
};
// note https://cplusplus.com/reference/vector/vector/
