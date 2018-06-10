// Lab 7 , The "Using Operator Overloading" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include "Rider.h"

int Rider::count = 0;

Rider::Rider(const Floor& a)
:id(count), destination(&a)
{
  count++;
}

bool Rider::operator<(const Rider& a) const
{
  bool result = false;
  if(id < a.id) result = true;
  return result;
}

bool Rider::operator==(const Rider& a) const
{
  bool result = false;
  if(id == a.id) result = true;
  return result;
}

const Floor& Rider::getDestination() const
{
  return *destination;
}
