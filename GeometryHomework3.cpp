// Lab 3b, The "Writing With Classes" Program
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

#include <cmath>

#include <cstring>


const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 3.14159;

class Circle
{
  double radius;

public:
  Circle(const char* a[]){radius = atof(a[1]);}
  void output(ostream& out);
  void xls(ostream& out);
};

class Square
{
  double size;

public:
  Square(const char* a[]){size = atof(a[1]);}
  void output(ostream& out);
  void xls(ostream& out);
};

class Cube
{
  double size;

public:
  Cube(const char* a[]){size = atof(a[1]);}
  void output(ostream& out);
  void xls(ostream& out);
};

class Rectangle
{
  double length;
  double width;

public:
  Rectangle(const char* a[]);

  void output(ostream& out);
  void xls(ostream& out);
};

class Cylinder
{
  double radius;
  double height;

public:
  Cylinder(const char* a[]);
  void output(ostream& out);
  void xls(ostream& out);
};

class Prism
{
  double length;
  double width;
  double height;

public:
  Prism(const char* a[]);

  void output(ostream& out);
  void xls(ostream& out);
};

Rectangle::Rectangle(const char* a[])
{
  length = atof(a[1]);
  width = atof(a[2]);
}

Cylinder::Cylinder(const char* a[])
{
  radius = atof(a[1]);
  height = atof(a[2]);
}

Prism::Prism(const char* a[])
{
  length = atof(a[1]);
  width = atof(a[2]);
  height = atof(a[3]);
}

void Circle::output(ostream& out)
{
  double area = PI * radius * radius;
  double circumference = 2 * PI * radius;

  out << "CIRCLE radius=" << radius;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " area=" << area << " circumference=" << circumference << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void Circle::xls(ostream& out)
{
  double area = PI * radius * radius;
  double circumference = 2 * PI * radius;

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << "Circle" << "\t" << "\t" << radius << "\t" << "\t" << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << PI * radius * radius << "\t" << 2 * PI * radius << endl;
}

void Square::output(ostream& out)
{
  double area = size * size;
  double perimeter = 4 * size;

  out << "SQUARE size=" << size;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);

  out << " area=" << area << " perimeter=" << perimeter << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void Square::xls(ostream& out)
{
  double area = size * size;
  double perimeter = 4 * size;

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << "Square" << "\t" << setprecision(6)<< size << "\t" << "\t" << "\t" << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << size* size << "\t" << 4 * size << endl;
}

void Cube::output(ostream& out)
{
  double area = 6 * size * size;
  double volume = size * size * size;

  out << "CUBE size=" << size;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " area=" << area << " volume=" << volume << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void Cube::xls(ostream& out)
{
  double area = 6 * size * size;
  double volume = size * size * size;

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << "Cube" << "\t" << size << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << 6*(size* size) << "\t" << size * size * size <<endl;
}

void Rectangle::output(ostream& out)
{
  double area = length * width;
  double perimeter = 2 * (length + width);

  out << "RECTANGLE length=" << length << " width=" << width;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);

  out << " area=" << area << " perimeter=" << perimeter << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void Rectangle::xls(ostream& out)
{
  double area = length * width;
  double perimeter = 2 * (length + width);

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << "Rectangle" << "\t" << "\t"  << "\t" << length << "\t" << width << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << length * width << "\t" << (2 * length) + (2 * width) << endl;
}

void Cylinder::output(ostream& out)
{
  double area = 2 * PI * radius * radius+ 2 * PI * radius * height;
  double volume = PI * radius * radius * height;

  out << "CYLINDER radius=" << radius << " heigth=" << height;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << area << " volume=" << volume << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void Cylinder::xls(ostream& out)
{
  double area = 2 * PI * radius * radius+ 2 * PI * radius * height;
  double volume = PI * radius * radius * height;

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << "Cylinder" << "\t" << "\t"  <<  radius << "\t" << "\t" << "\t"  << height << "\t" << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << 2 * (PI) * radius * radius + 2 * (PI) * radius * height << "\t" << (PI)* radius * radius * height <<endl;
}

void Prism::output(ostream& out)
{
  double area = 2 * length * width + 2 * length * height + 2* width * height;
  double volume = length * width * height;

  out << "PRISM length=" << length << " width=" << width << " height=" << height;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " surface area=" << area << " volume=" << volume << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void Prism::xls(ostream& out)
{
  double area = 2 * length * width + 2 * length * height + 2* width * height;
  double volume = length * width * height;

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << "Prism" << "\t" << "\t" << "\t" << length << "\t" << width << "\t" << height << "\t" << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << 2 * length * width + 2 * width * height + 2 * length * height << "\t" << length * width * height <<endl;
}

int main()
{
  // print my name and this assignment's title
  cout << "Lab 3b, The \"Writing With Classes\" Program \n";
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
  void* shapes[100];
  int shapeId[100];

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

      Square* s = new Square(token);

      shapes[i] = s;
      shapeId[i] = 1;
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

      Rectangle* s = new Rectangle(token);

      shapes[i] = s;
      shapeId[i] = 2 ;
      i++;
    }

    else if(strcmp(token[0], "CIRCLE") == 0)
    {
      if(n == 1) token[1] = "0";

      Circle* s = new Circle(token);

      shapes[i] = s;
      shapeId[i] = 3;
      i++;
    }

    else if(strcmp(token[0], "CUBE") == 0)
    {
      if(n == 1) token[1] = "0";

      Cube* s = new Cube(token);

      shapes[i] = s;
      shapeId[i] = 4;
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

      Prism* s = new Prism(token);

      shapes[i] = s;
      shapeId[i] = 5;
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

      Cylinder* s = new Cylinder(token);

      shapes[i] = s;
      shapeId[i] = 6;
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
