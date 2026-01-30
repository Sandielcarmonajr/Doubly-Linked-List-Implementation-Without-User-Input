//DLinkedList.cpp
#include <iostream>
#include "DLinkedList.h"

DLinkedList::DLinkedList() : head(nullptr), trailer(nullptr), n(0) {}

DLinkedList::~DLinkedList() {
    while (!empty()) {
        removeFront();
    }
}

bool DLinkedList::empty() const {
    return n == 0;
}

const int& DLinkedList::front() const {
    return head->elem;
}

const int& DLinkedList::back() const {
    return trailer->elem;
}

void DLinkedList::addFront(const int& e) {
    DNode* newNode = new DNode(e, nullptr, head);
    if (empty()) {
        head = trailer = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
    ++n;
}

void DLinkedList::addBack(const int& e) {
    DNode* newNode = new DNode(e, trailer, nullptr);
    if (empty()) {
        head = trailer = newNode;
    } else {
        trailer->next = newNode;
        trailer = newNode;
    }
    ++n;
}

void DLinkedList::removeFront() {
    if (empty()) return;
    DNode* old = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    else
        trailer = nullptr;
    delete old;
    --n;
}

void DLinkedList::removeBack() {
    if (empty()) return;
    DNode* old = trailer;
    trailer = trailer->prev;
    if (trailer != nullptr)
        trailer->next = nullptr;
    else
        head = nullptr;
    delete old;
    --n;
}

void DLinkedList::print(bool front) const {
    if (empty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if (front) {
        DNode* curr = head;
        std::cout << "List (front to back): ";
        while (curr != nullptr) {
            std::cout << curr->elem << " ";
            curr = curr->next;
        }
    } else {
        DNode* curr = trailer;
        std::cout << "List (back to front): ";
        while (curr != nullptr) {
            std::cout << curr->elem << " ";
            curr = curr->prev;
        }
    }
    std::cout << std::endl;
}

int DLinkedList::size() const {
    return n;
}

int DLinkedList::activeNodeCount() const {
    return DNode::activeNodes;
}