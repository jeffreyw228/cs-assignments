#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <algorithm>
using namespace std;

template <typename V>
class DynamicArray
{
  private:
    V* values;
    int cap;
    V dummy;

  public:
    DynamicArray(int = 2); //default parameter
    DynamicArray(const DynamicArray<V>&); //copy constructor
    void capacity(int);
    int capacity() const {return cap;}
    V operator[](int) const;
    V& operator[] (int);
    DynamicArray<V>& operator= (const DynamicArray<V>&);
    ~DynamicArray(){delete [] values;} //destructor
};

template <typename V>
DynamicArray<V>::DynamicArray(int cap)
{
  this->cap = cap;
  values = new V[cap];
}

template <typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for(int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template<typename V>
void DynamicArray<V>::capacity(int cap)
{
  V* temp = new V[cap];

  int limit = min(cap, this->cap);

  for (int i = 0; i < limit; i++)
    temp[i] = values[i];

  delete [] values;

  values = temp;

  this->cap = cap;
}

template<typename V>
DynamicArray<V>& DynamicArray<V>::operator= (const DynamicArray<V>& original)
{
  if( this != &original)
  {
    delete [] values;

    cap = original.cap;
    values = new V[cap];
    for(int i = 0; i < cap; i++)
      values[i] = original.values[i];
  }
  return *this;
}

template <typename V>
V DynamicArray<V>::operator[](int index) const
{
  if (index < 0 || index >= cap)
    return dummy;
  return values[index];
}

template <typename V>
V& DynamicArray<V>::operator[](int index)
{
  if (index < 0) return dummy;
  if (index >= cap) capacity(2*index);
  return values[index];
}

#endif // DYNAMICARRAY_H_INCLUDED
