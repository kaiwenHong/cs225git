#include <vector>
#include "BTreeNode.h"

void traverse(BTreeNode* root, std::vector<int> &v) {
  unsigned i;
  for (i = 0; i < root->elements_.size(); i++) {
    if (!root->is_leaf_) traverse(root->children_[i], v);
    v.push_back(root->elements_[i]);
  }
  if (!root->is_leaf_) traverse(root->children_[i], v);
}

std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    traverse(root, v);
    return v;
}
