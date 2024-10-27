#pragma once

// Dependencies
#include <iostream>

namespace ns {
  /*
   * Error handling
  */
  class Error {
  public:
    /*
     * Location needed to identify
     * at which phase the program had
     * an error
    */
    enum class Location { Lexer, Parser, Interpreter, End } location;

    /*
     * Error code <code>
     * and error message
    */
    int code;
    std::string message;

    /*
     * error constructor
     * error handling function to
     * print out the location, error code
     * and error message
    */
    Error();
    Error(Location location, int code, std::string message);

    /*
     * token friend to print out the error
    */
    friend std::ostream& operator<<(std::ostream& ostream, const Error& error);

  /*
   * private properties of error
  */
  private:
    /*
     * string to print out all locations
    */
    static const std::string locations [static_cast<int>(Location::End)];
  };

  /*
   * stand-alone error printing function
  */
  std::ostream& operator<<(std::ostream& ostream, const Error& error);
}