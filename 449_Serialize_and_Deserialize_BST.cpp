#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        mySerialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data == "") return NULL;
        istringstream in(data);
        return myDeserialize(in);
    }
private:
	void mySerialize(TreeNode* root, ostringstream &out)
	{
		if(root == NULL) return;
		out << root->val << " ";
		mySerialize(root->left, out);
		mySerialize(root->right, out);
	}

	TreeNode* myDeserialize(istringstream &in)
	{
		string val;
		in >> val;
		TreeNode *root = new TreeNode(stoi(val));
		while(in >> val)
			buildTree(root, stoi(val));
		return root;
	}

	void buildTree(TreeNode* root, int n)
	{
		if(root->val > n)
		{
			if(root->left == NULL)
				root->left = new TreeNode(n);
			else
				buildTree(root->left, n);
		}
		else
		{
			if(root->right == NULL)
				root->right = new TreeNode(n);
			else
				buildTree(root->right, n);
		}
	}
};

int main(){
    Codec codec;
    TreeNode* node = codec.deserialize("122 41 24");
    string str = codec.serialize(node);
    cout << str << endl;
}
