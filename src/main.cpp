#include "../hdr/Terminal.hpp"

/*
 * Main function
 * A loop that permits the code to terminate
*/
int main(int argc, const char** argv) {
  ns::initTerminal(argc, argv);

  while (ns::isTerminalOpen())
    ns::updateTerminal();

  ns::closeTerminal();
  return 0;
}