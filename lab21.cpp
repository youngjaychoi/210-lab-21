#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

string names[15] = {"Name1", "Name2", "Name3", "Name4", "Name5", "Name6", "Name7", "Name8", "Name9",
                    "Name10", "Name11", "Name12", "Name13", "Name14", "Name15"};

string colors[15] = {"Color1", "Color2", "Color3", "Color4", "Color5", "Color6", "Color7", "Color8", "Color9", 
                    "Color10", "Color11", "Color12", "Color13", "Color14", "Color15"};

class Goat {
private:
    int age;
    string name;
    string color;

public:
    Goat() {
        age = rand() % (MAX_NR - MIN_NR + 1) + MIN_NR;
        name = names[rand() % 15];
        color = colors[rand() % 15];
    }

    Goat(int a, string n, string c) { age = a; name = n; color = c; }

    void print() const {
        cout << string(" ", 4) << name << " (" << color << ", " << age << ")";
    }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            current->data.print();
            cout << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            current->data.print();
            cout << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));

    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(Goat());

    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    
    cout << "List forward: ";
    list.print();

    return 0;
}
