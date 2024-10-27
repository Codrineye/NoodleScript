#pragma once

// Dependencies
#include "eval/Expressions.hpp"

namespace ns {
  class Interpreter {
  public:
    /*
     * Constructor of interpreter
     * Deconstructor of interpreter
    */
    Interpreter();
    ~Interpreter();

    /*
     * Program generation
     * Program execution
    */
    void generateProgram(const std::string& sourceCode);
    void runProgram();

    /*
     * Clearing up program memory
    */
    void deleteProgramMemory();

    /*
     * Token and AST logging
    */
    void logTokens() const;
    void logAST() const;

    /*
     * Helper functions to enable logging for
     * Token, AST and Runtime Value
    */
    void enableTokenLogging(bool shouldLogTokens);
    void enableASTLogging(bool shouldLogAST);
    void enableRuntimeValueLogging(bool shouldLogRuntimeValue);

    /*
     * Status functions to determine if
     * logging is enabled
    */
    bool isTokenLoggingEnabled() const;
    bool isASTLoggingEnabled() const;
    bool isRuntimeValueLoggingEnabled() const;
  private:
    Memory memory;
    Parser parser;
    Program* program;
    Scope* globalScope;
    RuntimeValue* runtimeValue;
    /*
     * Utility property <tokens>
    */
    std::vector<Token> tokens;

    /*
     * Internal method of communication with
     * helper and status functions
    */
    bool shouldLogTokens;
    bool shouldLogAST;
    bool shouldLogRuntimeValue;

    /*
     * Internal method that allows the parser
     * to initialise the global scope
    */
    void initGlobalScope(bool reallocate = true);

    /*
     * Helper function for creating token copies
    */
    void copyTokens(const std::vector<Token>* tokens);

    /*
     * Runtime Value logging
    */
    void logRuntimeValue();
  };
}