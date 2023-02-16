// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* maketree(vector<int>& inorder, int in_st, int in_en, vector<int>& postorder, int post_st, int post_en, map<int, int>&inorder_position){
        if(in_st>in_en || post_st>post_en){return NULL;}
        TreeNode* root= new TreeNode(postorder[post_en]);
        int pos=inorder_position[postorder[post_en]];
        int rght=pos-in_st;
        root->left=maketree(inorder, in_st, pos-1, postorder, post_st, post_st+rght-1, inorder_position);
        root->right=maketree(inorder, pos+1, in_en, postorder, post_st+rght, post_en-1, inorder_position);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map <int, int> inorder_position;
        for(int i=0; i<inorder.size(); i++){inorder_position[inorder[i]]=i;}
        TreeNode* root=maketree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inorder_position);
        return root;
    }

};