// Lab 7 , The "Using Operator Overloading" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#ifndef Rider_h
#define Rider_h

class Floor;

class Rider
{
  const int id;
  const Floor* const destination;
public:
  static int count;
  Rider(const Floor&);
  bool operator<(const Rider&) const;
  bool operator==(const Rider&) const;
  const Floor& getDestination() const;
};

#endif
