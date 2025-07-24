#ifndef BINARY_TREE_SORT_H
#define BINARY_TREE_SORT_H

template <typename T>
struct TreeNode
{
    T _value;
    TreeNode *_left;
    TreeNode *_right;
    TreeNode(const T &value) : _value(value), _left(nullptr), _right(nullptr) {}
};

template <typename T>
bool InsertTreeNode(TreeNode<T> *&node, const T &value)
{
    if (!node)
    {
        node = new TreeNode<T>(value);
        return true;
    }

    else if (value < node->_value)
    {
        return InsertTreeNode(node->_left, value);
    }

    else if (node->_value < value)
    {
        return InsertTreeNode(node->_right, value);
    }

    return false;
}

template <typename T>
void RoundLrootR(TreeNode<T> *node, T *arr, int index)
{
    if (node)
    {
        RoundLrootR(node->_left, arr, index);
        arr[index++] = node->_value;
        RoundLrootR(node->_right, arr, index);
    }
}

template <typename T>
void BinaryTreeSort(T *arr, int size)
{
    TreeNode<T> *_root = nullptr;

    for (int i = 0; i < size; i++)
    {
        InsertTreeNode(_root, arr[i]);
    }

    RoundLrootR(_root, arr, 0);
}

#endif
