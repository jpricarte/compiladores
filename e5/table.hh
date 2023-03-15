#ifndef TABLE_HH
#define TABLE_HH
#include <map>
#include <vector>
#include "tree.hh"

#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_ARRAY 21 //2.3
#define ERR_FUNCTION 22 //2.3
#define ERR_CHAR_TO_INT 31 //2.4
#define ERR_CHAR_TO_FLOAT 32 //2.4
#define ERR_CHAR_TO_BOOL 33 //2.4
#define ERR_CHAR_VECTOR 34 //2.4
#define ERR_X_TO_CHAR 35 //2.4

enum class Kind {
    LITERAL,
    VARIABLE,
    ARRAY,
    FUNCTION
};

struct Symbol {
    int line_no;
    Kind kind;
    Type type; // Declarado em tree.hh
    size_t size;
    Node* assoc_node;
    size_t desloc;
};

// SymbolTable::size() retorna o numero de itens (*4 temos o 1o endereço livre da pilha de vars)
typedef std::map<TokenVal, Symbol> SymbolTable;

Type type_infer (Type symbol_1, Type symbol_2);
size_t get_size_from_type(const Type t);
int get_char_err(Type to, Type from);
int get_bad_usage_err(Kind expected, Kind received);

struct SymbolTableStack {;
private:
    std::vector<SymbolTable> stack {};
    std::vector<size_t> curr_desloc {};
    std::map<TokenVal, SymbolTable> symbol_table_memory{};

    size_t set_desloc(Symbol& s);

public :
    // funções para manipular stack;
    inline void push(SymbolTable& st) { this->stack.push_back(st); curr_desloc.push_back(0); };
    inline void push_new() { this->stack.push_back(SymbolTable{}); curr_desloc.push_back(0); };
    inline void pop() { this->stack.pop_back(); curr_desloc.pop_back(); }; // deleta tabela de cima
    void pop(TokenVal key);
    SymbolTable& recover_symbol_table(TokenVal key);

    inline SymbolTable& top() { return this->stack.back(); }; // retorna a table mais de cima
        /*
     *  - função para buscar simbolo na pilha: varre a pilha de cima para baixo procurando um simbolo
     *  - retorna indice na stack ou -1
     */
    int find_symbol_table(TokenVal key);
    inline bool is_declared(TokenVal key) { return this->top().contains(key); };
    inline bool is_not_declared(TokenVal key) { return find_symbol_table(key) < 0; };
    void insert_top(TokenVal lv, Symbol s, bool lookup_first = false);
    // Apenas cria o símbolo, não considera no caso de arranjo (tem que ser atualizado)
    void emplace_top(std::pair<TokenVal, Symbol> p);
    Symbol get_first_symbol(TokenVal key); // Retorna copia, não o original, SIDE-EFFECT: exit(ERR_UNDECLARED) se não encontrar
};
// note https://cplusplus.com/reference/vector/vector/


#endif // TABLE_HH