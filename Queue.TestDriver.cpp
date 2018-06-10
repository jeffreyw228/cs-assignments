// Lab 7, Part 1: The "Developing And Testing A Queue Template" Program
// Programmer: Jeffrey Wan
// Programmer's ID: 1454611

#include <iostream>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h"

int main()
{
  Queue<int> a;

  // empty function test
  cout << "\nTesting Queue::empty\n";
  cout << "EXPECTED: EMPTY\n";
  cout << "ACTUAL: " << (a.empty() ? "EMPTY" : "NOT EMPTY") << endl;
  assert(a.empty());

  // peek, pop and push function test
  a.push(1);
  a.push(2);
  a.push(3);
  cout << "\nTesting Queue::peek, pop and push\n";
  cout << "EXPECTED: 3\n";
  cout << "ACTUAL: " << a.front() << endl;
  assert(a.back() == 3);
  a.pop();
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << a.front() << endl;
  assert(a.front() == 2);

  // clear and size function test
  cout << "\nTesting Queue::clear and size\n";
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << a.size() << endl;
  assert(a.size() == 2);
  a.clear();
  cout << "EXPECTED: 0\n";
  cout << "ACTUAL: " << a.size() << endl;
  assert(a.size() == 0);

  // object copy test
  Queue<int> b = a;
  assert(a.size() == b.size());
  for (int i = 0; i < b.size(); i++) {
    assert(a.front() == b.back());
    a.pop();
    b.pop();
  }

  // object assignment test
  Queue<int> c; c = a;
  assert(a.size() == c.size());
  for (int i = 0; i < c.size(); i++) {
    assert(a.front() == c.back());
    a.pop();
    c.pop();
  }
}
