#pragma once
#include <stack>
#include <stdlib.h>
#include "Node.h"
class BSTNode;

class BST {
    public:
        BST();
        BST(int);
        BST(BSTNode*);
        /*
         * return 0 if the integer parameter is not found, or the number itself if it is
         */
        int find(int);
        /*
         * return 0 if the integer parameter is already in the tree, or, again, the number
         * itself if it is successfully inserted
         */
        int insert(int);
        /*
         * return 0 if the integer parameter is not in the tree, or 1 if it was in the tree
         * and has been successfully removed
         */
        int remove(int);
    private:
        BSTNode* head;
};

