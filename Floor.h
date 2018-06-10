// Lab 9, The "Using vectors" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#ifndef Floor_h
#define Floor_h

class Floor
{
  const int location;
public:
  Floor(int n):location(n){}
  int getLocation() const {return location;}
};

#endif
