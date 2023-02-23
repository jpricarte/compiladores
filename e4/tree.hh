#pragma once
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
    BOOLEAN
};

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
    Type node_type; // todo

    Node(LexicalVal lex_val);
    Node(int line_no, TokenType token_type, TokenVal token_val);
    ~Node();

    // Save child in children vector, using smart pointer
    void add_child(Node* child);
    void add_null_child();

    std::string to_string();

    inline int get_line_no() { return this->lex_val.line_no; }
    inline TokenVal get_token_val() { return this->lex_val.token_val; }
    inline void set_is_func_call(bool b) { this->is_func_call = b; }

};

typedef std::shared_ptr<Node> Node_p;