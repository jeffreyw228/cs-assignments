// Lab 6, Part 1: The "Developing And Testing A Stack Template" Program
// Programmer: Jeffrey Wan
// Programmer's ID: 1454611

#ifndef Stack_H
#define Stack_H

template <typename V>
class Stack
{
  struct Node
  {
    V value;
    Node* next;
  };

  Node* firstNode; // the head pointer
  int siz; // tracking the number of nodes
  V dummy;

  public:
    Stack(); //default parameter
    Stack(const Stack<V>&); //copy constructor
    Stack<V>& operator= (const Stack<V>&);
    ~Stack(); //destructor
    void pop();
    void clear();
    void push(const V& value);
    V peek() const; //Peek for copy constructor
    V& peek();
    int size() const {return siz;}
    bool empty() const {return firstNode==0?true:false;}
};

template <typename V>
Stack<V>::Stack()
{
  firstNode = 0;
  siz = 0;
};

template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  firstNode = 0;
  Node* lastNode = 0; // temporary tail
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original)
  {
    // deallocate existing list
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }

    // build new queue
    Node* lastNode = 0; // temporary tail
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

template <typename V>
Stack<V>::~Stack()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

template <typename V>
void Stack<V>::pop()
{
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

template <typename V>
void Stack<V>::push(const V& value)
{
  Node* temp = new Node;
  temp->value = value;
  temp->next = firstNode;
  firstNode = temp;
  ++siz;
}

template <typename V>
V& Stack<V>::peek()
{
  if (firstNode == 0)
    return dummy;
  return firstNode->value;
}

template <class V>
V Stack<V>::peek() const
{
  if (firstNode == 0)
    return dummy;
  return firstNode->value;
}

template <typename V>
void Stack<V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

#endif
