// Lab 9, The "Using vectors" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include "Elevator.h"
#include <cstdlib>

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;
using std::endl;

int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;

Elevator::Elevator(const int cap, const int v, const Floor& sFloor)
:ID(elevatorID),capacity(cap), speed(v), toFloor(NULL)
{
  location = sFloor.getLocation();
  direction = IDLE;
  doorOpen = true;
  elevatorID++;
}

bool Elevator::isNearDestination() const
{
  const int toLocation = toFloor->getLocation();
  int distance = (toLocation - location) > 0 ? (toLocation - location) : (location - toLocation);
  if(distance <= speed) return true;
  else return false;
}

void Elevator::moveToDestinationFloor()
{
  if(toFloor != 0)
    location = toFloor->getLocation();
}

ostream& operator<<(ostream& out, const Elevator& a)
{
  out << "Location: " << a.location << ", direction: ";
  if(a.direction > 0) out << "UP";
  else if (a.direction == 0) out << "IDLE";
  else out << "DOWN";
  out << ", door statuc: ";
  if(a.doorOpen) out << "Open";
  else out << "Close";
  out << ", ";
  if(a.r.size() == 0) out << "no Riders" << endl;
  else if(a.r.size() == 1) out << "1 Rider" << endl;
  else out << a.r.size() << " Riders" << endl;
  return out;
}

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
  vector<Rider> removedRiders;
  if(this->hasRiders())
  {
    vector<Rider> remainRiders;
    for(int i = 0; i < r.size(); i++)
      if(&r[i].getDestination() == toFloor)
        removedRiders.push_back(r[i]);
	  else
        remainRiders.push_back(r[i]);

    r = remainRiders;
  }

  return removedRiders;
}

void Elevator::addRiders(const vector<Rider>& riders)
{
  for(int i = 0; i < riders.size(); i++)
    if(this->getAvailableSpace() > 0)
	  r.push_back(riders[i]);
}

void Elevator::setDestinationBasedOnRiders()
{
  if(this->hasRiders() == false) return;

  toFloor = &r[0].getDestination();
  for(int i = 0; i < r.size(); i++)
  {
    int eToRD = abs(location - (r[i].getDestination()).getLocation());
    int eToED = abs(location - toFloor->getLocation());
	if(eToRD < eToED) toFloor = &r[i].getDestination();
  }
}
