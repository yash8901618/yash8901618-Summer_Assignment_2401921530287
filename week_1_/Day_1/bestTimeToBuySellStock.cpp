 
#include<iostream>
#include<vector>
using  namespace std;

 int maxProfit(vector<int>& prices) {
        int n=prices.size();

       int   maxprofit=0;
       int bestbuy=prices[0];

       for(int i=1;i<n; i++){
        if (prices[i]> bestbuy){
            maxprofit=max(maxprofit,prices[i]-bestbuy);
        }
         bestbuy=min(bestbuy,prices[i]);
       }
      return maxprofit;  
    }