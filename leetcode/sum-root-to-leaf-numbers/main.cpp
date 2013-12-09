
#define NULL 0

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int sumNumbers(TreeNode *root) {
		if (!root)return 0;
		return compute_tree_internal(root,0);
    }
	
	int compute_tree_internal(TreeNode* root, int val){
		val*=10;val+=root->val;
		int sum = 0;
		if (root->left) sum += compute_tree_internal(root->left,val);
		if (root->right) sum+= compute_tree_internal(root->right,val);
		return sum?sum:val;
	}
};

int main(){return 0;}