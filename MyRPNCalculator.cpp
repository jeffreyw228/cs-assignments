// Lab 6, Part2:The "An RPN Calculator" Program
// Programmer: Jeffrey Wan
// Programmer's ID: 1454611
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Stack.h"

#include <cstdlib> // atoi and atof

int main()
{
  Stack<double> s;

  string buf;
  double a;
  double b;

  while(true)
  {
    int i = 0;
    cout << "Enter: ";
    double number;
    cin >> buf;

    a = atof(buf.c_str());

    if(buf == "q" || buf == "Q") break;

    if(buf == "+")
    {
      double b;
      b = s.peek();
      s.pop();
      double c;
      c = s.peek();
      s.pop();
      double d = c + b;
      s.push(d);
      continue;
    }

    if(buf == "-")
    {
      double b;
      s.pop();
      double c;
      s.pop();
      double d = c - b;
      s.push(d);
      continue;
    }

    if(buf == "*")
    {
      double b;
      s.pop();
      double c;
      s.pop();
      double d = c * b;
      s.push(d);
      continue;
    }

    if(buf == "/")
    {
      double b;
      s.pop();
      double c;
      s.pop();
      double d = c / b;
      s.push(d);
      continue;
    }

    Stack<double> a = s;
    for (int i = 0; i < a.size(); i++)
    {
      cout << a.peek();
      a.pop();
    }
  }
}
