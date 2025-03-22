#include <iostream>
#include <assert.h>
using namespace std;

class Vector {
private:
    int *ArraY = nullptr;
    int size = 0; // the size of the Vector
    int values = 0; // the actual array size

public:
    Vector(int size) : size(size), values(0) {
        if (size < 0)
            size = 1;
        ArraY = new int[size] {};
    }
    ~Vector() {
        delete[] ArraY;
        ArraY = nullptr;
    }
    int get(int idx);
    void set(int index, int value);
    void print();
    int find(int value);
    int get_front();
    int get_back();
    void capacity_check();
    void push_back(int value);
    void insert(int value, int index);

};


int Vector::get(int idx) {
    assert(0 <= idx && idx < size);
    return ArraY[idx];
}

void Vector::set(int index, int value) {
    assert(0 <= index && index < size);
    ArraY[index] = value;
}

void Vector::print() {
    for (int index = 0; index < values; ++index)
        cout<<ArraY[index]<<" ";
    cout<<"\n the size of vector = "<<values<<endl;

}

int Vector::find(int value) {
    for (int index = 0; index < size; ++index)
        if(ArraY[index] == value)
            return index;
    return -1;
}

int Vector::get_front() {
    return ArraY[0];
}

int Vector::get_back() {
    return ArraY[size-1];
}

void Vector::capacity_check() {
    // Double the vector size
    size*= 2;
    int *Second_array = new int[size] {};
    for (int index = 0; index <= size; ++index)
        Second_array[index] = ArraY[index];
    swap(ArraY,Second_array);
    delete[] Second_array; 
}

void Vector::push_back(int value) {
    if (values == size)
        capacity_check();
    ArraY[values] = value;
    values++;
}

void Vector::insert(int value, int index) {
    assert(0 <= index && index < size);
    if (values == size)
        capacity_check();

    for(int Index = values-1; Index >= index; --Index)
        ArraY[Index+1] = ArraY[Index];  

    ArraY[index] = value;
    values++;                  
}


int main() {
    // lets use/test our vector
    Vector Names(4);
    
    Names.push_back(-1);
    Names.push_back(0);
    Names.push_back(1);
    Names.push_back(2);
    Names.push_back(3);


    Names.print();
    
    for(int index = 5; index < 20; ++index)
        Names.push_back(index);
    Names.print();

    Names.insert(55,2);
    Names.print();
    Names.insert(111,1);
    Names.print();
    Names.print();
    Names.print();

    return 0;
}