/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node* subRoot)
{
    if (subRoot == NULL) return;
    mirror(subRoot->left);
    mirror(subRoot->right);
    Node* temp = subRoot->left;
    subRoot->left = subRoot->right;
    subRoot->right = temp;

}

/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    if(root == nullptr) return true;
    Node* curr = root;
    Node* prev = nullptr;
    Node* parent = nullptr;
    bool ordered = true;

    while(curr != nullptr) {
      if(curr->left == nullptr) {
        if(parent != nullptr && parent->elem >= curr->elem) ordered = false;
        parent = curr;
        curr = curr->right;
      } else {
        prev = curr->left;
        while(prev->right != nullptr && prev->right != curr) prev = prev->right;
        if(prev->right == nullptr) {
          prev->right = curr;
          curr = curr->left;
        } else {
          prev->right = nullptr;
          if(parent->elem >= curr->elem) ordered = false;
          parent = curr;
          curr = curr->right;
        }
      }
    }

    return ordered;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
//    return isOrderedRecursive(root);
  InorderTraversal<int> iot(getRoot());
  TreeTraversal<int>::Iterator it = iot.begin();
  return iot.recursiveHelper(it);
}

// template <typename T>
// bool BinaryTree<T>::isOrderedRecursive(const Node* subRoot) const
// {
//     if(subRoot == NULL) return true;
//     if(subRoot->left != NULL && subRoot->elem < subRoot->left->elem) return false;
//     if(subRoot->right != NULL && subRoot->elem > subRoot->right->elem) return false;
//     return isOrderedRecursive(subRoot->left) && isOrderedRecursive(subRoot->right);
//
// }


/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::getPaths(vector<vector<T> > &paths) const
{
    vector<T> temp;
    getPaths(paths, temp, root);
}

template <typename T>
void BinaryTree<T>::getPaths(vector<vector<T> > &paths, vector<T> temp, const Node* subRoot) const
{
    temp.insert(temp.end(), subRoot->elem);
    if(subRoot->left == NULL && subRoot->right == NULL) paths.insert(paths.end(), temp);
    if(subRoot->left != NULL) getPaths(paths, temp, subRoot->left);
    if(subRoot->right != NULL) getPaths(paths, temp, subRoot->right);
}

/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    unsigned sum = 0;
    sumDistances(root, sum, 0);
    return sum;
}

template <typename T>
void BinaryTree<T>::sumDistances(const Node* subRoot, unsigned& sum, unsigned distance) const
{
    if(subRoot == nullptr) return;
    sum += distance;
    distance++;
    sumDistances(subRoot->left, sum, distance);
    sumDistances(subRoot->right, sum, distance);
}
