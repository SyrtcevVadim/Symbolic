/*
Copyright 2021 Syrtcev Vadim Igorevich

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once
#include"SymHelper.h"
#include"SymExpression.h"
#include<string>
#include<list>

using std::list;
using std::string;

enum class SymError
{
    NO_ERROR,  
    INCORRECT_TOKEN,
    INCORRECT_BRACKETS,
    EMPTY_BRACKETS,
    MISSED_OPERATION,
    MISSED_OPERANDS
};

class SymVerifier
{
private:
    /// List of tokens of mathematical expression it checks
    list<string> tokens;
    /// Error-message after which can appear after executing check-methods
    string errorMessage;

    /// <summary>
    /// Tokens those are close to the incorrect place
    /// </summary>
    string incorrectPlace;

    /// <summary>
    /// Type of the error
    /// </summary>
    SymError errorType;

    /// Clears all previous error information
    void clearError();

public:
    SymVerifier(const string& expression);
    SymVerifier(const SymExpression& expression);

    // Check-methods

    /// Checks whether all tokens in the expression are correct or not
    bool areAllTokensCorrect();
    /// Checks whether opening brackets corresponds to closing ones or not
    bool areBracketsCorrespond();
    /// Checks whether mathematical expression constists of empty brackets or not
    bool hasEmptyBrackets();
    /// Checks whether there're missed operations between operands or not
    bool hasMissedOperations();
    /// Checks whether every function/operation has enough operands or not
    bool hasMissedOperands();
    /// Checks the full correctness of the provided mathematical expression
    bool isCorrect();

    /// Returns the standart error-message, which can be created after executing some of check-methods
    string getErrorMessage();

    /// Returns the several tokens those are close to the incorrect place(if available)
    string getIncorrectPlace();

    /// Returns the type of the error(if available). If error hasn't been occured returns NO_ERROR
    SymError getErrorType();
};