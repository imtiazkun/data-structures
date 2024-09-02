#include <iostream>
#include "node.h"

using namespace std;

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()
    {
        Node *temp = this->head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    // get item at index
    Node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;

        Node *temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    // Create a new node and add to the end
    void append(int value)
    {
        Node *newNode = new Node(value);

        if (this->length == 0)
        {
            // check if linked list empty
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    // Remove from last
    void removeLast()
    {
        if (length == 0)
            return;

        Node *temp = head;

        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }

            tail = pre;
            tail->next = nullptr;
        }

        delete temp;
        length--;
    }

    // Create a new node and add to the end
    void prepend(int value)
    {
        Node *newNode = new Node(value);

        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        length++;
    }

    // delete first item
    void deleteFirst()
    {
        if (length == 0)
            return;

        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }

        delete temp;
        length--;
    }

    // Create a new node and add to position n
    bool set(int index, int value)
    {
        Node *temp = get(index);

        if (temp)
        {
            temp->value = value;
            return true;
        }

        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
            return false;

        if (index == 0)
        {
            prepend(value);
            return true;
        }

        if (index == length)
        {
            append(value);
            return true;
        }

        Node *newNode = new Node(value);
        Node *temp = get(index - 1);

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return false;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
            return;

        if (index == 0) return deleteFirst();
        if (index == length - 1) return removeLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    // reverse list
    void reverse () {
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;
        Node* before = nullptr;

        for (int i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
        
    }

    // print values in linked list
    void printList()
    {
        Node *temp = this->head;

        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    int getHead()
    {
        return this->head->value;
    }

    int getTail()
    {
        return this->tail->value;
    }

    int getLength()
    {
        return this->length;
    }
};

int main()
{
    // Create linkedlist and print items
    cout << "Creating Linked List" << endl;
    LinkedList *myLinkedList = new LinkedList(4);
    myLinkedList->printList();

    // append item and print items
    cout << "\nAdding items" << endl;
    for (int i = 0; i < 5; i++)
    {
        myLinkedList->append(i);
    }
    myLinkedList->printList();

    // remove last item and print items
    cout << "\nRemoving last time" << endl;
    myLinkedList->removeLast();
    myLinkedList->printList();

    // append item and print items
    cout << "\nPrepending item" << endl;
    myLinkedList->prepend(68);
    myLinkedList->printList();

    // append item and print items
    cout << "\nDeleting first item" << endl;
    myLinkedList->deleteFirst();
    myLinkedList->printList();

    // get specific item
    cout << "\nGet item at index" << endl;
    cout << "Returned: " << myLinkedList->get(3)->value << endl;

    // insert at n
    cout << "\nInsert at n" << endl;
    myLinkedList->insert(3, 15);
    myLinkedList->printList();

    // remove n
    cout << "\nInsert at n" << endl;
    myLinkedList->deleteNode(0);
    myLinkedList->deleteNode(2);
    myLinkedList->printList();

    // reverse a linked list
    cout << "\nInsert at n" << endl;
    myLinkedList->reverse();
    myLinkedList->printList();


    return 0;
}