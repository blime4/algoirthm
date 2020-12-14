题目描述
>

    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

示例1

输入

[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]

返回值


{1,2,5,3,4,6,7}


思路：

就是画图，前序的第一个，就是根，
在中序中找到根，左边的，就是左子树，右边，右子树
然后在前序中把相同长度的左右子树，进行下一轮递归。
看代码



```
class Solution {
public:
    TreeNode* rebuild(vector<int>& pre, int pre_left, int pre_right, vector<int>& vin, int vin_left, int vin_right){
        if(pre_left > pre_right) return nullptr;
        
        TreeNode* root = new TreeNode(pre[pre_left]);
        for(int i=vin_left;i<=vin_right;i++){
            if(vin[i]==root->val){
                root->left = rebuild(pre, pre_left+1, pre_left+i-vin_left,vin,vin_left,i-1);
                root->right = rebuild(pre, pre_left+1+i-vin_left,pre_right,vin,i+1,vin_right);
                break;
            }
        }
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return rebuild(pre,0,pre.size()-1,vin,0,vin.size()-1);
    }
};


