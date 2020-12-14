/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
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
思路：
转换成string，利用string的排序。自定义排序的方法，


lambda使用

[](string a, string b){
    return a+b<b+a;
}
*/