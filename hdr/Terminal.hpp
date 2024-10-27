#pragma once

// Dependencies
#include "runtime/Interpreter.hpp"

namespace ns {
  /*
   * Internal status properties
   * Defined to get computed values
  */
  extern Interpreter interpreter;
  extern std::string sourceCode;
  extern std::string terminalInput;

  /*
   * Internal checks for user interaction
   * State of the terminal
   * the console is just the terminal waiting to
   * be given access to the editor
  */
  extern bool terminalOpen;
  extern bool insideConsole;
  extern bool jumpToConsole;

  /*
   * Configurable initialiser messages
  */
  void initNoodleScriptMsg();
  void initTerminalMsg();
  void initConsoleMsg();

  /*
   * Functions to format the output to the
   * "user interface"
  */
  void prepareTerminalMsg();
  void prepareConsoleMsg();

  /*
   * Helper functions to interact with
   * internal checks for user interaction
  */
  void executeTerminal(const std::string& input);
  void executeConsole(const std::string& input);

  /*
   * NoodleScript parsing handler
  */
  void initTerminal(int argc, const char** argv);
  bool isTerminalOpen();
  void runSourceFile(const std::string& filepath);
  void updateTerminal();
  void closeTerminal();
}