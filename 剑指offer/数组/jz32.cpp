/*
����һ�����������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}��
���ӡ���������������ųɵ���С����Ϊ321323��
*/

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str;
        for(int i:numbers) str.push_back(to_string(i));
        sort(str.begin(), str.end(),[](string a,string b){
            return a+b<b+a;
        });
        string ans = "";
        for(string i:str) ans+=i;
        return ans;
    }
};

/*
˼·��
ת����string������string�������Զ�������ķ�����


lambdaʹ��

[](string a, string b){
    return a+b<b+a;
}
*/