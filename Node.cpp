//
//  Node.cpp
//  AVLtree
//
//  Created by Jonah Grant on 12/16/16.
//  Copyright © 2016 Jonah Grant. All rights reserved.
//

#include "Node.h"
#include <algorithm>

//Helper function to allow get_tree_height to be tail recursive
int Node::get_tree_height_helper(int sum) {
    
    //If no right tree
    if (!right) {
        
        //And no left tree
        if (!left) {
            return sum + 1;
        }
        
        return left->get_tree_height_helper(sum+1);
    }
    
    //If no left tree
    if (!left) {
        return right->get_tree_height_helper(sum+1);
    }
    
    //Return max of depth of left and right subtrees
    return std::max(left->get_tree_height(), right->get_tree_height());
}

//Function to get height of tree beginning at this node
int Node::get_tree_height() {
    return get_tree_height_helper(0);
}
