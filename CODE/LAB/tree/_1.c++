#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildtree(const vector<int>& levelOrder) {
    if (levelOrder.empty())
        return nullptr;

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    for (int i = 1; i < levelOrder.size(); i += 2) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->left = new TreeNode(levelOrder[i]);
            nodeQueue.push(current->left);
        }

        if (i + 1 < levelOrder.size() && levelOrder[i + 1] != -1) {
            current->right = new TreeNode(levelOrder[i + 1]);
            nodeQueue.push(current->right);
        }
    }

    return root;
}
void levelOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
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

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

void preorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr)
        return;

    result.push_back(root->data);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}

void postorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr)
        return;

    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->data);
}

int main() {
    int choice;
    cout << "Enter 1 to build tree from level order traversal" << endl;
    cout << "Enter 2 to print level order traversal" << endl;
    cout << "Enter 3 to print inorder traversal" << endl;
    cout << "Enter 4 to print preorder traversal" << endl;
    cout << "Enter 5 to print postorder traversal" << endl;
    cout << "Enter 6 to exit" << endl;
    cin >> choice;
    vector<int> levelOrder;

    while (choice != 6) {
        switch (choice) {
        case 1: {
            int n;
            cout << "Enter number of nodes" << endl;
            cin >> n;
            cout << "Enter level order traversal" << endl;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                levelOrder.push_back(x);
            }
            break;
        }
        case 2: {
            TreeNode* root = buildtree(levelOrder);
            cout << "Level order traversal is as follows" << endl;
            levelOrderTraversal(root);
            break;
        }
        case 3: {
            TreeNode* root = buildtree(levelOrder);
            vector<int> result;
            inorderTraversal(root, result);
            cout << "Inorder traversal is as follows" << endl;
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        }
        case 4: {
            TreeNode* root = buildtree(levelOrder);
            vector<int> result;
            preorderTraversal(root, result);
            cout << "Preorder traversal is as follows" << endl;
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        }
        case 5: {
            TreeNode* root = buildtree(levelOrder);
            vector<int> result;
            postorderTraversal(root, result);
            cout << "Post order traversal is as follows" << endl;
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            cout << endl;
            break;

}

        default:
            cout << "Invalid choice" << endl;
        }
        cout << "Enter choice" << endl;
        cin >> choice;
    }
    return 0;
}