#pragma once

// Depdencencies
#include <string>
#include <vector>
#include <iostream>

// Define the ns (noodlescript) namespace
namespace ns {
  enum class TokenType {
    Number,
    Bool,
    String,
    Const,
    Var,
    Func,
    EndStatement,
    If,
    Else,
    While,
    Equals,
    UnaryOperator,
    BinaryOperator,
    OpenParen,
    CloseParen,
    OpenBracket,
    CloseBracket,
    Identifier,
    Comment,
    EndOfLine,
    EndOfFile,
    Invalid
  };
  // Declair all types of tokens

  struct TokenIdentifier {
    std::vector<std::string> identifiers;

    static TokenIdentifier tokenIdentifiers [static_cast<int>(TokenType::Invalid)];
  };
  /*/
  // Structure to identify a token
  // Looks through all tokens until it reaches Invalid
  */

  struct Token {
    TokenType type;
    std::string string;
  };
  // Definition of a token

  /*
   * function for processing escape characters
  */
  void processEscapeCharacters(std::string& string);

  /*
   * function to unprocess escape characters
  */
  void unprocessEscapeCharacters(std::string& string);
  
  /*
   * function to extract the next identifier
  */
  std::string extractNextIdentifier(std::string& line, char seperator = ' ');
  
  /*
   * function to extract words from the terminal
  */
  std::vector<std::string>& extractWords(const std::string& string);
  
  /*
   * function to determine a token type
  */
  Token determineTokenType(const std::string& nextIdentifier);
  
  /*
   * function to extract the token size
  */
  std::vector<Token>& tokenize(const std::string& sourceCode);

  /*
   * output the token contents
  */
  std::ostream& operator<<(std::ostream& ostream, Token token);
  /*
   * output the number of token
  */
  std::ostream& operator<<(std::ostream& ostream, const std::vector<Token>& tokens);
}
