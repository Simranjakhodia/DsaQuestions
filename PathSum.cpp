class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> paths;
       vector<int>path;
       findPath(root, targetSum, path, paths);
       return paths; 
    }
    
    void findPath(TreeNode* root, int sum, vector<int>& path, vector<vector<int>> &paths){
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left && !root->right && sum == root -> val)
            paths.push_back(path);
        
        findPath(root->left , sum - root->val , path , paths);
        findPath(root->right , sum - root->val , path , paths);
        path.pop_back();
    }
};
