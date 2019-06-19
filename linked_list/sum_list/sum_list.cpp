// Problem from Cracking the Coding Interview: Chapter 2
// 2.5: Sum Lists
// You have two numbers represented by a linked list, where each node
// contains a single digit. The digits are stored in reverse order,
// such that 1's digit is at the head of the list.
// Write a function that adds the two numbers and returns the sum
// as a linked list.

// EXAMPLE
// Input: (7->1->6) + (5->9->2). 617 + 295
// Output: (2->1->9). 912

// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem.

#include <iostream>
#include "node.h"

Node* add_list(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    int sum;

    while (temp1 != nullptr && temp2 != nullptr) {
        sum = temp1->getData() + temp2->getData();

        if (sum < 10) {
            temp1->setData(sum);
        } else {
            temp1->setData(sum % 10);
            Node* next = temp1->getNext();
            next->setData(next->getData() + 1);
        }
        temp1 = temp1->getNext();
        temp2 = temp2->getNext();
    }

    if (temp1 != nullptr) {
        if (sum > 10) {
            temp1->setData(temp1->getData() + 1);
        }
    }

    if (temp2 != nullptr) {
        if (sum > 10) {
            temp2->setData(temp2->getData() + 1);
            temp1->setNext(temp2);
        }
    }

    return head1;
}

std::string printList(Node* head) {
    std::string output;
    Node* n = head;
    while (n != nullptr) {
        output += std::to_string(n->getData());
        output += " -> ";
        n = n->getNext();
    }

    return output;
}

int main() {
    Node* head1 = new Node(7);
    Node* t = head1;
    t->setNext(new Node(1));
    t = t->getNext();
    t->setNext(new Node(6));

    Node* head2 = new Node(5);
    t = head2;
    t->setNext(new Node(9));
    t = t->getNext();
    t->setNext(new Node(2));
    
    std::cout << printList(head1) << "+ " << printList(head2) << std::endl;

    return 0;
}

// Thoughts
// 
