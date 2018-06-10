// Lab 2b, The "Encapsulating Data" Program
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

struct Circle
{
  double radius;
};

struct Square
{
  double size;
};

struct Cube
{
  double size;
};

struct Rectangle
{
  double length;
  double width;
};

struct Cylinder
{
  double radius;
  double height;
};

struct Prism
{
  double length;
  double width;
  double height;
};

void outputCircle(ostream& out, Circle* p)
{
  double area = 4 * atan(double(1)) * p->radius * p->radius;
  double circumference = 2 * 4* atan(double(1)) * p->radius;

  out << "CIRCLE radius=" << p->radius;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << " area=" << area << " circumference=" << circumference << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void xlsCircle(ostream& out, Circle* p)
{
  double area = 4 * atan(double(1)) * p->radius * p->radius;
  double circumference = 2 * 4* atan(double(1)) * p->radius;

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << << "\t" << "\t" << radius << "\t" << "\t" << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << PI* radius * radius << "\t" << 2*PI*radius << endl;
}

void outputSquare(ostream& out, Square* p)
{
  double area = p->size * p->size;
  double perimeter = 4 * p->size;

  out << "SQUARE size=" << p->size;
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);

  out << " area=" << area << " perimeter=" << perimeter << endl;
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
}

void xlsCircle(ostream& out, Circle* p)
{
  double area = 4 * atan(double(1)) * p->radius * p->radius;
  double circumference = 2 * 4* atan(double(1)) * p->radius;

  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  out << << "\t" << "\t" << radius << "\t" << "\t" << "\t" << "\t";

  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  out << PI* radius * radius << "\t" << 2*PI*radius << endl;
}



void outputCube(Cube* p)
{
  double area = 6 * p->size * p->size;
  double volume = p->size * p->size * p->size;

  cout << "CUBE size=" << p->size;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << " area=" << area << " volume=" << volume << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputRectangle(Rectangle* p)
{
  double area = p->length * p->width;
  double perimeter = 2 * (p->length + p->width);

  cout << "RECTANGLE length=" << p->length << " width=" << p->width;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  cout << " area=" << area << " perimeter=" << perimeter << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputCylinder(Cylinder* p)
{
  double area = 2 * 4* atan(double(1)) * p->radius * p->radius+ 2 * 4* atan(double(1)) * p->radius * p->height;
  double volume = 4* atan(double(1)) * p->radius * p->radius * p->height;

  cout << "CYLINDER radius=" << p->radius << " heigth=" << p->height;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << " surface area=" << area << " volume=" << volume << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputPrism(Prism* p)
{
  double area = 2 * p->length * p->width + 2 * p->length * p->height + 2* p->width * p->height;
  double volume = p->length * p->width * p->height;

  cout << "PRISM length=" << p->length << " width=" << p->width << " height=" << p->height;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << " surface area=" << area << " volume=" << volume << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

int main()
{
  // print my name and this assignment's title
  cout << "Lab 2b, The \"Encapsulating Data\" Program \n";
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

      Square* s = new Square;
      s->size = atof(token[1]);

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

      Rectangle* s = new Rectangle;
      s->length = atof(token[1]);
      s->width = atof(token[2]);

      shapes[i] = s;
      shapeId[i] = 2 ;
      i++;
    }

    else if(strcmp(token[0], "CIRCLE") == 0)
    {
      if(n == 1) token[1] = "0";

      Circle* s = new Circle;
      s->radius = atof(token[1]);

      shapes[i] = s;
      shapeId[i] = 3;
      i++;
    }

    else if(strcmp(token[0], "CUBE") == 0)
    {
      if(n == 1) token[1] = "0";

      Cube* s = new Cube;
      s->size = atof(token[1]);

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

      Prism* s = new Prism;

      s->length = atof(token[1]);
      s->width = atof(token[2]);
      s->height = atof(token[3]);

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

      Cylinder* s = new Cylinder;
      s->radius = atof(token[1]);
      s->height = atof(token[2]);

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
    if(shapeId[j] == 1) outputSquare((Square*) shapes[j]);
    else if(shapeId[j] == 2) outputRectangle((Rectangle*) shapes[j]);
    else if(shapeId[j] == 3) outputCircle((cout, Circle*) shapes[j]);
    else if(shapeId[j] == 4) outputCube((Cube*) shapes[j]);
    else if(shapeId[j] == 5) outputPrism((Prism*) shapes[j]);
    else if(shapeId[j] == 6) outputCylinder((Cylinder*) shapes[j]);
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
