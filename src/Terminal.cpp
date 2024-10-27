#include "../hdr/Terminal.hpp"

#include <fstream>

/*
 * Core structure of NoodleScript
*/
namespace ns {
  Interpreter interpreter;
  std::string sourceCode;
  std::string terminalInput;
  bool terminalOpen = false;
  bool insideConsole = false;
  bool jumpToConsole = false;


  void initNoodleScriptMsg() {
    std::cout << "\nNoodleScript Terminal - Created by CodeNoodles (2024)\n\n";

    std::cout << " @@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << " @@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << " @@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << " @@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << " @@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << " @@@@@@@@ @@@ @@@   @@\n";
    std::cout << " @@@@@@@@  @@ @@  @@@@\n";
    std::cout << " @@@@@@@@ @ @ @@@  @@@\n";
    std::cout << " @@@@@@@@ @@  @@@@  @@\n";
    std::cout << " @@@@@@@@ @@@ @@   @@@\n";
    std::cout << " @@@@@@@@@@@@@@@@@@@@@\n\n";

    std::cout << "type `help` to view a list of commands.\n\n";
  }

  void initTerminalMsg() {
    std::cout << "\nNoodleScript Terminal\n\n";

    /*
     * Signal we're entering the terminal
    */
    insideConsole = false;
  }

  void initConsoleMsg() {
    std::cout << "\nNoodleScript Console\n\n";

    /*
     * Signal we're waiting to enter the
     * terminal
    */
    insideConsole = true;
  }

  void prepareTerminalMsg() {
    std::cout << "> ";
    /*
     * Visually represent the cursor
    */
  }
  void prepareConsoleMsg() {
    /*
     * Visually represent the cursor
     * only if we are not exiting Terminal
    */
    if (!jumpToConsole)
      std::cout << ">>> ";
  }

