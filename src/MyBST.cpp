#include "../headers/MyBST.h"
#include <iostream> // logic_error, cout

MyBST::MyBST(int root_value)
    : _value(root_value), parent(nullptr), left(nullptr), right(nullptr) {}

MyBST::MyBST(const MyBST& other) 
    : _value(other._value), parent(nullptr), left(nullptr), right(nullptr) {

    if(other.left)
        ( left = new MyBST(*other.left) ) -> parent = this;

    if(other.right)
        ( right = new MyBST(*other.right) ) -> parent = this;
}

MyBST::~MyBST() {
    delete left;
    delete right;

    // disconnect from parent node if it exists
    if (parent) {
        if (this == parent->left)
            parent->left = nullptr;
        else if (this == parent->right)
            parent->right = nullptr;
    }
}

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

        if(removing_node == this) {
            erase(removing_node);
            return child; // `child` is now root
        }

        erase(removing_node);
        return this;
    }

    // no child
    if(removing_node->parent) { // not root
        if(removing_node == removing_node->parent->left)
            removing_node->parent->left = nullptr;
        else
            removing_node->parent->right = nullptr;
    }
    erase(removing_node);

    if(removing_node == this) return nullptr; // the only node is removed
    return this;
}

MyBST* MyBST::find(int value) {
    if (value == _value) return this;

    if (value > _value) return right ? right->find(value) : nullptr;
    else                return left  ? left ->find(value) : nullptr;
}

void MyBST::in_order_traverse() const {
    if(left) left->in_order_traverse();
    std::cout << _value << ' ';
    if(right) right->in_order_traverse();
}

void MyBST::post_order_traverse() const {
    if(left) left->post_order_traverse();
    if(right) right->post_order_traverse();
    std::cout << _value << ' ';
}

void MyBST::pre_order_traverse() const {
    std::cout << _value << ' ';
    if(left) left->pre_order_traverse();
    if(right) right->pre_order_traverse();
}

void MyBST::erase(MyBST* node) {
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    delete node;
}
