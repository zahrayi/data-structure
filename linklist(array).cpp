#include <iostream>
using namespace std;
#include "list1.cpp"
class Array
{
  private:
    LinkedList l;
    
  public:
 

void Add(int value)
{
  l.InsertAtEnd(value);
}
void Insert(int index, int value)
{
  l.InsertAtIndex(value , index);
}
int Delete(int value)
{
  return  l.RemoveNodeAtIndex(value);
}
}
