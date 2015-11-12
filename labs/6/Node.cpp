#include "Node.h"

BSTNode::BSTNode(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

int BSTNode::getData() {
    return this->data;
}

BSTNode* BSTNode::getLeft() {
    return this->left;
}

BSTNode* BSTNode::getRight() {
    return this->right;
}

BST BSTNode::leftSubtree() {
    return BST(this->left);
}

BST BSTNode::rightSubtree() {
    return BST(this->right);
}

void BSTNode::setLeft(int data) {
    this->left = new BSTNode(data);
}

void BSTNode::setRight(int data) {
    this->right = new BSTNode(data);
}

void BSTNode::setLeft(BSTNode* ptr) {
    this->left = ptr;
}

void BSTNode::setRight(BSTNode* ptr) {
    this->right = ptr;
}

void BSTNode::smashLeft() {
    this->left = nullptr;
}

void BSTNode::smashRight() {
    this->right = nullptr;
}
