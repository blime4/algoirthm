# -*- coding:utf-8 -*-
class Solution:
    # ¿ìÅÅ
    def quick_sort(self,arr,left,right):
        if left > right: return
        i = left
        j = right
        temp = arr[left]
        while i!=j:
            while arr[j]+temp >= temp + arr[j] and i<j:
                j -= 1
            while arr[i]+temp <= temp + arr[i] and i<j:
                i += 1
            if i<j:
                arr[i],arr[j] = arr[j],arr[i]
        arr[left],arr[i] = arr[i],arr[left]
        self.quick_sort(arr,left,i-1)
        self.quick_sort(arr,i+1,right)
        return arr
    # Ï£¶ûÅÅĞò
    def shell_sort(self,arr):
        n = len(arr)
        gap = n//2
        while gap>0:
            for i in range(gap,n):
                tmp = arr[i]
                j = i
                while j>=gap and arr[j-gap]+tmp>tmp+arr[j-gap]:
                    arr[j] = arr[j-gap]
                    j -= gap
                arr[j] = tmp
            gap = gap//2
        return arr
        
    def PrintMinNumber(self, numbers):
        # write code here
        if not numbers: return ""
        s = [str(n) for n in numbers]
        self.quick_sort(s,0,len(s)-1)
        return "".join(s)
