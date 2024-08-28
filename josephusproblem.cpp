//
// Created by mauri on 28/08/2024.
//

#include <iostream>
using namespace std;


struct Ndode {
    int data;
    Ndode* next;
    Ndode* prev;
};



class CircularList {
private:
    Ndode* head;
    Ndode* tail;

public:
    CircularList() : head(nullptr) , tail(nullptr) {}

    void insert(int data);

};





int main() {
    return 0;
};