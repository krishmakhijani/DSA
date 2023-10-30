#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(root->data > data){
        root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int findMax(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return -1;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
Node *deleteNodeInBST(Node *root, int target)
{
    // Base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == target)
    {
        // Case 1 : Leaf Node
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        // Case 2 : Left child not exist
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            return child;
        }
        // Case 3 : Right child not exist
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            return child;
        }
        // Case 4 : Both child exists
        else
        {
            int inorderPred = findMax(root->left);
            root->data = inorderPred;
            root->left = deleteNodeInBST(root->left, inorderPred);
            return root;
        }
    }
    else if (root->data < target)
    {
        // right
        root->right = deleteNodeInBST(root->right, target);
    }
    else
    {
        // left
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}
int main(){
    int choice;
    cout << "Enter the choice" << endl;
    cout << "1. Insert into BST" << endl;
    cout << "2. Display BST" << endl;
    cout << "3. Inorder Traversal" << endl;
    cout << "4. Preorder Traversal" << endl;
    cout << "5. Postorder Traversal" << endl;
    cout << "6. Delete" << endl;
    cout << "7. Exit" << endl;
    cin >> choice;
    Node* root = NULL;
    while(true){
        switch(choice){
            case 1:
                cout<<"Enter the data for Node"<<endl;
                takeInput(root);
                break;
            case 2:
                levelOrderTraversal(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                int target;
                cout<<"Enter the target"<<endl;
                cin>>target;
                root = deleteNodeInBST(root,target);
                break;
            default:
                cout<<"Invalid Choice"<<endl;
        }
        cout << "Enter the choice" << endl;
        cout << "1. Insert into BST" << endl;
        cout << "2. Display BST" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Delete" << endl;
        cin >> choice;
    }
    return 0;
}