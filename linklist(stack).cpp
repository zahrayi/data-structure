#include<iostream>
using namespace std;
class stacklink{
  private:
    LinkedList l;
    public:
      bool isempty()
      {
        if(l.sizeoflist()==0)
        return true;
        else
        return false;
      }
      void push(int item)
      {
          l.InsertABegin(item);
      }
      void pop()
      {
       return l.RemoveNodeAtBegin();
   }
}