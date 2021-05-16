# Зарезервированные имена
___
В фреймворке *Symbolic* очень много *имен*, которые имеют определённое математическое значение. Вы должны использовать их `только` по назначению, чтобы избежать множества проблем.

* [Переменные](#Variables)
* [Скобки](#Brackets)
* [Операции](#Operations)
* [Функции](#Functions)
* [Предопределённые константы](#Predefined)

### <a name="Variables"></a>Переменные
___
В последней версии *Symbolic* *v0.1.1* математические выражения поддерживают только одну переменную: `x`.

В ваших выражениях вы можете использовать две версии такой переменной: в верхнем регистре(`X`) и в нижнем регистре(`x`):
```c++
SymExpression a{"x+1"};
SymExpression b{"X+1"};
if(a == b)
{
  std::cout << "Expressions are equal!\n";
}
```

Переменные не зависят от регистра, поэтому и `x`, и `X` считаются одинаковыми.

### <a name="Brackets"></a>Скобки
___
Вы можете использовать 3 вида скобок в своих выражениях:
1. Круглые скобки: `()`
2. Квадратные скобки: `[]`
3. Фигурные скобки: `{}`

В использовании они абсолютно одинаковы.

### <a name="Operations"></a>Операции
В фреймворке *Symbolic* поддерживаются следующие операции:
1. Унарные
* \- (отрицание)
* \+ (+5 == 5)
2. Бинарные
* \+ (сложение)
* \- (вычитание)
* \* (умножение)
* / (деление)
* ^ (возведение в степень: 2^3 == 8)

### <a name="Functions"></a> Функции
*Symbolic* поддерживает следующие функции для использования в математических выражениях:

1. Обычные математические функции
* abs(value) - абсолютное значение
* pow(base, power) - возведение числа `base` в степень `power`
* sqr(base) - возведение числа `base` во `2` степень
* sqrt(value) - взятие арифметического квадратного корня
2. Тригонометрические функции(углы в *радианах*)
* sin(angle) - Синус
* cos(angle) - Косинус
* tg(angle) - Тангенс
* tan(angle) - Тангенс
* ctg(angle) - Котангенс
* cot(angle) *
3. Обратные тригонометрические функции
* arcsin(value) - Арксинус
* arccos(value) - Арккосинус
* arctg(value) - Арктангенс
* arctan(value) - *
* arcctg(value) - Арккотангенс
* arccot(value) *
* arccotan(value) *
4. Логарифмические функции
* ln(value) - Натуральный логарифм(основание равно `e`)
* lg(value) - Десятичный логарифм(основание равно `10`)
* log(base, value) - Логарифм с произвольным основанием

Как вы успели заметить, у некоторых функций есть `псевдонимы`. Это связано с тем, что в разных странах используются разные обозначения. Тем не менее, означают они одно и то же. В списке функций символ `*` означает, что данное имя - псевдоним к предыдущему.

Пример использования функций в выражениях:
```c++
SymExpression a{"sin(tg(log(5,25)))"};
```

Выражения типа *SymExpression* поддерживают произвольную глубину вложенности для функций и скобок.

### <a name="Predefined"></a> Предопределённые константы
___
В фреймворке имеется лишь 2 предопределённые константы:
* pi(3.141592..)
* e(2.718281828..)