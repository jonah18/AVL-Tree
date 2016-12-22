//
//  AVLTree.cpp
//  AVLtree
//
//  Created by Jonah Grant on 12/16/16.
//  Copyright © 2016 Jonah Grant. All rights reserved.
//

#include "AVLTree.h"
#include <cmath>

//Default constructor for AVL Tree
AVLTree::AVLTree() : root(nullptr) {}

//Basic constructor for AVL Tree with value for root node
AVLTree::AVLTree(int root_val) : root(new Node(root_val)) {
    tree_size++;
}

//Function to insert element into AVL tree
void AVLTree::insert_val_helper(Node *&np, Node *&parent, int val) {
    
    if (empty()) {
        root = new Node(val);
        root->parent = nullptr;
        root->right = nullptr;
        root->left = nullptr;
        tree_size++;
    }
    
    else {
        
        //If Node pointer is null, insert new Node
        if (!np) {
            np = new Node(val);
            np->parent = parent;
            tree_size++;
            balance_tree(np);
        }
        
        //Traverse right subtree
        else if (val > np->datum) {
            insert_val_helper(np->right, np, val);
        }
        
        //Traverse left subtree
        else {
            insert_val_helper(np->left, np, val);
        }
    }
}

//Insert val function to give user illusion of simplicity --
//Node class is hidden
void AVLTree::insert_val(int val) {
    insert_val_helper(root, root->parent, val);
}

//Function to search for element in AVL tree
bool AVLTree::search_for_val_helper(Node *np, int val) const {
 
    if (empty() || !np) return false;
    
    if (np->datum == val) return true;
    
    //Traverse right subtree looking for val
    if (np->datum < val) {
        return search_for_val_helper(np->right, val);
    }
    
    //Traverse left subtree looking for val
    else {
        return search_for_val_helper(np->left, val);
    }
    
}

//Function to search for value in tree
bool AVLTree::search_for_val(int val) const {
    return search_for_val_helper(root, val);
}


//Function to return in order successor for np
Node *AVLTree::inorder_successor(Node *&np) {
    Node *successor = np->right;
    
    while (successor->left) {
        successor = successor->left;
    }
    
    return successor;
}

//Helper function for deleteting element from tree
bool AVLTree::delete_node_helper(Node *&np, int val) {
    
    //Reached nullptr, node not in tree
    if (!np) return false;
    
    Node *temp = np;
    
    //Found node -- delete and rearrange pointers
    if (np->datum == val) {
        
        //Begin by checking simple cases of empty subtrees
        //Case where right subtree is empty
        if (!np->right) {
            np = np->left;
            delete temp;
        }
        
        //Case where left subtree is empty
        else if (!np->left) {
            np = np->right;
            delete temp;
        }
        
        //Find inorder successor, set value of np, delete inorder successor
        else {
            Node *replace = inorder_successor(np);
            np->datum = replace->datum;
            delete_node_helper(replace, replace->datum);
        }
        
        balance_tree(np->parent);
        return true;
    }
    
    //Traverse right tree to delete node
    else if (np->datum < val) {
        return delete_node_helper(np->right, val);
    }
    
    //Traverse left tree to delete node
    else {
        return delete_node_helper(np->left, val);
    }
    
    return false;
}

//Function to delete node from AVL tree
void AVLTree::delete_node(int val) {
    
    //Decrement tree size if deleted node
    if (delete_node_helper(root, val)) {
        tree_size--;
    }
}


//Function to compute balance factor of tree
const int AVLTree::compute_balance_factor(Node *node) const {
    int right_height = 0, left_height = 0;
    
    //If node has right subtree
    if (node->right) right_height = node->right->get_tree_height();
    
    //If node has left subtree
    if (node->left) left_height = node->left->get_tree_height();
    
    return left_height - right_height;
}

//Function to execute left rotation
void AVLTree::rotate_left(Node *&np) {
    np->right->parent = np->parent;
    np->parent = np->right;
    np->right = np->right->left;
}

//Function to execute right rotation
void AVLTree::rotate_right(Node *&np) {
    np->left->parent = np->parent;
    np->parent = np->left;
    np->left = np->left->right;
}


//Function to balance tree
void AVLTree::balance_tree(Node *&begin_node) {
    
    //Check if current node is unbalanced on the right
    if (compute_balance_factor(begin_node) > 1) {
        
        //Check if need double rotation
        if (compute_balance_factor(begin_node->left) < 0) {
            rotate_left(begin_node->left);
        }
        
        rotate_right(begin_node);
    }
    
    //Check if current node is unbalanced on left
    else if (compute_balance_factor(begin_node) < -1) {
        
        //Check if need double rotation
        if (compute_balance_factor(begin_node->right) > 0) {
            rotate_right(begin_node->right);
        }
        
        rotate_left(begin_node);
    }
    
    //Continue checking until reached root
    else {
        if (begin_node->parent) {
            balance_tree(begin_node->parent);
        }
    }
}
