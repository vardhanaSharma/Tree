#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}
void printPathsRecur(node* node, int path[], int pathLen)
{
    if (node == NULL)
        return;
    path[pathLen] = node->data;
    pathLen++;
     
    if (node->left == NULL && node->right == NULL)
    {//check for leaf node
        printArray(path, pathLen);
    }
    else
    {
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}

void printPaths(node* node)
{
    int path[1000];
    printPathsRecur(node, path, 0);
}
 
int main() {

    node* root = NULL;
    // root = buildTree(root);

    buildFromLevelOrder(root);
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    cout<<"ROOT TO LEAF PATH"<<endl;
    // mainFunc(root);
    printPaths(root);

    return 0;
}