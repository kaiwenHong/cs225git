#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    if (!root) return nullptr;
    unsigned i;
    for (i = 0; i < root->elements_.size(); i++) {
      if (root->elements_[i] < key) continue;
      if (root->elements_[i] > key) break;
      if (root->elements_[i] == key) return root;
    }
    if(!root->is_leaf_) return find(root->children_[i], key);
    return nullptr;
}
