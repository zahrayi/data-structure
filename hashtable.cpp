#include <iostream>
using namespace std;

#define size 5 

struct node
{
    int key;
    int value;
};

class LinerHashTable
{
private:
    node* HT[size];
    int currentSize;

public:
    LinerHashTable()
    {
        for (int i = 0; i < size; ++i)
        {
            HT[i] = nullptr;
        }
        currentSize = 0;
    }

    int hashfunc(int key)
    {
        return key % size;
    }

    int linearProbe(int key, int index)
    {
        return (index + 1) % size;
    }

    void insert(node rec)
    {
        int key = rec.key;
        int h = hashfunc(key);
        int index = h;

        if (currentSize == size)
        {
            
            return;
        }

        while (HT[index] != nullptr)
        {
            index = linearProbe(key, index);
        }

        HT[index] = new node;
        HT[index]->key = key;
        HT[index]->value = rec.value;
        currentSize++;
    }
