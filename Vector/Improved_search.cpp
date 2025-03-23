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
    void Right_rotation();
    void left_rotation();
    void Right_rotation_n_steps(int number);
    int Delete_position(int position);
    
    int Improved_search(int number);
};

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

void Vector::print() {
    for (int index = 0; index < values; ++index)
        cout<<ArraY[index]<<" ";
    cout<<"\n the size of vector = "<<values<<endl;

}


// Function that make a better way of searching a value in vector
int Vector::Improved_search(int number) {
    int temp_idx;
    for(int index =0; index < values; ++index)
        if(ArraY[index] == number)
            temp_idx = index;
    
    if(temp_idx){
        if(temp_idx != 0)
            swap(ArraY[temp_idx],ArraY[temp_idx-1]);
            return temp_idx-1;
    }
    else
        return -1;
    }



int main() {
    
    // let`s put it on the test
    Vector number(5);
    
    for(int index = 1; index <= 5; ++index)
        number.push_back(index);

    number.print();
    number.Improved_search(1);
    number.print();

    number.Improved_search(3);
    number.Improved_search(3);
    number.Improved_search(3);
    number.Improved_search(5);
    number.print();
    return 0;
}