  void executeTerminal(const std::string& input) {
    /*
     * Get input from terminal
     * const vector words that can hold
     * data type string
    */
    const std::vector<std::string> words = extractWords(input);

    /*
     * Get the size of words, representing the
     * ammount of words that were inputed
    */
    const int wordCount = words.size();

    /*
     * Exit function if no input was
     * obtained
    */
    if (wordCount == 0) return;

    if (words [0] == "help") {
      /*
       * print the help message
      */
      std::cout << "\nHere are a list of commands:\n\n"
        " console -> Enters a console where code can be written\n"
        " terminal -> Reenters the terminal\n"
        " run [string] -> Runs a .ns script, if the file path is given\n"
        " set -> Allows for the modification of enviroment variables\n"
        "     logTokens [true | false] -> Specifies whether lexed tokens should be outputed\n"
        "     logAST [true | false] -> Specifies whether to output the AST\n"
        "     logRuntimeValue [true | false] -> Specifies whether to ouput the program value\n"
        " show -> Shows the state of certain enviroment variables\n"
        "     logTokens -> Shows whether lexed tokens should be outputed\n"
        "     logAST -> Shows whether to output the AST\n"
        "     logRuntimeValue -> Shows whether to ouput the program value\n"
        "     globalMemorySize -> Shows how many runtime values are currently allocated\n"
        " clear -> Clears the terminal\n"
        " exit -> Closes the terminal\n\n";
      return;
    }

    if (words [0] == "console") {
      /*
       * Switch to console mode
      */
      initConsoleMsg();
    }

    if (words [0] == "run") {
      /*
       * Treat the next input as a
       * source file only if
       * we got more than 1 input
      */
      if (wordCount == 1) return;

      runSourceFile(words [1]);
    }

    if (words [0] == "set") {
      /*
       * Update the internal logging values
       * if we got more than 2 inputs
       * set the condition according to what was inputed
       * and assign the logging level of the appropriate
       * value if the inputed second word matches
       * one of our logging variables
      */
      if (wordCount <= 2) return;

      const bool condition = words [2] == "true";

      if (words [1] == "logTokens") interpreter.enableTokenLogging(condition);

      if (words [1] == "logAST") interpreter.enableASTLogging(condition);

      if (words [1] == "logRuntimeValue") interpreter.enableRuntimeValueLogging(condition);

    }

    if (words [0] == "show") {
      /*
       * Create method showEnvironmentVariable
       * taking 2 constant strings and prints to console
       * the environment variable name, and its value
      */
      auto showEnviromentVariable = [](const std::string& variableName, const std::string& value)
        -> void {
        std::cout << " Enviroment variable ";
        std::cout << '`' << variableName << '`';
        std::cout << " is currently set to " << value << "\n";
        };

      // quit function if only 1 input is present
      if (wordCount == 1) return;

      /*
       * Call method showEnvironmentVariable
       * giving the variable name
       * and
       * a ternary operation for its value
      */
      if (words [1] == "logTokens") {
        showEnviromentVariable(
          "shouldLogTokens",
          interpreter.isTokenLoggingEnabled() ? "true" : "false"
        );
      }
      if (words [1] == "logAST") {
        showEnviromentVariable(
          "shouldLogAST",
          interpreter.isASTLoggingEnabled() ? "true" : "false"
        );
      }
      if (words [1] == "logRuntimeValue") {
        showEnviromentVariable(
          "shouldLogRuntimeValue",
          interpreter.isRuntimeValueLoggingEnabled() ? "true" : "false"
        );
      }

      /*
       * Output special case
       * says how many runtime values
       * are allocated
      */
      if (words [1] == "globalMemorySize") {
        const int allocatedRuntimeValues = globalMemory->getPointerCount();
        std::cout << " Currently, there are ";
        std::cout << allocatedRuntimeValues;
        std::cout << " runtimeValues allocated\n";
      }
    }
    if (words [0] == "clear") {
      // Clears terminal in Windows
      system("cls");
      initNoodleScriptMsg();
    }
  }
  void executeConsole(const std::string& input) {
    /*
     * Get the input from console
    */
    if (input == "terminal") {
      /*
       * initialise the terminal
       * and end the function
      */
      initTerminalMsg();
      return;
    }

    /*
     * Set sourceCode to input if
     * sourceCode is empty
    */
    if (sourceCode == "") sourceCode = input;

    /*
     * Generate and run the program
     * in sourceCode
    */
    interpreter.generateProgram(sourceCode);
    interpreter.runProgram();

    /*
     * Assign sourceCode an
     * empty string
     * and prevent the program from
     * jumping to the console
    */
    sourceCode = "";
    jumpToConsole = false;
  }

  void initTerminal(int argc, const char** argv) {
    /*
     * signal to the program that
     * we're in terminal mode
    */
    terminalOpen = true;

    // Attempts running a source file if an extra parameter is passed into the command prompt
    if (argc == 2) {
      const std::string filepath = argv [1];
      runSourceFile(filepath);
    }
    else {
      initNoodleScriptMsg();
    }
  }

  bool isTerminalOpen() {
    // check if the terminal is open
    return terminalOpen;
  }

  void runSourceFile(const std::string& filepath) {
    /*
     * Function to run source files
     * signal to the program we're
     * in console mode
    */
    insideConsole = true;

    /*
     * Read the contents of the source file
     * declair string variable line
    */
    std::ifstream sourceFile(filepath);
    std::string line;

    while (std::getline(sourceFile, line)) {
      if (line.empty())
        continue;

      // Adds \n to ensure an EOL token is lexed
      sourceCode += line + " \n";
    }

    /*
     * Close the source file
     * initialise the console message
     * tell the program to jump to console
    */
    sourceFile.close();
    initConsoleMsg();
    jumpToConsole = true;
  }

  void updateTerminal() {
    /*
     * Function to update terminal
    */
    if (insideConsole) {
      prepareConsoleMsg();
    }
    else {
      prepareTerminalMsg();
    }

    // Skips input handling when a script is ready to be run
    if (!jumpToConsole) {
      std::getline(std::cin, terminalInput);

      // Exits terminal when `exit` is typed
      if (terminalInput == "exit") {
        terminalOpen = false;
        return;
      }
    }

    if (insideConsole) {
      executeConsole(terminalInput);
    }
    else {
      executeTerminal(terminalInput);
    }
  }

  void closeTerminal() { }
}
