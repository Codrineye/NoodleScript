#pragma once

// Dependencies
#include "../util/Memory.hpp"
#include "AST.hpp"

namespace ns {
  /*
   * Parser class
   * Allow the parsing of code
  */
  class Parser {
  public:
    /*
     * tokens pointer
     * pointer for root token
    */
    std::vector<Token>* tokens;

    Parser();

    std::vector<Token>* lexSourceCode(const std::string& sourceCode);

    /*
     * Produce AST program
    */
    Program* produceAST();
  private:
    /*
     * return the previous token
    */
    Token prvsToken;

    /*
     * Parse all statements
     * * statement
     * * variable decl
     * * function decl
     * * if statement
     * * while statement
    */
    Statement* parseStatement();
    Statement* parseVarDeclaration();
    Statement* parseFuncDeclaration();
    Statement* parseIfStatement();
    Statement* parseWhileStatement();

    /*
     * Parse all expr
     * * expr
     * * assignment expr
     * * conditional expr
     * * add expr
     * * mult expr
     * * add unary expr
     * * func call expr
     * * primary expr
    */
    Expr* parseExpr();
    Expr* parseAssignmentExpr();
    Expr* parseConditionalExpr();
    Expr* parsePrimaryConditionalExpr();
    Expr* parseAdditiveExpr();
    Expr* parseMultiplicativeExpr();
    Expr* parseAdditiveUnaryExpr();
    Expr* parseFuncCallExpr();
    Expr* parsePrimaryExpr();

    /*
     * Returns tokens
     * * obtain token at index <index>
     * *  starting at 0
     * * pop token at index <index>
     * *  starting at 0
     * * expect token to exist
     * * bool to return if at end of file
    */
    Token getToken(int index = 0) const;
    Token popToken(int index = 0);
    Token expectToken(TokenType tokenType, int index = 0);
    bool atEOF() const;
  };
}