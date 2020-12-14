#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int get_mid(vector<int>& arr,int left,int right){
        int pivot = arr[left];
        while(left < right){
            // 由大到小
            while(arr[right]>= pivot && left < right) right--;
            arr[left] = arr[right];
            while(arr[left]<= pivot && left<right) left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        return left;
    }
    // 快排
    void quick_sort(vector<int>& arr, int left, int right){
        if(left < right){
            int mid = get_mid(arr, left, right);
            quick_sort(arr, left,mid-1);
            quick_sort(arr,mid+1,right);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums,0,nums.size()-1);
        return nums[k];
    }
};