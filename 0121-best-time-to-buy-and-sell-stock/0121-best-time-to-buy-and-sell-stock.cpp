class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for (int price : prices) {
            if (price < buy) {
                buy = price;
            } else if (price - buy > profit)
                profit = price - buy;
        }
        return profit;
    }
 
};