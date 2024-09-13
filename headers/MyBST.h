#ifndef __MY_BST__
#define __MY_BST__

/**
 * Binary Search Tree implementation.
 * Each MyBST object itself acts as Node.
 */
class MyBST {
public:
    /**
     * @brief Construct new MyBST root node with its value as `root_value`.
     * @param root_value The value root will have.
     */
    MyBST(int root_value = 0);

    /**
     * @brief Copy constructor.
     * @param other The MyBST to copy from.
     */
    MyBST(const MyBST& other);

    // No move constructor yet

    /**
     * @brief Destructor.
     * Recursively deletes all child nodes, effectively deleting the entire subtree.
     */
    ~MyBST();

    /**
     * @brief Insert value.
     * Do nothing if the value already exists.
     * 
     * @param value The value being inserted.
     */
    MyBST* insert(int value);

    /**
     * @brief Remove value.
     * @param value The value being removed.
     * 
     * @throws `logic_error` if the value was not found.
     */
    MyBST* remove(int value);

    /**
     * @brief Find the node with value.
     * @param value The value being found.
     * 
     * @returns 
     * - `MyBST*` if the value was found.
     * 
     * - `nullptr` if the value was not found.
     */
    MyBST* find(int value);

    // Traverse the tree in order.
    void in_order_traverse() const;

    // Traverse the tree in post-order.
    void post_order_traverse() const;

    // Traverse the tree in pre-order.
    void pre_order_traverse() const;

    // Find node with smallest value.
    MyBST* smallest() { return left ? left->smallest() : this; }

    // Find node with biggest value.
    MyBST* biggest() { return right ? right->biggest() : this; }

    // Const reference to the `_value`.
    const int& value() const { return _value; }

private:
    int _value;
    MyBST* parent;
    MyBST* left;
    MyBST* right;

    /**
     * @brief Erase a single node, not the whole subtree.
     * @param node The node you're erasing.
     * 
     * Use this in case you have to remove only a single node.
     * 
     * Before using it, make sure the node is not part of the tree anymore.
     */
    void erase(MyBST* node);
};

#endif
