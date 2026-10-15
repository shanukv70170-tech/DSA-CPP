// Binary Search approach
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // Find the maximum number of candies in any pile
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int answer = 0;
        
        // Binary search for the maximum possible candies per child
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long count = 0;
            
            // Count how many children can get 'mid' candies
            for (int pile : candies) {
                count += pile / mid;
            }
            
            // If enough children can get 'mid' candies, try for more
            if (count >= k) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};

// Heap (Priority Queue) approach
#include <queue>
class Solution2 {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // Use a max heap to always split the largest pile
        priority_queue<int> maxHeap(candies.begin(), candies.end());
        int answer = 0;
        
        // Try all possible pile sizes from largest to smallest
        for (int size = maxHeap.top(); size >= 1; --size) {
            long long count = 0;
            for (int pile : candies) {
                count += pile / size;
            }
            if (count >= k) {
                return size;
            }
        }
        return 0;
    }
};

// Brute Force approach
class Solution3 {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // Try all possible pile sizes from 1 up to the largest pile
        int maxPile = *max_element(candies.begin(), candies.end());
        for (int size = maxPile; size >= 1; --size) {
            long long count = 0;
            for (int pile : candies) {
                count += pile / size;
            }
            if (count >= k) {
                return size;
            }
        }
        return 0;
    }
};