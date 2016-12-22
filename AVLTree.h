//
//  AVLTree.h
//  AVLtree
//
//  Created by Jonah Grant on 12/16/16.
//  Copyright © 2016 Jonah Grant. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Node.h"

using std::vector;

class AVLTree {
private:
    
    Node *root;
    int tree_size;
    
    //Helper function for inserting element into AVL tree
    void insert_val_helper(Node *&np, Node *&parent, int val);
    
    //Helper function to search for element in AVL tree
    bool search_for_val_helper(Node *np, int val) const;
    
    //Helper function for deleteting element from tree
    bool delete_node_helper(Node *&np, int val);
    
public:
    
    //Default constructor for AVL Tree
    AVLTree();
    
    //Basic constructor for AVL Tree with value for root node
    AVLTree(int root_val);
    
    //Function to return current size of AVL Tree
    const int size() const { return tree_size; }
    
    //Function returns true if tree is empty
    bool empty() const { return !tree_size; }
    
    //Function to build tree from inorder and postorder tree traversal
    Node *build_tree(vector<int> &inorder, vector<int> &postorder);
    
    //Function to compute balance factor of tree
    const int compute_balance_factor(Node* node) const;
    
    //Function to execute right rotation
    void rotate_right(Node *&np);
    
    //Function to execute left rotation
    void rotate_left(Node *&np);
    
    //Function to balance tree
    void balance_tree(Node *&begin_node);
    
    //Function to search for element in AVL Tree
    bool search_for_val(int val) const;
    
    //Insert val function to give user illusion of simplicity --
    //Node class is hidden
    void insert_val(int val);
    
    //Function to return in order successor for np
    Node *inorder_successor(Node *&np);
    
    //Function to delete node from AVL tree
    void delete_node(int val);
};

#endif /* AVLTree_h */
