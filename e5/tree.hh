#ifndef TREE_HH
#define TREE_HH
#include <vector>
#include <variant>
#include <string>
#include <memory>

const std::vector<char> useless_chars {',', ';', '(', ')', '{', '}', '[', ']'};

enum class TokenType {
    SPECIAL_CHAR, // char
    RESERVED_WORD, // std::string
    COMPOSED_OPERATOR, // std::string
    IDENTIFIER, // std::string
    LIT_INT, // int
    LIT_FLOAT, // float
    LIT_CHAR, // char
    LIT_BOOL, // bool
};

enum class Type {
    INTEGER,
    FLOATING,
    CHARACTER,
    BOOLEAN,
    TYPE_ERROR,
};

std::string node_type_to_string (Type tt);

typedef std::variant<std::string, int, float, char, bool> TokenVal;

struct LexicalVal {
    int line_no;
    TokenType token_type;
    TokenVal token_val;
};

struct Node {
    LexicalVal lex_val;
    std::vector<std::shared_ptr<Node>> children;
    bool is_func_call = false;
    Type node_type;

    Node(LexicalVal lex_val);
    Node(int line_no, TokenType token_type, TokenVal token_val);
    ~Node();

    // Save child in children vector, using smart pointer
    void add_child(Node* child);
    void add_null_child();

    std::string to_string();
    std::string token_val_to_string();

    inline LexicalVal get_lex_val() { return this->lex_val; }
    inline int get_line_no() { return this->lex_val.line_no; }
    inline TokenVal get_token_val() { return this->lex_val.token_val; }
    inline TokenType get_token_type() { return this->lex_val.token_type; }
    inline void set_is_func_call(bool b) { this->is_func_call = b; }
    inline void set_node_type(Type t) { this->node_type = t; }
    inline Type get_node_type() { return this->node_type; }

};

typedef std::shared_ptr<Node> Node_p;

/* FUNÇÕES NÃO TIPADAS */
void print_arvore(std::shared_ptr<Node> arvore);

#endif // TREE_HH

