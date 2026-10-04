#include <iostream>
using namespace std;

class Myvector
{
    int* ptr;
    int size;

public:
    Myvector()
    {
        ptr = nullptr;
        size = 0;
    }

    Myvector(int s)
    {
        size = s;
        ptr = new int[size];
    }

    Myvector(const Myvector& obj)
    {
        size = obj.size;
        ptr = new int[size];

        for (int i = 0; i < size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
    }

    Myvector& operator=(const Myvector& obj)
    {
        if (this != &obj)
        {
            delete[] ptr;
            size = obj.size;
            ptr = new int[size];

            for (int i = 0; i < size; i++)
            {
                ptr[i] = obj.ptr[i];
            }
        }

        return *this;
    }

    Myvector(Myvector&& obj)
    {
        ptr = obj.ptr;
        size = obj.size;
        obj.ptr = nullptr;
        obj.size = 0;
    }

    Myvector& operator=(Myvector&& obj)
    {
        if (this != &obj)
        {
            delete[] ptr;
            ptr = obj.ptr;
            size = obj.size;
            obj.ptr = nullptr;
            obj.size = 0;
        }

        return *this;
    }

    void Init()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand() % 100;
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << "\t";
        }

        cout << endl;
    }

    void AddBack(int a)
    {
        int* temp = new int[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }

        temp[size] = a;
        delete[] ptr;
        ptr = temp;
        size++;
    }

    void AddFirst(int a)
    {
        int* temp = new int[size + 1];

        temp[0] = a;

        for (int i = 0; i < size; i++)
        {
            temp[i + 1] = ptr[i];
        }

        delete[] ptr;

        ptr = temp;
        size++;
    }

    ~Myvector()
    {
        delete[] ptr;
    }
};


int main()
{
    srand(time(0));

    Myvector obj1(5);

    obj1.Init();

    cout << "obj1:" << endl;
    obj1.Print();


    obj1.AddBack(100);

    cout << "After AddBack:" << endl;
    obj1.Print();


    obj1.AddFirst(200);

    cout << "After AddFirst:" << endl;
    obj1.Print();

    Myvector obj2 = obj1;

    cout << "obj2 copy obj1:" << endl;
    obj2.Print();

    Myvector obj3;

    obj3 = obj1;

    cout << "obj3 = obj1:" << endl;
    obj3.Print();


    Myvector obj4 = move(obj1);

    cout << "obj4 move obj1:" << endl;
    obj4.Print();

    Myvector obj5;

    obj5 = move(obj2);

    cout << "obj5 move obj2:" << endl;
    obj5.Print();
}
