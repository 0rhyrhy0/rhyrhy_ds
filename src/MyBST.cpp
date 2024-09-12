#include "../headers/MyBST.h"
#include <iostream> // logic_error

MyBST::MyBST(int root_value)
    : _value(root_value), parent(nullptr), left(nullptr), right(nullptr) {}

MyBST* MyBST::insert(int value) {
    if (value < _value) {
        if (left) left->insert(value);
        else {
            left = new MyBST(value);
            left->parent = this;
        }
    } else if (value > _value) {
        if (right) right->insert(value);
        else {
            right = new MyBST(value);
            right->parent = this;
        }
    }

//  else : the value exists, do nothing
    return this;
}

MyBST* MyBST::remove(int value) {
    MyBST* removing_node = find(value);
    if(!removing_node)
        throw std::logic_error("Removing value was not found");

    if(removing_node->left && removing_node->right) { // two children
        MyBST* replace_node = removing_node->left->biggest();
        removing_node->_value = replace_node->value();
        replace_node->remove(replace_node->value());
        return this;
    }

    MyBST* child = removing_node->left ? removing_node->left : removing_node->right;

    if(child) { // one child
        if(removing_node == removing_node->parent->left) // removing node is left child
            removing_node->parent->left = child;
        else                                             // removing node is right child
            removing_node->parent->right = child;

        child->parent = removing_node->parent;
        delete removing_node;

        if(removing_node  == this) return child; // `child` is now root
        return this;
    }

    // no child
    if(removing_node->parent) { // not root
        if(removing_node == removing_node->parent->left)
            removing_node->parent->left = nullptr;
        else
            removing_node->parent->right = nullptr;
    }
    delete removing_node;

    if(removing_node == this) return nullptr; // the only node is removed
    return this;
}

MyBST* MyBST::find(int value) {
    if (value == _value) return this;

    if (value > _value) return right ? right->find(value) : nullptr;
    else                return left  ? left ->find(value) : nullptr;
}
