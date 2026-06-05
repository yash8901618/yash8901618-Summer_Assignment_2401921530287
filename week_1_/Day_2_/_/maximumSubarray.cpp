#include<iostream>
#include<vector>
using  namespace std;
 
 
 int maxSubArray(vector<int>& nums) {
        int sum=0;
       int n=nums.size();
       int arrstart=-1;
       int arrend=-1;
       int maxi=INT_MIN;
       int start=0;

       for(int i=0;i<n;i++){
        if (sum==0)  start =i;
        sum+=nums[i];

        if (sum>maxi){
            maxi=sum;
            arrstart=start,arrend=i;
        }
        if (sum<0){
             sum=0;
        } 
        // if (maxi<0)  {
        //     maxi=0;
        // } 
        
       }
    return maxi;

    }