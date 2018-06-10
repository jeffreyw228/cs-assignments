// Lab 7, Part 2: The "Server Simulation" Program
// Programmer: Jeffrey Wan
// Programmer's ID: 1454611
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cmath> // atoi and atof
#include <cstdlib> // atoi, atof, srand and rand
#include <cstring> // for strtok and strcpy

#include "DynamicArray.h"
#include "Queue.h"

struct Customer
{;
  char index;
  int aTime;
  int EndTime;
};

// requires cmath and cstdlib
int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / (double)++arrivals);
  return arrivals;
}

int main()
{
  // programmer's identification
  cout << "Programmer: Jeffrey Wan\n";
  cout << "Programmer's ID: 1454611\n";

  srand(2);
  // open the input file
  char buf[1024];
  Queue<string> data;
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";

  // read the input values from a text file, one per line, in the order specified above.
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines

    data.push(buf);

    // print progress bar
    //cout << (counter % 1000 == 0 ? "." : "");
    cout.flush();
  }
  fin.close();

  int numberOfServers = atoi(data.front().c_str());
  data.pop();
  double arrivalRate = atof(data.front().c_str());
  data.pop();
  int maxLength = atoi(data.front().c_str());
  data.pop();
  int minTime = atoi(data.front().c_str());
  data.pop();
  int maxTime = atoi(data.front().c_str());
  data.pop();
  int newArrivalsStop = atoi(data.front().c_str());
  data.pop();

  cout << "number of servers:\t" << numberOfServers << endl;
  cout << "customer arrival rate:\t"<< arrivalRate << " per minute, for " << newArrivalsStop << " minutes\n";
  cout << "maximum queue length:\t"<< maxLength << endl;
  cout << "minimum service time:\t"<< minTime << endl;
  cout << "maximum service time:\t"<< maxTime << endl;

  // declare and create and assign arrays and queues to be used in the solution
  Queue<Customer> waitQueue;
  DynamicArray<Customer> nowServing;
  DynamicArray<bool> nowServingStatus;
  char indexQ = 'A';

  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all services scheduled to complete at this clock time
    // for each server
    for (int i = 0; i < numberOfServers; i++)
    {
      // if the server is busy
      if (nowServingStatus[i])
      {
        // if the service end time of the customer that it's now serving equals the clock time
        if (nowServing[i].EndTime == time)
        {
          // set this server to idle
          nowServingStatus[i] = false;
        }
      }
    }

    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    // if clock time is less than the time at which new arrivals stop
    if (time < newArrivalsStop)
    {
      // get the #of of arrivals from the "Poisson process" (a whole number >= 0)
      int numberOfArrivals = getRandomNumberOfArrivals(arrivalRate);

      // for each new arrival
      for (int i = 0; i < numberOfArrivals; i++)
      {
        // if the wait queue is NOT full
        if (waitQueue.size() < maxLength)
        {
          // create a new customer object
          Customer newCustomer;
          // set its arrival time equal to the current clock time
          newCustomer.aTime = time;
          // assign it an ID tag (A-Z)
          if (indexQ == 'Z') indexQ = 'A';
          newCustomer.index = indexQ++;
          // push the new customer onto the wait queue
          waitQueue.push(newCustomer);
        }
      }
    }

    // for idle servers, move customer from wait queue and begin service
    // for each server
    for (int i = 0; i < numberOfServers; i++)
    {
      // if (server is idle AND the wait queue is not empty)
      if (!nowServingStatus[i] && !waitQueue.empty())
      {
         // remove top customer from wait queue
         // copy it to the nowServing array at that server's index
         nowServing[i] = waitQueue.front();
         waitQueue.pop();
         // set service end time to current clock time PLUS "random service interval"
         nowServing[i].EndTime = (time + (rand() % (maxTime + 1 - minTime) + minTime));
         // mark that server as busy
         nowServingStatus[i] = true;
      }
    }

    // output the summary
    // output the current time
    cout << "\nTime: " << time << endl;
    // output a visual prepresentation of the servers and the wait queue
    cout << "---------------------------\n";
    cout << "server now serving wait queue\n";
    cout << "---- ----------- ----------\n";
    // for each server
    for (int i = 0; i < numberOfServers; i++)
    {
      // output the server's index number (zero-based)
      cout << i << "\t";
      // show the ID of the customer being served by that server (blank if idle)
      cout << (nowServingStatus[i] ? nowServing[i].index : ' ') << "\t";
      // for server 0 only, show the IDs of customers in the wait queue
      if (i == 0)
      {
        Queue<Customer> wait = waitQueue;
        while (!wait.empty())
        {
          cout << wait.front().index;
          wait.pop();
        }
      }
      cout << endl;
    }
    cout << "---------------------------\n";

    // if the end of the simulation has been reached, break
    bool allIdle = true;
    for (int i = 0; i < numberOfServers; i++)
    {
      if (nowServingStatus[i])
      {
        allIdle = false;
        break;
      }
    }
    if (allIdle && waitQueue.empty() && time >= newArrivalsStop)
    {
      cout << "Done!";
      break;
    }

    // pause for the user to press ENTER
    cout << "Press ENTER to continue...";
    cin.ignore();
  }
}
