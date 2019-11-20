/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::updateHeight(Node*& subroot) {
    subroot->height = max(heightOrNeg1(subroot->left), heightOrNeg1(subroot->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node * x = t;
    Node * y = t->right;

    x->right = y->left;
    y->left = x;
    t = y;

    updateHeight(x);
    updateHeight(y);
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node * x = t;
    Node * y = t->left;

    x->left = y->right;
    y->right = x;
    t = y;

    updateHeight(x);
    updateHeight(y);
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left) < -1) {
      int left_balance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
      if (left_balance == -1) rotateRight(subtree);
      else rotateLeftRight(subtree);
    } else if (heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left) > 1) {
      int right_balance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
      if (right_balance == 1) rotateLeft(subtree);
      else rotateRightLeft(subtree);
    }
    updateHeight(subtree);
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (!subtree) subtree = new Node(key, value);
    else if (key < subtree->key) insert(subtree->left, key, value);
    else if (key > subtree->key) insert(subtree->right, key, value);
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    V const * value;
    if (subtree == NULL) return;
    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
        rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = nullptr;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node * curr = subtree;
            Node * iop = subtree->left;
            while (iop->right) {
              curr = iop;
              iop = iop->right;
            }
            swap(subtree, iop);
            Node * temp = iop;
            curr->right = iop->left;
            delete temp;
        } else {
            /* one-child remove */
            // your code here
            if (!subtree->left && subtree->right) {
              Node * temp = subtree;
              subtree = subtree->right;
              delete temp;
            } else if (subtree->left && !subtree->right) {
              Node * temp = subtree;
              subtree = subtree->left;
              delete temp;
            }
        }
        // your code here
    }
}
