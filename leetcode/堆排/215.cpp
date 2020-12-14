#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    // Î¬»¤¶Ñ
    void maxHeapify(vector<int>& a,int i,int heapSize){
        int left = i*2+1,right = i*2+2,largest = i;
        if(left < heapSize && a[left] > a[largest]) largest = left;
        if(right < heapSize && a[right] > a[largest]) largest = right;
        if(largest != i){
            swap(a[i],a[largest]);
            maxHeapify(a,largest,heapSize);
        }
    }
    // ½¨¶Ñ
    void buildMaxHeap(vector<int>& a,int heapSize) {
        for(int i = heapSize/2;i>=0;i--){
            maxHeapify(a,i,heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums,heapSize);
        for(int i = nums.size()-1;i>=nums.size()-k+1;i--){
            swap(nums[0],nums[i]);
            --heapSize;
            maxHeapify(nums,0,heapSize);
        }
        return nums[0];
    }
};