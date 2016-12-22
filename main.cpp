//
//  main.cpp
//  AVLtree
//
//  Created by Jonah Grant on 12/16/16.
//  Copyright © 2016 Jonah Grant. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "AVLTree.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    
    AVLTree tree(5);
    assert(tree.size() == 1);
    assert(tree.search_for_val(5));
    
    tree.insert_val(10);
    tree.insert_val(2);
    assert(tree.size() == 3);
    
    tree.insert_val(11);
    tree.insert_val(12);
    assert(tree.size() == 5);
    
    assert(tree.search_for_val(2));
    assert(!tree.search_for_val(100));
    
    tree.delete_node(11);
    assert(!tree.search_for_val(11));
    assert(tree.size() == 4);
    
    tree.delete_node(100);
    assert(tree.size() == 4);
    
    tree.delete_node(5);
    assert(!tree.search_for_val(5));
    assert(tree.search_for_val(10));
    assert(tree.size() == 3);
    
    cout << "Passed all tests" << endl;
    
    return 0;
}
