#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Min 
{
public:
    int operator()(const vector<int>& vec) const 
    {
        return *min_element(vec.begin(), vec.end());
    }
};

class Max 
{
public:
    int operator()(const vector<int>& vec) const 
    {
        return *max_element(vec.begin(), vec.end());
    }
};

class SortAscending 
{
public:
    void operator()(vector<int>& vec) const 
    {
        sort(vec.begin(), vec.end());
    }
};

class SortDescending 
{
    class CompareDescending 
    {
    public:
        bool operator()(int a, int b) const 
        {
            return a > b;
        }
    };

public:
    void operator()(vector<int>& vec) const 
    {
        sort(vec.begin(), vec.end(), CompareDescending());
    }
};

class Increment 
{
    int value;
    class IncrementOperation 
    {
        int incrementValue;
    public:
        IncrementOperation(int v) : incrementValue(v) {}
        void operator()(int& x) const 
        {
            x += incrementValue;
        }
    };

public:
    Increment(int v) : value(v) {}
    void operator()(vector<int>& vec) const {
        for_each(vec.begin(), vec.end(), IncrementOperation(value));
    }
};

class Decrement 
{
    int value;
    class DecrementOperation 
    {
        int decrementValue;
    public:
        DecrementOperation(int v) : decrementValue(v) {}
        void operator()(int& x) const 
        {
            x -= decrementValue;
        }
    };

public:
    Decrement(int v) : value(v) {}
    void operator()(vector<int>& vec) const 
    {
        for_each(vec.begin(), vec.end(), DecrementOperation(value));
    }
};

class RemoveValue 
{
    int value;
public:
    RemoveValue(int v) : value(v) {}
    void operator()(vector<int>& vec) const 
    {
        vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
    }
};

int main() {
    vector<int> vec = { 5, 3, 8, 6, 3, 7, 2, 3 };

    Min min;
    cout << "Min value: " << min(vec) << endl;
    Max max;
    cout << "Max value: " << max(vec) << endl;

    SortAscending sortAsc;
    sortAsc(vec);
    cout << "Sorted ascending: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    SortDescending sortDesc;
    sortDesc(vec);
    cout << "Sorted descending: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    Increment increment(2);
    increment(vec);
    cout << "Incremented by 2: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    Decrement decrement(3);
    decrement(vec);
    cout << "Decremented by 3: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    RemoveValue removeVal(5);
    removeVal(vec);
    cout << "After removing 5: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    return 0;
}
