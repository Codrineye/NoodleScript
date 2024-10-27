#pragma once

// Dependencies
#include <unordered_map>

#include "Values.hpp"

namespace ns {
  /*
   * Definition of class Scope
   * class was declaired in Values.hpp
  */
  class Scope {
  public:
    Scope(); // Constructor initializes a new scope.

    Scope* assignParent(Scope* parent);
    RuntimeValue* declareVariable(
      const std::string& variableName, RuntimeValue* runtimeValue, bool constant = false
    );
    RuntimeValue* assignVariable(const std::string& variableName, RuntimeValue* runtimeValue);
    Scope* resolveVariable(const std::string& variableName);
    RuntimeValue* getVariableValue(const std::string& variableName);
    bool isVariableConst(const std::string& variableName);

  /*
   * Private field of Scope
  */
  private:
    struct Variable {
      bool constant;
      RuntimeValue* runtimeValue;
    };

    Scope* parent;
    std::unordered_map<std::string, Variable> variables;
  };
}