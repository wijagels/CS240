#include "BinarySearchTree.h"
#include <iostream>

BST::BST() {
    this->head = nullptr;
}

BST::BST(int data) {
    this->head = new BSTNode(data);
}

BST::BST(BSTNode* head) {
    this->head = head;
}

int BST::find(int data) {
    if(data > this->head->getData()) {
        if(this->head->getRight())
            return this->head->rightSubtree().find(data);
        return 0;
    }
    if(data < this->head->getData()) {
        if(this->head->getLeft())
            return this->head->leftSubtree().find(data);
        return 0;
    }
    return data; // Head.data == data
}

int BST::insert(int data) {
    if(!this->head) {
        this->head = new BSTNode(data);
        return data;
    }
    if(data > this->head->getData()) {
        if(this->head->getRight())
            return this->head->rightSubtree().insert(data);
        else
            this->head->setRight(data);
        return data;
    }
    if(data < this->head->getData()) {
        if(this->head->getLeft())
            return this->head->leftSubtree().insert(data);
        else
            this->head->setLeft(data);
        return 0;
    }
    return 0; // Is already in tree
}

int BST::remove(int data) {
    if(this->head->getData() == data) {
        if(this->head->getLeft() && ! this->head->getRight()) {
            this->head = this->head->getLeft();
            return 1;
        }
        else if(this->head->getRight()) {
            this->head = this->head->getRight();
            return 1;
        }
        else if(! this->head->getLeft() && ! this->head->getLeft()) {
            this->head = nullptr;
            return 1;
        }
        BSTNode* n;
        for(n = this->head->right ;n;) {
            if(n->left)
                n = n->left;
            break;
        }
        this->head->data = n->data;
        this->head->rightSubtree().remove(data);
        return 1;
    }
    std::stack<BSTNode*> s;
    s.push(this->head);
    while(s.top()) {
        if(data < s.top()->getData()) {
            if(s.top()->getLeft()) {
                s.push(s.top()->getLeft());
                continue;
            }
            return 0;
        }
        if(data > s.top()->getData()) {
            if(s.top()->getRight()) {
                s.push(s.top()->getRight());
                continue;
            }
            return 0;
        }
        // Found node to delete
        BSTNode* del = s.top();
        if(! s.top()->getLeft() && ! s.top()->getRight()) {
            s.pop();
            if(s.top()->getLeft() == del) {
                s.top()->smashLeft();
            }
            else {
                s.top()->smashRight();
            }
            delete(del);
            return 1;
        }
        if(s.top()->getLeft() && ! s.top()->getRight()) {
            s.pop();
            if(s.top()->getLeft() == del) {
                s.top()->setLeft(del->getLeft());
            }
            else {
                s.top()->setRight(del->getLeft());
            }
            delete(del);
            return 1;
        }
        if(! s.top()->getLeft() && s.top()->getRight()) {
            s.pop();
            if(s.top()->getLeft() == del) {
                s.top()->setLeft(del->getRight());
            }
            else {
                s.top()->setRight(del->getRight());
            }
            delete(del);
            return 1;
        }
        // Has both pointers full
        if(!s.top())
            return 0;
        BSTNode* n;
        for(n = s.top()->right ;n;) {
            if(n->left)
                n = n->left;
            break;
        }
        s.top()->data = n->data;
        s.top()->rightSubtree().remove(data);
        return 1;
    }
    return 0;
}
