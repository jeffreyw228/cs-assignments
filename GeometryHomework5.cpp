// Lab 10 , The "Using Inheritance" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;

#include <cstdlib>

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ostream;

#include <vector>
using std::vector;

#include <cmath>

#include <cstring>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159;

class Shape
{
};

class Circle : public Shape
{
protected:
  const double radius;

public:
  Circle(const char* const * const a):radius(atof(a[1])){}
  void output(ostream& out) const;
  void xls(ostream& out) const;
};

class Square : public Shape
{
protected:
  const double size;

public:
  Square(const char* const * const a):size(atof(a[1])){}
  void output(ostream& out) const;
  void xls(ostream& out) const;
};

class Cube : public Square
{
public:
  Cube(const char* const * const a): Square(a){}
  void output(ostream& out) const;
  void xls(ostream& out) const;
};

class Rectangle : public Shape
{
protected:
  const double length;
  const double width;

public:
  Rectangle(const char* const * const a);
  void output(ostream& out) const;
  void xls(ostream& out) const;
};

class Cylinder : public Circle
{
  const double height;

public:
  Cylinder(const char* const * const a);
  void output(ostream& out) const;
  void xls(ostream& out) const;
};

class Prism : public Rectangle
{
protected:
  const double height;

public:
  Prism(const char* const * const a);
  void output(ostream& out) const;
  void xls(ostream& out) const;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 10, The \"Using Inheritance\" Program \n";
  cout << "Programmer: Jeffrey Wan\n";
  cout << "Editor(s) used: Code::blocks\n";
  cout << "Compiler(s) used: GNU GCC Complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  ifstream fin;
  fin.open("geo.txt");
  if(!fin.good())
    return 1;

  ofstream fout;
  fout.open("geo.xls");
  fout << "Shape\tSide\tRadius\tLength\tWidth\tHeight\tArea\tPerimiter\tSurface Area\tVolume\n";

  int i = 0;
  vector<const Shape*> shapes;
  vector<int> shapeId;

  while (!fin.eof())
  {
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);

    int n = 0;

    const char* token[MAX_TOKENS_PER_LINE] = {};

    token[0] = strtok(buf, DELIMITER);

    if(token[0])
    {
      for(n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER);
        if(!token[n]) break;
      }
    }

    if(n == 0) continue;

    if(strcmp(token[0], "SQUARE") == 0)
    {
      if(n == 1) token[1] = "0";

      const Square* s = new Square(token);

      shapes.push_back(s);
      shapeId.push_back(1);
      i++;
    }

    else if(strcmp(token[0], "RECTANGLE") == 0)
    {
      if(n == 1)
      {
        token[1] = "0";
        token[2] = "0";
      }

      if(n == 2) token[2] = "0";

      const Rectangle* s = new Rectangle(token);

      shapes.push_back(s);
      shapeId.push_back(2);
      i++;
    }

    else if(strcmp(token[0], "CIRCLE") == 0)
    {
      if(n == 1) token[1] = "0";

      const Circle* s = new Circle(token);

      shapes.push_back(s);
      shapeId.push_back(3);
      i++;
    }

    else if(strcmp(token[0], "CUBE") == 0)
    {
      if(n == 1) token[1] = "0";

      const Cube* s = new Cube(token);

      shapes.push_back(s);
      shapeId.push_back(4);
      i++;
    }

    else if(strcmp(token[0], "PRISM") == 0)
    {
      if(n == 1)
      {
        token[1] = "0";
        token[2] = "0";
        token[3] = "0";
      }

      if(n == 2)
      {
        token[2] = "0";
        token[3] = "0";
      }

      if(n == 3)
      {
        token[3] = "0";
      }

      const Prism* s = new Prism(token);

      shapes.push_back(s);
      shapeId.push_back(5);
      i++;
    }

    else if(strcmp(token[0], "CYLINDER") == 0)
    {
      if(n == 1)
      {
        token[1] = "0";
        token[2] = "0";
      }

      if(n == 2)
      {
        token[2] = "0";
      }

      const Cylinder* s = new Cylinder(token);

      shapes.push_back(s);
      shapeId.push_back(6);
      i++;
    }

    else
      cout << token[0] << " invalid object" << endl;
  }

  fin.close();


  for(int j = 0; j < i + 1; j++)
  {
    if(shapeId[j] == 1) ((Square*)shapes[j])->output(cout);
    else if(shapeId[j] == 2) ((Rectangle*)shapes[j])->output(cout);
    else if(shapeId[j] == 3) ((Circle*)shapes[j])->output(cout);
    else if(shapeId[j] == 4) ((Cube*)shapes[j])->output(cout);
    else if(shapeId[j] == 5) ((Prism*)shapes[j])->output(cout);
    else if(shapeId[j] == 6) ((Cylinder*)shapes[j])->output(cout);
  }

    for(int j = 0; j < i + 1; j++)
  {
    if(shapeId[j] == 1) ((Square*)shapes[j])->xls(fout);
    else if(shapeId[j] == 2) ((Rectangle*)shapes[j])->xls(fout);
    else if(shapeId[j] == 3) ((Circle*)shapes[j])->xls(fout);
    else if(shapeId[j] == 4) ((Cube*)shapes[j])->xls(fout);
    else if(shapeId[j] == 5) ((Prism*)shapes[j])->xls(fout);
    else if(shapeId[j] == 6) ((Cylinder*)shapes[j])->xls(fout);
  }


  for(int j = 0; j < i + 1; j++)
  {
    if(shapeId[j] == 1) delete(Square*) shapes[j];
    else if(shapeId[j] == 2) delete(Rectangle*) shapes[j];
    else if(shapeId[j] == 3) delete(Circle*) shapes[j];
    else if(shapeId[j] == 4) delete(Cube*) shapes[j];
    else if(shapeId[j] == 5) delete(Prism*) shapes[j];
    else if(shapeId[j] == 6) delete(Cylinder*) shapes[j];
  }
}

