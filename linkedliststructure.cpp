//
// Created by mauri on 28/08/2024.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    public:

    LinkedList() : head(nullptr) {}

    int front() {
        if (head != nullptr) {
            return head->data;
        }
        return 0;
    }

    int back() {
        if (head == nullptr) {
            return 0;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(int value) {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }

    void push_back(int value) {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->next = nullptr;
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void pop_back() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    int operator[](int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr) {
                return 0;
            }
            temp = temp->next;
        }
        if (temp != nullptr) {
            return temp->data;
        } else {
            return 0;
        }
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* sorted = nullptr;

        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};


int main() {

    LinkedList list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(2);

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Size: " << list.size() << endl;

    list.sort();
    cout << "Sorted list: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    list.reverse();
    cout << "Reversed list: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    list.clear();
    cout << "List cleared, is empty? " << list.empty() << endl;

    return 0;
}
