��Ŀ����
>

    ����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

ʾ��1

����

[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]

����ֵ


{1,2,5,3,4,6,7}


˼·��

���ǻ�ͼ��ǰ��ĵ�һ�������Ǹ���
���������ҵ�������ߵģ��������������ұߣ�������
Ȼ����ǰ���а���ͬ���ȵ�����������������һ�ֵݹ顣
������



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


