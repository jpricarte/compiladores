#pragma once
#include <vector>
#include <variant>
#include <string>
#include <memory>

const std::vector<char> useless_chars {',', ';', '(', ')', '{', '}', '^', '[', ']'};

enum class TokenType {
    SPECIAL_CHAR, // std::string
    RESERVED_WORD, // std::string
    COMPOSED_OPERATOR, // std::string
    IDENTIFIER, // std::string
    LIT_INT, // int
    LIT_FLOAT, // float
    LIT_CHAR, // char
    LIT_BOOL, // bool
};

typedef std::variant<std::string, int, float, char, bool> TokenVal;

struct LexicalVal {
    int line_no;
    TokenType token_type;
    TokenVal token_val;
};

struct Node {
    LexicalVal lex_val;
    std::vector<std::unique_ptr<Node>> children;

    Node(LexicalVal lex_val);
    Node(int line_no, TokenType token_type, TokenVal token_val);

    // Save child in children vector, using smart pointer
    void add_child(Node* child);
    // Return True if is a useless token (such as '{' or "then")
    bool is_useless();
};

typedef std::unique_ptr<Node> Node_p;