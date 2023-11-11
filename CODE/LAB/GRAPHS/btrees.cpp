
#include <iostream>
#include <vector>
#include <queue>

class BTreeNode {
  bool leaf;
  std::vector<int> keys;
  std::vector<BTreeNode *> children;

public:
  BTreeNode(bool leaf_node = true) {
    leaf = leaf_node;
  }

  int getHeight() {
    if (leaf) {
      return 1;
    } else {
      return 1 + children[0]->getHeight();
    }
  }

  void traverse() {
    if (keys.empty()) {
      std::cout << "The B-Tree is empty." << std::endl;
      return;
    }

    std::queue<BTreeNode *> q;
    q.push(this);

    int level = 1;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;

    while (!q.empty()) {
      BTreeNode *current = q.front();
      q.pop();
      nodesInCurrentLevel--;

      std::cout << "| ";
      for (int i = 0; i < current->keys.size(); i++) {
        std::cout << current->keys[i];

        if (i != current->keys.size() - 1)
          std::cout << ", ";
      }

      if (!current->leaf) {
        for (int i = 0; i <= current->children.size(); i++) {
          if (current->children[i] != nullptr) {
            q.push(current->children[i]);
            nodesInNextLevel++;
          }
        }
      }

      if (nodesInCurrentLevel == 0) {
        std::cout << std::endl;
        level++;
        nodesInCurrentLevel = nodesInNextLevel;
        nodesInNextLevel = 0;
      }
    }
  }

  BTreeNode *search(int key) {
    int i = 0;
    while (i < keys.size() && key > keys[i])
      i++;

    if (keys[i] == key)
      return this;

    if (leaf)
      return nullptr;

    return children[i]->search(key);
  }

  void insert(int key) {
    if (leaf) {
      int i = 0;
      while (i < keys.size() && key > keys[i])
        i++;
      keys.insert(keys.begin() + i, key);
    } else {
      int i = 0;
      while (i < keys.size() && key > keys[i])
        i++;
      children[i]->insert(key);
    }
  }

  friend class BTree;
};

class BTree {
  BTreeNode *root;
  int t;

public:
  BTree(int degree) {
    root = nullptr;
    t = degree;
  }

  void traverse() {
    if (root != nullptr)
      root->traverse();
  }

  BTreeNode *search(int key) {
    return (root == nullptr) ? nullptr : root->search(key);
  }

  void insert(int key) {
    if (root == nullptr) {
      root = new BTreeNode(true);
      root->keys.push_back(key);
    } else {
      if (root->keys.size() == (2 * t - 1)) {
        BTreeNode *new_root = new BTreeNode(false);
        new_root->children.push_back(root);
        split_child(new_root, 0, root);
        insert_non_full(new_root, key);
        root = new_root;
      } else {
        insert_non_full(root, key);
      }
    }
  }

private:
  void split_child(BTreeNode *parent, int index, BTreeNode *child) {
    BTreeNode *new_node = new BTreeNode(child->leaf);
    parent->keys.insert(parent->keys.begin() + index, child->keys[t - 1]);
    parent->children.insert(parent->children.begin() + index + 1, new_node);

    new_node->keys.assign(child->keys.begin() + t, child->keys.end());
    child->keys.resize(t - 1);

    if (!child->leaf) {
      new_node->children.assign(child->children.begin() + t, child->children.end());
      child->children.resize(t);
    }
  }

  void insert_non_full(BTreeNode *node, int key) {
    int i = node->keys.size() - 1;
    if (node->leaf) {
      node->keys.resize(node->keys.size() + 1);

      while (i >= 0 && key < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        i--;
      }

      node->keys[i + 1] = key;
    } else {
      while (i >= 0 && key < node->keys[i])
        i--;

      i++;
      if (node->children[i]->keys.size() == (2 * t - 1)) {
        split_child(node, i, node->children[i]);
        if (key > node->keys[i])
          i++;
      }
      insert_non_full(node->children[i], key);
    }
  }
};

void printMenu() {
  std::cout << "B-tree Operations:" << std::endl;
  std::cout << "1. Insert a key" << std::endl;
  std::cout << "2. Search for a key" << std::endl;
  std::cout << "3. Print the B-tree as a tree (Level Order)" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << "Enter your choice: ";
}

int main() {
  BTree btree(3);

  int choice, key;
  do {
    printMenu();
    std::cin >> choice;

    switch (choice) {
    case 1:
      std::cout << "Enter a key to insert: ";
      std::cin >> key;
      btree.insert(key);
      std::cout << "Key inserted successfully." << std::endl;
      break;
    case 2:
      std::cout << "Enter a key to search: ";
      std::cin >> key;
      if (btree.search(key) != nullptr)
        std::cout << "Key found." << std::endl;
      else
        std::cout << "Key not found." << std::endl;
      break;
    case 3:
      std::cout << "B-tree as a tree (Level Order):" << std::endl;
      btree.traverse();
      std::cout << std::endl;
      break;
    case 4:
      std::cout << "Exiting program..." << std::endl;
      break;
    default:
      std::cout << "Invalid choice. Please enter a valid option." << std::endl;
    }

    std::cout << std::endl;
  } while (choice != 4);

  return 0;
}
