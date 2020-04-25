#pragma once
#include <iostream>

class Node {
    public:
        Node() : next(NULL) {}
        Node(int k) : key(k), next(NULL) {}
        int key;
        Node* next;
};