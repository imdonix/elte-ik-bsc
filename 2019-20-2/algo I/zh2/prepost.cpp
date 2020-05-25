#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class node
{
    public:
    string data;
    node* left;
    node* right;

    node(string data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

int search(vector<string> arr, int strt, int end, string value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

node* prebuildTree(vector<string> in, vector<string> pre, int inStrt, int inEnd)
{
    static int preIndex = 0;
    if (inStrt > inEnd)
        return NULL;
    node* tNode = new node(pre[preIndex++]);
    if (inStrt == inEnd)
        return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->left = prebuildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = prebuildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}

void postorder(node* tree)
{
    if(tree!=nullptr)
    {
        postorder(tree->left);
        postorder(tree->right);
        cout<<tree->data<<" ";
    }
}

node* postbuildTree(vector<string> in, vector<string> post, int inStrt, int inEnd)
{
    static int pIndex=post.size()-1;
    if (inStrt > inEnd)
        return NULL;
    node* tNode = new node(post[pIndex--]);

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
    int iIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->right = postbuildTree(in, post, iIndex + 1, inEnd);
    tNode->left = postbuildTree(in, post, inStrt, iIndex - 1);
    return tNode;
}

void preorder(node* tree)
{
    if(tree!=nullptr)
    {
        cout<<tree->data<<" ";
        preorder(tree->left);
        preorder(tree->right);
    }
}

int main()
{
    vector<string> inorder;
    cout<<"Inorder: ";
    string input;
    getline(cin,input);
    stringstream ss(input);
    string s;
    ss>>s;
    inorder.push_back(s);
    while(!ss.fail())
    {
        ss>>s;
        if(!ss.fail())
            inorder.push_back(s);
    }

    cout<<"pre/post: ";
    string prepost;
    getline(cin,prepost);

    if(prepost=="pre")
    {
        vector<string> preorder;
        cout<<"Preorder: ";
        getline(cin,input);
        stringstream ss(input);
        ss>>s;
        preorder.push_back(s);
        while(!ss.fail())
        {
            ss>>s;
            if(!ss.fail())
                preorder.push_back(s);
        }
        node* tree=prebuildTree(inorder,preorder,0,preorder.size()-1);
        cout<<"Postorder: ";
        postorder(tree);
    }

    else if(prepost=="post")
    {
        vector<string> postorder;
        cout<<"Postorder: ";
        getline(cin,input);
        stringstream ss(input);
        ss>>s;
        postorder.push_back(s);
        while(!ss.fail())
        {
            ss>>s;
            if(!ss.fail())
                postorder.push_back(s);
        }
        node* tree=postbuildTree(inorder,postorder,0,postorder.size()-1);
        cout<<"Preorder: ";
        preorder(tree);
    }

    else
    {
        cout<<"Hiba";
    }
    return 0;
}
