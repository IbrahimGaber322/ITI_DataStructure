// binary_tree.h

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <class T>
class Nodeb
{
public:
    T data;
    Nodeb<T> *left;
    Nodeb<T> *right;

    Nodeb(T _data) : data(_data), left(nullptr), right(nullptr) {}
    ~Nodeb() {}
};
template <class T>
class BinaryTree
{
private:
    Nodeb<T> *root;

    // Helper method for recursive insertion
    void insertRecursive(Nodeb<T> *&node, T value)
    {
        if (node == nullptr)
        {
            // If the node is null, create a new node with the given value
            node = new Nodeb<T>(value);
        }
        else
        {
            // Decide whether to insert into the left or right subtree based on the value
            if (value < node->data)
            {
                insertRecursive(node->left, value);
            }
            else
            {
                insertRecursive(node->right, value);
            }
        }
    }

    // Helper method for recursive in-order traversal
    void inOrderTraversalRecursive(Nodeb<T> *node)
    {
        if (node != nullptr)
        {
            // Traverse the left subtree
            inOrderTraversalRecursive(node->left);
            // Print the current node's data
            cout << node->data << " ";
            // Traverse the right subtree
            inOrderTraversalRecursive(node->right);
        }
    }

    // Helper method for recursive search
    bool searchRecursive(Nodeb<T> *node, T value)
    {
        if (node == nullptr)
        {
            // If the node is null, the value is not found
            return false;
        }

        // Check if the current node contains the value
        if (node->data == value)
        {
            return true;
        }
        else if (value < node->data)
        {
            // Search in the left subtree
            return searchRecursive(node->left, value);
        }
        else
        {
            // Search in the right subtree
            return searchRecursive(node->right, value);
        }
    }

    // Helper method for recursive node deletion
    Nodeb<T> *removeRecursive(Nodeb<T> *node, T value)
    {
        if (node == nullptr)
        {
            // If the node is null, the value is not in the tree
            return nullptr;
        }

        // Decide whether to go left or right based on the value
        if (value < node->data)
        {
            node->left = removeRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeRecursive(node->right, value);
        }
        else
        {
            // Node to be deleted found

            // Case 1: No child or one child
            if (node->left == nullptr)
            {
                Nodeb<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Nodeb<T> *temp = node->left;
                delete node;
                return temp;
            }

            // Case 2: Two children
            Nodeb<T> *temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }

        return node;
    }

    // Helper method to find the minimum value node in a subtree
    Nodeb<T> *findMin(Nodeb<T> *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public method to insert a value into the binary tree
    void insert(T value)
    {
        insertRecursive(root, value);
    }

    // Public method to perform in-order traversal of the binary tree
    void inOrderTraversal()
    {
        inOrderTraversalRecursive(root);
        cout << endl;
    }

    // Public method to search for a value in the binary tree
    bool search(T value)
    {
        return searchRecursive(root, value);
    }

    // Public method to delete a value from the binary tree
    void remove(T value)
    {
        root = removeRecursive(root, value);
    }
};

#endif // BINARY_TREE_H