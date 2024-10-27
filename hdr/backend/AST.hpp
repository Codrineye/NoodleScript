#pragma once

// Dependencies
#include "Lexer.hpp"

namespace ns {
  enum class NodeType {
    // Statements
    Program,
    VarDeclaration,
    FuncDeclaration,
    IfStatement,
    WhileStatement,

    // Expressions
    NullLiteral,
    NumLiteral,
    StringLiteral,
    ListLiteral,
    Identifier,
    ListAccesser,
    UnaryExpr,
    BinaryExpr,
    AssignmentExpr,
    FuncCall
  };
  /*
   * Express the types of nodes
   * being worked with
  */
  enum class ValueType {
    Null,
    Number,
    Bool,
    String,
    List,
    FuncValue
  };
  /*
   * Express the types of values
   * being worked with
  */

  /*
   * Struct for nodes of type Statement
   * virtual destructor for propper statement cleanup
  */
  struct Statement {
    NodeType nodeType;

    virtual ~Statement() { }
  };

  /*
   * Struct for expressions
   * in nodes of type Statement
  */
  struct Expr : public Statement { };

  /*
   * Struct for Statements inside
   * of a program
  */
  struct Program : public Statement {
    std::vector<Statement*> statements;

    Program();
  };

  /*
   * Struct for variables
   * of type <value type>
  */
  struct VarDeclaration : public Statement {
    bool constant;
    ValueType valueType;
    std::string identifier;
    Expr* expr;

    VarDeclaration();
  };

  /*
   * Struct for functions
   * Permits the assignment of multiple parameters
   * and statements (function definition)
  */
  struct FuncDeclaration : public Statement {
    std::string name;
    bool nativeFunc;
    std::vector<std::string> parameters;
    std::vector<Statement*> statements;

    FuncDeclaration();
  };

  /*
   * Struct for <if> statement
  */
  struct IfStatement : public Statement {
    Expr* condition;
    std::vector<Statement*> ifStatements;
    std::vector<Statement*> elseStatements;

    IfStatement();
  };

  /*
   * Struct for <while> statement
  */
  struct WhileStatement : public Statement {
    Expr* condition;
    std::vector<Statement*> statements;

    WhileStatement();
  };

  /*
   * Struct for <NULLptr> expr
  */
  struct NullLiteral : public Expr {
    NullLiteral();
  };

  /*
   * Struct for a Lnumber expr
  */
  struct NumLiteral : public Expr {
    double value;

    NumLiteral();
  };

  /*
   * Struct for a Lstring expr
  */
  struct StringLiteral : public Expr {
    std::string value;

    StringLiteral();
  };

  /*
   * Struct for a Llist expr
  */
  struct ListLiteral : public Expr {
    std::vector<Expr*> elements;

    ListLiteral();
  };

  /*
   * Struct for an Identifier expr
  */
  struct Identifier : public Expr {
    std::string name;

    Identifier();
  };

  /*
   * Struct for List Accessor expr
   * arr[5] = accessor
  */
  struct ListAccesser : public Expr {
    std::string name;
    int index;

    ListAccesser();
  };

  /*
   * Struct for Unary expr
   * How Unary operations are performed
  */
  struct UnaryExpr : public Expr {
    Expr* expr;
    std::string operation;

    UnaryExpr();
  };

  /*
   * Struct for Binary expr
   * How Binary operations are performed
  */
  struct BinaryExpr : public Expr {
    Expr* leftExpr;
    Expr* rightExpr;
    std::string operation;

    BinaryExpr();
  };

  /*
   * Struct for Assignment expr
   * how to assign a value
  */
  struct AssignmentExpr : public Expr {
    Expr* assigne;
    Expr* value;

    AssignmentExpr();
  };

  /*
   * Struct for Function call expr
   * permit calling a declaired function
  */
  struct FuncCall : public Expr {
    std::string caller;
    std::vector<Expr*> arguments;

    FuncCall();
  };

  /*
   * Output a statement
  */
  std::ostream& operator<<(std::ostream& ostream, const Statement* statement);
}