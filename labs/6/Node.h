#pragma once
#include "BinarySearchTree.h"
class BST;

class BSTNode {
    public:
        BSTNode(int);
        int getData();
        BSTNode* getLeft();
        BSTNode* getRight();
        BST leftSubtree();
        BST rightSubtree();
        void setLeft(int);
        void setRight(int);
        void setLeft(BSTNode*);
        void setRight(BSTNode*);
        void smashLeft();
        void smashRight();
        int data;
        BSTNode* left;
        BSTNode* right;
};

