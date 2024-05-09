#include "Calc.h"
#include <iostream>

using namespace std;

Calc::Calc() : x(0), y(0), answer(0) {}

Calc::Calc(float i1, float i2, float a): x(i1), y(i2), answer(a) {}

void Calc::Display_Answer()
{
	cout << "Answer: " << answer << "\n";
}

void Calc::Addition()
{
	answer = x + y;
}

void Calc::Subtraction()
{
	answer = x - y;
}

void Calc::Multiplication()
{
	answer = x * y;
}

void Calc::Division()
{
	answer = x / y;
}

void Calc::Absolute_ValueX()
{
	answer = abs(x);
}

void Calc::Absolute_ValueY()
{
	answer = abs(y);
}

