
#include <iostream>
using namespace std;
class Array
{
private:
    int Size;
    int Lenght;
    int *Items;

public:
    Array(int ArraySize)
    {
        Size = ArraySize;
        Lenght = 0;
        Items = new int[Size];
    }
    void fill()
    {
        int NumberOfItems;
        cout << "How many items you want to add ? \n";
        cin >> NumberOfItems;
        if (NumberOfItems > Size)
        {
            cout << " The number of items excced the limit \n";
            return;
        }
        else
        {
            for (int i = 0; i < NumberOfItems; i++)
            {
                cout << "Enter the ( " << i << " ) item :  ";
                cin >> Items[i];
                Lenght++;
            }
        }
    }
    void Display()
    {
        cout << " Array items :  \t";
        for (int i = 0; i < Lenght; i++)
        {
            cout << Items[i] << "\t";
        }
        cout << endl;
    }
    int GetSize()
    {
        return Size;
    }
    int Getlength()
    {
        return Lenght;
    }
    int search(int key)
    {
        int index = -1;
        for (int i = 0; i < Lenght; i++)
        {
            if (Items[i] == key)
            {
                index = i;
                break;
            }
        }
        return index;
    }
    void insert(int index, int newitem)
    {
        if (index >= 0 && index < Size)
        {
            for (int i = Lenght; i > index; i--)
            {
                Items[i] = Items[i - 1];
            }
            Items[index] = newitem;
            Lenght++;
        }
        else
        {
            cout << "Index out of range \n";
        }
    }
    void remove(int index)
    {
        if (index >= 0 && index < Size)
        {
            for (int i = index; i < Lenght - 1; i++)
            {
                Items[i] = Items[i + 1];
                Lenght--;
            }
        }
        else
        {
            cout << "index out of array range !! ";
        }
    }
};
int main()
{
    cout << "Hello to our array generator . \n";
    int arraySize;
    cout << " Please enter array Size ? \n";
    cin >> arraySize;
    Array Myarray(arraySize);
    Myarray.fill();
    Myarray.Display();
    cout << "The length of the array is " << Myarray.Getlength() << " and the Size is " << Myarray.GetSize() << "\n";
    cout << "What is the operation you want to do (insert - delete - search ) ? \n";
    string operation = "null";
    cin >> operation;
    if (operation == "search")
    {
        cout << "Enter the value to search for ? \n";
        int key;
        cin >> key;
        int index = Myarray.search(key);
        if (index == -1)
        {
            cout << " Item not found !!";
        }
        else
        {
            cout << " The item is found in " << index << "tr ";
        }
        cout << "The length of the array is " << Myarray.Getlength() << " and the Size is " << Myarray.GetSize() << "\n";
    }
    else if (operation == "insert")
    {
        cout << "What is value you want to add ? \n";
        int newvalue = 0;
        cin >> newvalue;
        cout << " where you want to add this value ? \n";
        int index = 0;
        cin >> index;
        Myarray.insert(index, newvalue);
        Myarray.Display();
        cout << "The length of the array is " << Myarray.Getlength() << " and the Size is " << Myarray.GetSize() << "\n";
    }
    else if (operation == "delete")
    {
        cout << "What the index of the item you want to delet ? \n";
        int index = 0;
        cin >> index;
        Myarray.remove(index);
        Myarray.Display();
        cout << "The length of the array is " << Myarray.Getlength() << " and the Size is " << Myarray.GetSize() << "\n";
    }
}