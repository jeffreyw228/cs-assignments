// Lab 6, Part 1: The "Developing And Testing A Stack Template" Program
// Programmer: Jeffrey Wan
// Programmer's ID: 1454611
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include <iostream>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h"

int main()
{
  Stack<int> a;

  //Testing empty function
  cout << "Testing Stack::empty\n";
  cout << "EXPECTED: Empty\n";
  cout << "ACTUAL: " << (a.empty()?"Empty":"Not Empty") << endl;
  assert(true == a.empty());

  //Testing Push and Peek function
  cout << "\nTesting Stack::push\n";
  a.push(1);
  a.push(100);
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << a.peek() << endl;
  assert (100 == a.peek());

  //Testing Pop and Clear function
  cout << "\nTesting Stack::pop and Stack::clear\n";
  a.pop();
  cout << "EXPECTED: 1 for size\n";
  cout << "ACTUAL: " << a.size() << endl;
  cout << "EXPECTED: 1 for top element\n";
  cout << "ACTUAL: " << a.peek() << endl;
  assert (1 == a.peek());
  assert (1 == a.size());
  a.clear();
  cout << "EXPECTED: 0 for size\n";
  cout << "ACTUAL: " << a.size() << endl;
  assert (0 == a.size());
  assert (true == a.empty());

  cout << "\nTesting Stack::peek\n";
  a.push(2);
  a.push(20);
  a.push(30);
  cout << "EXPECTED: 30\n";
  cout << "ACTUAL: " << a.peek() << endl;
  assert (30 == a.peek());
  assert (2 != a.peek());
  assert (1 != a.peek());

  //Testing size function
  cout << "\nTesting Stack::size\n";
  cout << "EXPECTED: 3\n";
  cout << "ACUTAL: " << a.size() << endl;
  assert (3 == a.size());

  //Testing Copy constructor and getter
  const Stack<int> b=a;
  cout << "\nTesting Copy Constructor\n";
  cout << "EXPECTED: 3 for size\n";
  cout << "ACUTAL: " << b.size() << endl;
  cout << "\nTesting Peek Getter\n";
  cout << "EXPECTED: 30 for top element\n";
  cout << "ACTUAL: " << b.peek() << endl;
  assert (3 == b.size());
  assert (30 == b.peek());

  //Testing operator=
  Stack<int> c;
  c = a;
  cout << "\nTesting Stack::operator=\n";
  cout << "EXPECTED: 3 for size\n";
  cout << "ACUTAL: " << c.size() << endl;
  cout << "EXPECTED: 30 for top element\n";
  cout << "ACTUAL: " << c.peek() << endl;
  assert (3 == b.size());
  assert (30 == b.peek());
}
