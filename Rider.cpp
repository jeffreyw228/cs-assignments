// Lab 9, The "Using vectors" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include "Rider.h"
#include "Floor.h"

int Rider::count = 0;

Rider::Rider(const Floor& a)
:id(count+1), destination(&a)
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

Rider& Rider::operator=(const Rider& a)
{
  const_cast<int&>(id) = a.id;
  const_cast<const Floor*&>(destination) = a.destination;
  return *this;
}
