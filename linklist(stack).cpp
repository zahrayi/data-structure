#include<iostream>
using namespace std;
#include "list1.cpp"





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
      
     
      void pop()
      {
       return l.RemoveNodeAtBegin();
   }

   
   
    void push(int item)
      {
          l.InsertABegin(item);
      }
      
      
};
=======
}
>>>>>>> f97d940a46da53359ec75ba3c553346617e942d2
