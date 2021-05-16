# Reserved names
___
There're many names in the *Symbolic* those have the special mathematical meaning. You have to use them only by appointment to avoid most of the problems. They are:
* [Variables](#Variables)
* [Brackets](#Brackets)
* [Operations](#Operations)
* [Functions](#Functions)
* [Pre-defined constants](#Predefined)

### <a name="Variables"></a>Variables
___
In the latest *Symbolic* version(*v0.1.1*) mathematical expressions accepts only one variable: `x`.

In your expressions you can use both versions: uppercase(`X`) and the lowercase(`x`):
```c++
SymExpression a{"x+1"};
SymExpression b{"X+1"};
if(a == b)
{
  std::cout << "Expressions are equal!\n";
}
```

As you can see variables' names are *case-insensitive*

### <a name="Brackets"></a>Brackets
___
There're three types of brackets you can use in your expressions:
1. Round brackets: `()`
2. Square brackets: `[]`
3. Curly brackets: `{}`

They are exactly the same in usage.

### <a name="Operations"></a>Operations
___

There're the following supported operations in *Symbolic*

1. Unary
* \- (negation)
* \+ (+5 == 5)
2. Binary
* \+ (addition)
* \- (subtraction)
* \* (multiplication)
* / (division)
* ^ (exponentiation: 2^3 == 8)
* 

### <a name="Functions"></a>Functions
___
*Symbolic* framework supports the following functions for using them in the users' mathematical expression:

1. Common mathematical functions
* abs(value) - absolute value
* pow(base, power) - raising a `base` to the power of `power`
* sqr(base) - raising a `base` to the power of `2`
* sqrt(value) - arithmetic square root
2. Trigonometric functions(angles are calculated in radians)
* sin(angle)  - Sinus
* cos(angle)  - Cosine
* tg(angle)   - Tangent
* tan(angle)  - Tangent
* ctg(angle)  - Cotangent
* cot(angle)  - Cotangent
3. Inverse trigonometric functions
* arcsin(value) - Arcsinus
* arccos(value) - Arccosine
* arctg(value)  - Arctangent
* arctan(value) - Arctangent
* arcctg(value) - Arccotangent
* arccot(value) - Arccotangent
* arccotan(value) - Arccotangent
4. Logarithmic functions
* ln(value) - Natural logarithm(with the `e` base)
* lg(value) - Decimal logarithm(with the `10` base)
* log(base, value)  - Logarithm with an arbitrary base

As you can noticed there can be several `aliases` for the several functions. This is due to the fact that different names are used in different countries. By the way, they mean the same thing. In this list of functions symbol `*` means that a current name is an `alias` to the previous one.

Example of function usage:
```c++
SymExpression a{"sin(tg(log(5,25)))"};
```

Expressions of the *SymExpression* type support arbitrary nesting for the functions and group of brackets.



### <a name="Predefined"></a> Pre-defined constants
___
There're only two pre-defined constants:
* pi(3.141592..)
* e(2.718281828..)


