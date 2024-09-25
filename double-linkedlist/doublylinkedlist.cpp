#include <iostream>

#include "node.h"

using namespace std;

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        this->head = newNode;
        this->tail = newNode;
        this->length = 1;
    }

    void printList() {
        Node* temp = head;

        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() { cout << "Head: " << head->value << endl; }

    void getTail() { cout << "Tail: " << tail->value << endl; }

    void getLength() { cout << "Length: " << length << endl; }

    void append(int value) {
        Node* newNode = new Node(value);

        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        length++;
    }

    void deleteLast() {
        if (length == 0) return;

        Node* temp = tail;

        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);

        if (length == 0) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;

        Node* temp = head;

        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }

        Node* temp = head;

        if (index < length / 2) {
            for (int i = 0; i < length; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = tail;
            for (int i = length - 1; i > index; i--) {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }

        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after = before->next;

        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
        return true;
    }
};

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(5);

    // listing all items in dll
    cout << "Primary Iteration" << endl;
    myDLL->printList();

    // Appending
    cout << "Appending new item (3)" << endl;
    myDLL->append(3);
    myDLL->printList();

    // removing last
    cout << "Remove last item" << endl;
    myDLL->deleteLast();
    myDLL->printList();

    // adding first
    cout << "Prepending new item (7)" << endl;
    myDLL->prepend(7);
    myDLL->printList();

    // removing first
    cout << "Removing first item" << endl;
    myDLL->deleteFirst();
    myDLL->printList();

    // get nth item after appending
    cout << "Appending 1, 9, 2 and getting the 2nd item (starts from 0)" << endl;
    myDLL->append(1);
    myDLL->append(9);
    myDLL->append(2);
    myDLL->printList();
    cout << "2nd item: " << myDLL->get(2)->value << endl;

    // insert in nth position
    cout << "Insert in nth position" << endl;
    myDLL->insert(3, 77);
    myDLL->printList();

    return 0;
}