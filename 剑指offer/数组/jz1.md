
题目描述
>

    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。



示例1

输入

7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]

返回值

true


## 思路

每一列中，最右的元素，一定是本列最大的。第一行最右，设为初值 a

if taget > a 说明在下一行，行++
if taget < a 说明在前一列，列--

代码：
```
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if(m==0) return false;
        int n = array[0].size();
        if(n==0) return false;
        int r=0, c=n-1;  // 从右上角开始比较
        while(r<m && c>=0){
            if(target == array[r][c]) return true;
            if(target > array[r][c]) ++r;
            else --c;
        }
        return false;
    }
};

