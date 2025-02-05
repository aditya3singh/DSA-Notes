#include<bits/stdc++.h>
using namespace std;

int fromoneton( int n){
    if( n ==0 ) return 0;

    cout<< n<<endl;
    fromoneton( n-1);
}

int main(){
    int n;
    cin>> n;
    int i= 1;
    cout<< fromoneton(n);
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int mini = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

