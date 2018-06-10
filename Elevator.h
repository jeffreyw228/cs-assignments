// Lab 9, The "Using vectors" Program
// Programmer: Jeffrey Wan
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Complier

#include "Floor.h"
#include "Rider.h"

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

#ifndef Elevator_h
#define Elevator_h

class Elevator
{
  static int elevatorID;
  static const int IDLE;
  static const int UP;
  static const int DOWN;

  vector<Rider> r;
  const int ID;
  const int capacity;
  const int speed;
  const Floor* toFloor;
  int location;
  int direction;
  bool doorOpen;

  public:
  Elevator(const int, const int, const Floor&);

  bool isDoorOpen() const{return doorOpen;}
  bool isIdle() const{return direction == IDLE;}
  bool isDirectionUp() const{return direction == UP;}
  bool isDirectionDown() const{return direction == DOWN;}
  void closeDoor(){doorOpen = false;}
  void openDoor(){doorOpen = true;}
  void setIdle(){direction = IDLE;}
  void setDirectionUp(){direction = UP;}
  void setDirectionDown(){direction = DOWN;}
  void moveUp(){location = location + speed;}
  void moveDown(){location = location - speed;}
  void setDestination(const Floor* floor){toFloor = floor;}
  const Floor& getDestination() const{return *toFloor;}
  int getLocation() const{return location;}
  bool hasADestination() const{return toFloor != 0;}

  bool hasRiders() const{return r.size() != 0;}
  int getRiderCount() const{return r.size();}
  int getCapacity() const{return capacity;}
  int getAvailableSpace() const{return (capacity - r.size());}

  bool isNearDestination() const;
  void moveToDestinationFloor();

  vector<Rider> removeRidersForDestinationFloor(); // remove riders from vector whose destination is reached
  void addRiders(const vector<Rider>&); // copy riders from parameter vector to riders vector
  void setDestinationBasedOnRiders(); // reset toFloor based on riders' destinations

  friend ostream& operator<<(ostream&, const Elevator&);
};

#endif
