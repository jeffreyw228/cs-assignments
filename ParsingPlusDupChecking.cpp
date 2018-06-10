// Lab 8, Part 2: The "Determine Big Oh And Perform Another Simple Timing Study" Program
// Programmer: Jeffrey Wan
// Programmer's ID: 1454611
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include <iostream> // for cout and endl
#include <string> // for string
#include <fstream>
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

#include <cstring>
#include <cstdlib>
#include "DynamicArray.h"

struct SectionsForTerm
{
  string term;
  int numberOfSectionsSeen = 0; // to track where we are in the following "array"
  DynamicArray<int> seenSectionNumbers; // or int instead of string
};

int main()
{
  // programmer's identification
  cout << "Programmer: Jeffrey Wan\n";
  cout << "Programmer's ID: 1454611\n";

  // problem setup goes here

  // programmer customizations go here
  int n = 5000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    string lineFromFile;

    clock_t startTime = clock();
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if(!fin.good()) throw "I/O error";

    for(int i = 0; i < n; i++)
      getline(fin, lineFromFile);

      int numberOfTermsSeen = 0; // to track where we are in the following "array"
      DynamicArray<SectionsForTerm> alreadySeen; // 200 should be plenty for the number of terms

      // for parsing the inputfile
      char* token;
      char buf[1000];
      const char* const tab = "\t";

      int count = 0;
      int readLine = 0;
      int duplicate = 0;
      DynamicArray<string> classes;
      DynamicArray<string> subjCodes;
      DynamicArray<int> subjCounter;

      while (fin.good())
      {
        bool result = false;
        bool Terms = false;
        bool Sections = false;
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;

        // parse the line
        const string term(token = strtok(buf, tab));
        const string section(token = strtok(0, tab));
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        for (int i = 0; i < numberOfTermsSeen; i++)
        {
          if (term == alreadySeen[i].term)
          {
            Terms = true;
            for (int j = 0; j < alreadySeen[i].numberOfSectionsSeen; j++)
            {
              if (atoi(section.c_str()) == alreadySeen[i].seenSectionNumbers[j])
              {
                Sections = true;
                break;
              }
              else
              {
                Sections = false;
              }
            }
            if (!Sections)
            {
              alreadySeen[i].seenSectionNumbers[alreadySeen[i].numberOfSectionsSeen] = atoi(section.c_str());
              alreadySeen[i].numberOfSectionsSeen++;
            }
            break;
          }
          else
          {
            Terms = false;
          }
        }

        if (Terms && Sections) {
          duplicate++;
          continue;
        }
        else
        {
          alreadySeen[numberOfTermsSeen].term = term;
          alreadySeen[numberOfTermsSeen].seenSectionNumbers[alreadySeen[numberOfTermsSeen].numberOfSectionsSeen] = atoi(section.c_str());
          alreadySeen[numberOfTermsSeen].numberOfSectionsSeen++;
          numberOfTermsSeen++;
        }

        for(int i = 0; i < readLine; i++)
        {
          if(subjectCode == subjCodes[i])
          {
            subjCounter[i]++;
            result = true;
            break;
          }
          else
          {
            result = false;
          }
        }

        if(!result)
        {
          subjCodes[readLine] = subjectCode;
          subjCounter[readLine] = 1;
          readLine++;
        }
      }

    fin.close();
    clock_t endTime = clock();

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
    cout << elapsedTimeTicks;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
}
