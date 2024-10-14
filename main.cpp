#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;


class Goat {
private:
    int age;
    string name;
    string color;
    string names[15] = {"Kenny", "Gruff", "Nanny", "Dolly", "David", "Gizmo", "Whiskers", "Snickers", "Bubbles", "Shadow", "Blaze", "Sunny", "Muffin", "Twilight", "Zippy"};
    string colors[15] = {"White", "Black", "Brown", "Grey", "Spotted", "Gold", "Silver", "Red", "Yellow", "Green", "Blue", "Mauve", "Orange", "Pink", "Purple"};

public:
    // default constructor
    Goat() {
        age = rand() % 20 + 1;  
        name = names[rand() % 15];  
        color = colors[rand() % 15];  
    }

    // parameterized constructor
    Goat(int a, string n, string c) : age(a), name(n), color(c) {}

    void display() const {
        cout << name << " (" << color << ", " << age << ")";
    }
};


class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;

        Node(const Goat& goat, Node* p = nullptr, Node* n = nullptr) : data(goat), prev(p), next(n) {}
    };
    
    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(const Goat& goat) {
        Node* newNode = new Node(goat);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Push to the front of the list
    void push_front(const Goat& goat) {
        Node* newNode = new Node(goat);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
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

int main() {
    

    return 0;
}
