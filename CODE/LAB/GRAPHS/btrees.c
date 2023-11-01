#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 100

typedef struct node {
    int num_keys;
    int keys[MAX_KEYS];
    struct node *children[MAX_KEYS + 1];
    int is_leaf;
} node;

node *create_node(int order) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->num_keys = 0;
    for (int i = 0; i < MAX_KEYS; i++) {
        new_node->keys[i] = 0;
        new_node->children[i] = NULL;
    }
    new_node->children[MAX_KEYS] = NULL;
    new_node->is_leaf = 1;
    return new_node;
}

void insert(node **root, int key, int order) {
    if (*root == NULL) {
        *root = create_node(order);
        (*root)->keys[0] = key;
        (*root)->num_keys++;
    } else {
        node *current = *root;
        node *parent = NULL;
        int index = -1;
        while (current != NULL && !current->is_leaf) {
            parent = current;
            index = -1;
            for (int i = 0; i < current->num_keys; i++) {
                if (key > current->keys[i]) {
                    index = i;
                } else {
                    break;
                }
            }
            if (index == -1) {
                current = current->children[0];
            } else {
                current = current->children[index + 1];
            }
        }
        if (current == NULL) {
            current = create_node(order);
            parent->children[index + 1] = current;
        }
        int i = current->num_keys - 1;
        while (i >= 0 && current->keys[i] > key) {
            current->keys[i + 1] = current->keys[i];
            i--;
        }
        current->keys[i + 1] = key;
        current->num_keys++;
        if (current->num_keys == MAX_KEYS) {
            int split_index = MAX_KEYS / 2;
            int split_key = current->keys[split_index];
            node *new_node = create_node(order);
            new_node->is_leaf = current->is_leaf;
            for (int i = split_index + 1; i < MAX_KEYS; i++) {
                new_node->keys[i - split_index - 1] = current->keys[i];
                new_node->children[i - split_index - 1] = current->children[i];
            }
            new_node->children[MAX_KEYS - split_index - 1] = current->children[MAX_KEYS];
            current->num_keys = split_index;
            new_node->num_keys = MAX_KEYS - split_index - 1;
            if (parent == NULL) {
                parent = create_node(order);
                *root = parent;
            }
            i = parent->num_keys - 1;
            while (i >= 0 && parent->keys[i] > split_key) {
                parent->keys[i + 1] = parent->keys[i];
                parent->children[i + 2] = parent->children[i + 1];
                i--;
            }
            parent->keys[i + 1] = split_key;
            parent->children[i + 2] = new_node;
            parent->num_keys++;
        }
    }
}

