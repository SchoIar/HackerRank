#include <iostream>
#include <cstddef>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    // Height: Check if children, if none, return, else, return height
    int getHeight(Node *root)
    {
        int heightCount = 0; // base height
        if (root == NULL)
        {
            return -1; // error: No tree.
        }
        
        //check sides.
        Node* tempNode = root;

        if(tempNode->right == NULL && tempNode->left == NULL){
            //Found a root node, check other nodes. Also base case (Only root node)
        }else if(tempNode->right != NULL && tempNode->left != NULL){
            //L & R child
        }else if(tempNode->left != NULL){
            //thus has exclusively a left child
        }else if(tempNode->right != NULL){
            //Exclusive right child
        }

        return 0;
    }

    int heightHelper(Node *temp){
        return 0;
    }

}; // End of Solution

int main()
{
    Solution myTree;
    Node *root = NULL;
    int t;
    int data;

    cin >> t;

    while (t-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}