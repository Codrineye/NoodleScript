#pragma once

// Dependencies
#include "Statements.hpp"

namespace ns {
  /*
   * Method that permits the eval of function calls
   * Method that permits the eval of native function calls
  */
  RuntimeValue* evaluateFuncCallExpr(FuncCall* funcCall, Scope* scope);
  RuntimeValue* evaluateNativeFuncCallExpr(
    FuncValue* funcValue, FuncCall* funcCall, Scope* scope
  );

  /*
   * Evaluation of expressiones
   * * assignment expr
   * * Unary node
   * * Numeric Unary
   * * Conditional Unary
   * * Binary node
   * * Numeric Binary
   * * Conditional Binary
   * * String Binary
  */
  RuntimeValue* evaluateAssignmentExpr(AssignmentExpr* assignmentExpr, Scope* scope);
  RuntimeValue* evaluateUnaryExprNode(UnaryExpr* unaryExpr, Scope* scope);
  RuntimeValue* evaluateNumericUnaryExpr(NumValue* numberValue, const std::string& operation);
  RuntimeValue* evaluateConditionalUnaryExpr(BoolValue* boolValue, const std::string& operation);
  RuntimeValue* evaluateBinaryExprNode(BinaryExpr* binaryExpr, Scope* scope);
  RuntimeValue* evaluateNumericBinaryExpr(
    NumValue* leftNumValue, NumValue* rightNumValue, const std::string& operation
  );
  RuntimeValue* evaluateConditionalBinaryExpr(
    BoolValue* leftBoolValue, BoolValue* rightBoolValue, const std::string& operation
  );
  RuntimeValue* evaluateStringBinaryExpr(
    StringValue* leftStringValue, StringValue* rightStringValue, const std::string& operation
  );

  /*
   * Evaluation of identifier
  */
  RuntimeValue* evaluateIdentifier(Identifier* identifier, Scope* scope);
}