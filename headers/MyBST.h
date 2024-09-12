#ifndef __MY_BST__
#define __MY_BST__

/**
 * Binary Search Tree implementation.
 * Each MyBST object itself acts as Node.
 */
class MyBST {
public:
    MyBST(int root_value = 0);

    MyBST* insert(int value);
    MyBST* remove(int value);

    MyBST* find(int value);

    MyBST* smallest() { return left  ? left->smallest() : this; }
    MyBST* biggest()  { return right ? right->biggest() : this; }
    const int& value() const { return _value; }

private:
    int _value;
    MyBST* parent;
    MyBST* left;
    MyBST* right;
};

#endif