ostream& reset(ostream& out)
{
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  return out;
}

ostream& set(ostream& out)
{
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  return out;
}

Rectangle::Rectangle(const char* const * const a)
:length(atof(a[1])), width(atof(a[2]))
{
}

Cylinder::Cylinder(const char* const * const a)
: Circle(a), height(atof(a[2]))
{
}

Prism::Prism(const char* const * const a)
:Rectangle(a), height(atof(a[3]))
{
}

void Circle::output(ostream& out) const
{
  double area = PI * radius * radius;
  double circumference = 2 * PI * radius;

  out << "CIRCLE radius=" << radius;
  out << set << " area=" << area << " circumference=" << circumference << endl;
  out << reset;
}

void Circle::xls(ostream& out) const
{
  double area = PI * radius * radius;
  double circumference = 2 * PI * radius;

  out << "Circle" << "\t" << "\t" << radius << "\t" << "\t" << "\t" << "\t";
  out << set << area << "\t" << circumference << endl;
  out << reset;
}

void Square::output(ostream& out) const
{
  double area = size * size;
  double perimeter = 4 * size;

  out << "SQUARE size=" << size;
  out << set << " area=" << area << " perimeter=" << perimeter << endl;
  out << reset;
}

void Square::xls(ostream& out) const
{
  double area = size * size;
  double perimeter = 4 * size;

  out << "Square" << "\t" << setprecision(6)<< size << "\t" << "\t" << "\t" << "\t" << "\t";
  out << set << area << "\t" << perimeter << endl;
  out << reset;
}

void Cube::output(ostream& out) const
{
  double area = 6 * size * size;
  double volume = size * size * size;

  out << "CUBE size=" << size;
  out << set << " area=" << area << " volume=" << volume << endl;
  out << reset;
}

void Cube::xls(ostream& out) const
{
  double area = 6 * size * size;
  double volume = size * size * size;

  out << "Cube" << "\t" << size << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t";
  out << set << area << "\t" << volume << endl;
  out << reset;
}

void Rectangle::output(ostream& out) const
{
  double area = length * width;
  double perimeter = 2 * (length + width);

  out << "RECTANGLE length=" << length << " width=" << width;
  out << set << " area=" << area << " perimeter=" << perimeter << endl;
  out << reset;
}

void Rectangle::xls(ostream& out) const
{
  double area = length * width;
  double perimeter = 2 * (length + width);

  out << "Rectangle" << "\t" << "\t"  << "\t" << length << "\t" << width << "\t" << "\t";
  out << set << area << "\t" << perimeter << endl;
  out << reset;
}

void Cylinder::output(ostream& out) const
{
  double area = 2 * PI * radius * radius+ 2 * PI * radius * height;
  double volume = PI * radius * radius * height;

  out << "CYLINDER radius=" << radius << " heigth=" << height;
  out << set << " surface area=" << area << " volume=" << volume << endl;
  out << reset;
}

void Cylinder::xls(ostream& out) const
{
  double area = 2 * PI * radius * radius+ 2 * PI * radius * height;
  double volume = PI * radius * radius * height;

  out << "Cylinder" << "\t" << "\t"  <<  radius << "\t" << "\t" << "\t"  << height << "\t" << "\t" << "\t";
  out << set << area << "\t" << volume << endl;
  out << reset;
}

void Prism::output(ostream& out) const
{
  double area = 2 * length * width + 2 * length * height + 2* width * height;
  double volume = length * width * height;

  out << "PRISM length=" << length << " width=" << width << " height=" << height;
  out << set << " surface area=" << area << " volume=" << volume << endl;
  out << reset;
}

void Prism::xls(ostream& out) const
{
  double area = 2 * length * width + 2 * length * height + 2* width * height;
  double volume = length * width * height;

  out << "Prism" << "\t" << "\t" << "\t" << length << "\t" << width << "\t" << height << "\t" << "\t" << "\t";
  out << set << area << "\t" << volume << endl;
  out << reset;
}
