//
//  Node.hpp
//  AVLtree
//
//  Created by Jonah Grant on 12/16/16.
//  Copyright © 2016 Jonah Grant. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <cstdlib>

//Struct for Node
class Node {
private:
    Node *left, *right, *parent;
    int datum;
    
    //Variable for depth of node in tree
    int depth = 1;
    
    friend class AVLTree;
public:
    
    //Basic constructor for Node struct
    Node(int datum_in) : left(nullptr), right(nullptr),
      parent(nullptr), datum(datum_in) {}
    
    //Helper function to allow get_tree_depth to be tail recursive
    int get_tree_height_helper(int sum);
    
    //Function to get depth of tree begginning at this node
    int get_tree_height();

};
    
#endif /* Node_h */