void delete(node **root, int key, int order) {
    if (*root == NULL) {
        return;
    }
    node *current = *root;
    node *parent = NULL;
    int index = -1;
    while (current != NULL && !current->is_leaf) {
        parent = current;
        index = -1;
        for (int i = 0; i < current->num_keys; i++) {
            if (key > current->keys[i]) {
                index = i;
            } else {
                break;
            }
        }
        if (index == -1) {
            current = current->children[0];
        } else {
            current = current->children[index + 1];
        }
    }
    if (current == NULL) {
        return;
    }
    index = -1;
    for (int i = 0; i < current->num_keys; i++) {
        if (current->keys[i] == key) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }
    for (int i = index; i < current->num_keys - 1; i++) {
        current->keys[i] = current->keys[i + 1];
    }
    current->num_keys--;
    if (current == *root) {
        if (current->num_keys == 0) {
            *root = current->children[0];
            free(current);
        }
        return;
    }
    if (current->num_keys >= order / 2) {
        return;
    }
    node *left_sibling = NULL;
    node *right_sibling = NULL;
    int left_index = -1;
    int right_index = -1;
    for (int i = 0; i < parent->num_keys + 1; i++) {
        if (parent->children[i] == current) {
            if (i > 0) {
                left_sibling = parent->children[i - 1];
                left_index = i - 1;
            }
            if (i < parent->num_keys) {
                right_sibling = parent->children[i + 1];
                right_index = i + 1;
            }
            break;
        }
    }
    if (left_sibling != NULL && left_sibling->num_keys > order / 2) {
        for (int i = current->num_keys - 1; i >= 0; i--) {
            current->keys[i + 1] = current->keys[i];
        }
        current->keys[0] = parent->keys[left_index];
        parent->keys[left_index] = left_sibling->keys[left_sibling->num_keys - 1];
        current->num_keys++;
        left_sibling->num_keys--;
        current->children[1] = current->children[0];
        current->children[0] = left_sibling->children[left_sibling->num_keys];
        left_sibling->children[left_sibling->num_keys] = NULL;
    } else if (right_sibling != NULL && right_sibling->num_keys > order / 2) {
        current->keys[current->num_keys] = parent->keys[index];
        parent->keys[index] = right_sibling->keys[0];
        current->num_keys++;
        right_sibling->num_keys--;
        current->children[current->num_keys] = right_sibling->children[0];
        for (int i = 0; i < right_sibling->num_keys; i++) {
            right_sibling->keys[i] = right_sibling->keys[i + 1];
            right_sibling->children[i] = right_sibling->children[i + 1];
        }
        right_sibling->children[right_sibling->num_keys] = right_sibling->children[right_sibling->num_keys + 1];
        right_sibling->children[right_sibling->num_keys + 1] = NULL;
    } else if (left_sibling != NULL) {
        left_sibling->keys[left_sibling->num_keys] = parent->keys[left_index];
        for (int i = 0; i < current->num_keys; i++) {
            left_sibling->keys[left_sibling->num_keys + 1 + i] = current->keys[i];
            left_sibling->children[left_sibling->num_keys + 1 + i] = current->children[i];
        }
        left_sibling->children[left_sibling->num_keys + current->num_keys + 1] = current->children[current->num_keys];
        left_sibling->num_keys += current->num_keys + 1;
        for (int i = left_index + 1; i < parent->num_keys; i++) {
            parent->keys[i - 1] = parent->keys[i];
            parent->children[i] = parent->children[i + 1];
        }
        parent->num_keys--;
        free(current);
    } else if (right_sibling != NULL) {
        current->keys[current->num_keys] = parent->keys[index];
        for (int i = 0; i < right_sibling->num_keys; i++) {
            current->keys[current->num_keys + 1 + i] = right_sibling->keys[i];
            current->children[current->num_keys + 1 + i] = right_sibling->children[i];
        }
        current->children[current->num_keys + right_sibling->num_keys + 1] = right_sibling->children[right_sibling->num_keys];
        current->num_keys += right_sibling->num_keys + 1;
        for (int i = right_index; i < parent->num_keys; i++) {
            parent->keys[i - 1] = parent->keys[i];
            parent->children[i] = parent->children[i + 1];
        }
        parent->num_keys--;
        free(right_sibling);
    }
    delete(root, key, order);
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    int i;
    for (i = 0; i < root->num_keys; i++) {
        inorder_traversal(root->children[i]);
        printf("%d ", root->keys[i]);
    }
    inorder_traversal(root->children[i]);
}

void postorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    int i;
    for (i = 0; i < root->num_keys; i++) {
        postorder_traversal(root->children[i]);
    }
    postorder_traversal(root->children[i]);
    for (i = 0; i < root->num_keys; i++) {
        printf("%d ", root->keys[i]);
    }
}

void preorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    int i;
    for (i = 0; i < root->num_keys; i++) {
        printf("%d ", root->keys[i]);
        preorder_traversal(root->children[i]);
    }
    preorder_traversal(root->children[i]);
}

void printtree(node *root) {
    //print in the form of tree

    if (root == NULL) {
        return;
    }
    int i;
    for (i = 0; i < root->num_keys; i++) {
        printtree(root->children[i]);
        printf("%d ", root->keys[i]);
    }
    printtree(root->children[i]);
    
}

node *search(node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    int i = 0;
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }
    if (i < root->num_keys && key == root->keys[i]) {
        return root;
    }
    if (root->is_leaf) {
        return NULL;
    }
    return search(root->children[i], key);
}

int main() {
    node *root = NULL;
    int order, choice, key;
    printf("Enter the order of the B-Tree: ");
    scanf("%d", &order);
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Print Tree \n5. Inorder \n6.pre Order\n7.Post Order\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of keys : ");
                int n;
                scanf("%d", &n);
                printf("Enter the key to insert: ");
                for(int i=0;i<n;i++){
                scanf("%d", &key);
                insert(&root, key, order);}
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                delete(&root, key, order);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Key found\n");
                } else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                printtree(root);
                break;
            case 5:
                inorder_traversal(root);
                break;
            case 6:
                preorder_traversal(root);
                break;
            case 7:
                postorder_traversal(root);
                break;
            default:
                exit(0);

        }
    }
    return 0;
}