// Lab 6 , The "Using Dynamic Memory Allocation" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Route;
class Leg
{
  const char* const StartCity;
  const char* const EndCity;
  const double distance;

public:
  Leg(const char* const, const char* const, const int&);
  friend void outputleg(ostream&, const Leg&);
  friend void outputRoute(ostream&, const Route&);
};

Leg::Leg(const char* const SCity, const char* const ECity, const int& d)
  :StartCity(SCity), EndCity(ECity), distance(d)
{
}

void outputleg(ostream& out, const Leg& a)
{
  out << a.StartCity << " to " << a.EndCity << ", " << a.distance << " miles." << endl;
}

class Route
{
  const Leg** legs;
  int size;

public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  Route(const Route&);
  ~Route(){delete [] legs;}

  friend void outputRoute(ostream&, const Route&);
};

Route::Route(const Leg& l)
{
  size = 1;
  legs = new const Leg*[size];
  legs[0] = &l;
}

Route::Route(const Route& r, const Leg& l)
{
  size = r.size + 1;
  legs = new const Leg*[size];
  for(int i = 0; i < size - 1; i++)
    legs[i] = r.legs[i];
  legs[size-1] = &l;
}

Route::Route(const Route& r)
{
  size = r.size;
  legs = new const Leg*[size];
  for(int i = 0; i < size; i++)
    legs[i] = r.legs[i];
}

void outputRoute(ostream& out , const Route& r)
{
  out << (r.legs[0])->StartCity;
  int mile = 0;
  for(int i = 0; i < r.size; i++)
  {
    out << " to " << (r.legs[i])->EndCity;
    mile = mile + (r.legs[i])->distance;
  }

  out << ", " << mile << " miles" << endl;
}



int main()
{
  // print my name and this assignment's title
  cout << "Lab 6, The \"Using Dynamic Memory Allocation\" Program \n";
  cout << "Programmer: Jeffrey Wan\n";
  cout << "Editor(s) used: Code::blocks\n";
  cout << "Compiler(s) used: GNU GCC Complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Leg a("San Francisco", "Los Angeles", 380);
  Leg b("Los Angeles", "Las Vegas", 270);
  Leg c("Las Vegas", "Salt Lake City", 420);
  Leg d("Salt Lake City", "Chicago", 1400);
  Leg e("Chicago", "Miami", 1380);
  Leg f("Miami", "New York", 1280);

  cout << "Output 6 legs" << endl;
  outputleg(cout, a);
  outputleg(cout, b);
  outputleg(cout, c);
  outputleg(cout, d);
  outputleg(cout, e);
  outputleg(cout, f);

  Route ra(a);
  Route rb(ra, b);
  Route rc(rb, c);
  Route rd(rc, d);
  Route re(rd, e);
  Route rf(re, f);

  cout << "\nObject copy test" << endl;
  {
    Route Copy = ra;
    outputRoute(cout, Copy);
  }

  cout << "\nOutput all the route" << endl;
  outputRoute(cout, ra);
  outputRoute(cout, rb);
  outputRoute(cout, rc);
  outputRoute(cout, rd);
  outputRoute(cout, re);
  outputRoute(cout, rf);
}
