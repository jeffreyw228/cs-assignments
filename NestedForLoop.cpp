// Lab 8, Part 3: The "Perform A Timing Study On Nested For-Loop Sorting" Program
// Programmer: Jeffrey Wan
// Programmer's ID: 1454611
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstdlib>

int main()
{
  // programmer's identification
  cout << "Programmer: Jeffrey Wan\n";
  cout << "Programmer's ID: 1454611\n";

  srand(time(0)); rand();
  // problem setup goes here

  // programmer customizations go here
  int n = 500; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n squared)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    double* a = new double[n];
    for(int i = 0; i < n; i++)
      a[i] = rand();

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        if(a[i] > a[j]) swap(a[i], a[j]);

    clock_t endTime = clock();

    for (int i = 1; i < n; i++) assert (a[i - 1] <= a[i]);
    delete [] a;

    // validation block -- assure that process worked

    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
}
