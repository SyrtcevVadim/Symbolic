# Tutorial
___
### Contents

* [Getting SymCalc](#GettingStarted)
* [Working with symbolic expressions](#SymExpression)
* [Constants](#Constants)
* [Parameters](#Parameters) 
* [Correctness-checking of mathematical expressions](#Correctness)
* [Next steps](#NextStep)

## <a name = "GettingStarted"></a> Getting SymCalc
___
The simplest and the only one way(so far) to get SymCalc framework is to download the whole repository and copy src folder to your project folder. Rename it to `symCalc` and include its' headers as:
  `#include"symCalc/...h`
## <a name = "SymExpression"></a>Working with mathematical expressions
___

Let's start with a simple example. Imagine that you have a function *y=x+1* and you want to calculate the value of it when the x equals to 5.

To make that in SymCalc you have to follow these three steps(put all code inside main.cpp):
1. Include the appropriate header files:

```c++
#include<iostream>                // For showing the result
#include"symCalc/SymExpression.h"
#include"symCalc/SymCalculator.h"
```
> SymExpression.h is needed to work with mathematical expressions. It declares the class *SymExpression* for handling function bodies or simple arithmetic expressions.

> SymCalculator.h is needed to compute the value of the provided mathematical expression stored inside SymExpression object. It declares the class *SymCalculator* for computing of values.

2. Define the variable to store your's mathematical expression:

```c++
SymExpression expression("x+1");
```

3. And calculate the result of y(5) with the help of SymCalculator class's object:

```c++
SymCalculator calculator(expression);
std::cout << calculator.compute(5.0) << '\n';
```

You will get the result: *6*. Be sure to try it by yourself.

## <a name = "Constants"></a> Constants
___
When you work with multiple mathematical expressions it can be tedious and cumbersome to type them every time from scratch. SymCalc offers to you the `mechanism of constants`. How does it works?

In *SymCalc* constants are the user-defined expressions which are indicated by a unique name. To work with constants you have to include `SymConstantManager.h` into your files. Imagine, that you have a very big expression, such as `1777*x^7-833*x^3+tg(log(5,25)*x-4)` and you want to add that expression to other expressions as a part. With *SymCalc* you can define a *constant*(not a good name, I agree):
```
#include"symCalc/SymConstantManager.h"
#include"symCalc/SymExpression.h"
...
string expression{"1777*x^7-833*x^3+tg(log(5,25)*x-4)"};
SymConstantManager::AddConstant("z",expression);        // z - is a name of constant
...
string anotherExpression{"z+1"};
SymExpression func(anotherExpression);
```
Now in order. Firstly, we define a constant using the `AddConstant()` method of the SymConstantManager class. It requires a constant's name and a constant's value.

>Note that the constant name have to differ from the *standard names* such as `x`, name of functions, name of predefine constants(more on this later)

Secondly, we use the constant name as a part of another expression. Virtually `another expression` constains: `1777*x^7-833*x^3+tg(log(5,25)*x-4)+1`(pay an attention to the last 2 symbols!). As a result, this mechanism can save your time or it can gives a greate possibilities for the users of your program.

## <a name = "Parameters"></a> Parameters
___
When you studied at school most likely you are familiar with *parameters* inside mathematical expressions. If in short, parameter - is an entity that can accepts any real number. Consider an example:
```
#include"symCalc/SymExpression.h"
#include"symCalc/SymCalculator.h"
...
string expression{"a*x+b"};
SymExpression func(expression);
```
We have an expression with two parameters: *a* and *b*. By default, their values equal to 1.0. So, if you wil try to compute that expression:
```
SymCalculator calculator(func);
// By default the argument of compute method is equal to 0.0
std::cout << calculator.compute() <<'\n';
```
You will receive the result *1.0*.
> There're 4 parameters in SymCalc which you can use inside your expressions: a, b, c, d

By the way, you can give them any decimal number(which suits in int variable). For instance:

```
func.setParameterValue("a", 3.0);
func.setParameterValue("b", 7.0);
// You can also replace it by func.setParameterValues(3.0, 7.0). It's exactly the same thing
std::cout << calculator.compute(1.0) << '\n';
```
I hope your result is equal to 10


## <a name = "Correctness"></a>Correctness-checking of mathematical expression
___
Users always make lots of mistakes which can be fatal for your program. I guess you want your programs to be stable to every mistake they will face with. For such purposes *SymCalc* offers the special class *SymVerifier*. It can check the correctness of the user-provided mathematical expression. For instance:
```c++
#include"symCalc/SymVerifier.h"
...
string userExpression;                  // User-provided mathematical expression
```

Imagine that you want to check whether all elements inside a provided expression are correct. You can check it as following:

```
SymVerifier verifier(userExpression);  // Binds provided expression with verifier object
if(verifier.areAllTokensCorrect())
{
  std::cout << "All tokens are correct inside \"" << userExpression << "\"!\n";
}
```
For the sake of brevity, this method checks whether provided mathematical expressions contains symbols without mathematical meaning. As a result, this example can say you, that expressions *abra+cadabra-7* and *bla/bla+1* are incorrect.

There're a lot of check-methods inside the SymVerifier class(You can find them all inside a REFERENCE SECTION). So if you want to check the whole correctness, you should use *isCorrect()* method of SymVerifier object. If the expression is correct it returns *true*. If an expression isn't correct you can receive the standard wrong-message:

```
string expression{"x-blabla"};
SymVerifier verifier(expression);
if(!verifier.isCorrect())
{
  std::cout << verifier.getErrorMessage();      // Will show: Unknown token "blabla" was received
}

```
If you want to provide the error-message by yourself you can receive the *error-code* after every
execution of some of check-methods. 
> Error-codes are the objects of the enumerations type *SymError* defined inside *SymVerifier.h*. 

There're only six error-codes:
1. NO_ERROR (no errors were occured)
2. INCORRECT_TOKEN (incorrect tokens was found)
3. INCORRECT_BRACKETS (brackets don't match or even missed: `(]`,`(`, `{}}` 
4. EMPTY_BRACKETS (empty brackets were received: `()`, `[]`, `{}`)
5. MISSED_OPERATION (operation was missed: `1 1`)
6. MISSED_OPERANDS (operand(s) was(ere) missed `pow(2,)`, `1+`)

Usage example:
```
...// Execution of check-methods
switch(verifier.getErrorType())
{
  case SymError::NO_ERROR:
    std::cout << "Everything is fine!\n";
    break;
  case SymError::EMPTY_BRACKETS:
    std::cout << "You have missed an expression between "+verifier.getIncorrectPlace() <<'\n';
    break;
  ...
}
```
> verifier.getIncorrectPlace() returns a several tokens near the error-place. The result depends on the error-type. For example, if expression contains a wrong token the method will return that token: `abra+5`->`abra`. If expression contains an empty brackets, the method will return those brackets: `()+1`->`()`. Try it for different errors and check the [REFERENCE SECTION] for more details.

## <a name = "NextStep"></a> Next steps
___
This has been a brief introduction to get you up with *SymCalc* framework. This will get you going quite far already and you are now in a position to dive in and write some symbolic calculation expressions.

Of course there is more to learn - most of which you should be able to page-fault in as you go. Please see the ever-growing [Reference section](...) for what's available.

