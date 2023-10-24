#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree(int data)
{
    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root = new Node(data);
    // Recursion will handle
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);
    return root;
}
// Normal Level order traversal

/*
void levelOrderTraversal(Node* root){
    // Empty tree
    if(root == NULL){
        return;
    }
    queue<Node*>q;
    // Push the root in queue
    q.push(root);
    // Run the loop until queue becomes empty
    while(!q.empty()){
        // Fetch front node and then pop
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        // left child exists
        if(temp->left){
            q.push(temp->left);
        }
        // right child exists
        if(temp->right){
            q.push(temp->right);
        }
    }
}
*/

// To print the tree level wise
void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void postOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // Left
    postOrderTraversal(root->left);
    // Right
    postOrderTraversal(root->right);
    // Node
    cout<<root->data<<" ";
}

void preOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // Node
    cout<<root->data<<" ";
    // Left
    preOrderTraversal(root->left);
    // Right
    preOrderTraversal(root->right);
}

void inorderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // Left
    inorderTraversal(root->left);
    // Node
    cout<<root->data<<" ";
    // Right
    inorderTraversal(root->right);
}

int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);
    cout << "Level order traversal is as follows" << endl;
    levelOrderTraversal(root);
    cout << "Post order traversal is as follows" << endl;
    postOrderTraversal(root);
    cout << endl<<"Pre order traversal is as follows" << endl;
    preOrderTraversal(root);
    cout << endl<<"Inorder traversal is as follows" << endl;
    inorderTraversal(root);
    return 0;
}