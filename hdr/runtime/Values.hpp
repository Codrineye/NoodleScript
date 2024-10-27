#pragma once

// Dependencies
#include "../backend/AST.hpp"


namespace ns {

  /*
   * Number of native functions
   * Outputs the names of our native functions
   * declair a class: scope
  */
  constexpr int numOfNativeFuncs = 17;
  extern const char* nativeFuncNames [numOfNativeFuncs];
  class Scope;

  /*
   * Same as struct in AST.hpp, but
   * instead of node, we're working with values
  */
  struct RuntimeValue {
    ValueType valueType;

    virtual ~RuntimeValue() { };
  };

  struct NullValue : public RuntimeValue {
    std::string value;

    NullValue();
  };
  struct NumValue : public RuntimeValue {
    double value;

    NumValue();
    NumValue(double value);
  };
  struct BoolValue : public RuntimeValue {
    bool state;

    BoolValue();
    BoolValue(bool state);
  };
  struct StringValue : public RuntimeValue {
    std::string value;

    StringValue();
    StringValue(const std::string& value);
  };
  struct ListValue : public RuntimeValue {
    std::vector<RuntimeValue*> elements;

    ListValue();
  };
  struct FuncValue : public RuntimeValue {
    std::string name;
    std::vector<std::string> parameters;
    std::vector<Statement*> statements;
    Scope* scope;
    bool nativeFunc;

    FuncValue();
  };

  /*
   * Make a copy of the wanted runtime value
  */
  RuntimeValue* cloneRuntimeValue(RuntimeValue* runtimeValue);

  /*
   * Output runtime value
  */
  std::ostream& operator<<(std::ostream& ostream, const RuntimeValue* runtimeValue);
}