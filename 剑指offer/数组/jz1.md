
��Ŀ����
>

    ��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������



ʾ��1

����

7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]

����ֵ

true


## ˼·

ÿһ���У����ҵ�Ԫ�أ�һ���Ǳ������ġ���һ�����ң���Ϊ��ֵ a

if taget > a ˵������һ�У���++
if taget < a ˵����ǰһ�У���--

���룺
```
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if(m==0) return false;
        int n = array[0].size();
        if(n==0) return false;
        int r=0, c=n-1;  // �����Ͻǿ�ʼ�Ƚ�
        while(r<m && c>=0){
            if(target == array[r][c]) return true;
            if(target > array[r][c]) ++r;
            else --c;
        }
        return false;
    }
};

