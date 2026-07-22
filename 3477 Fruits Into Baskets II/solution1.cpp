class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = baskets.size();
        for (int i = 0; i < fruits.size(); i++) {
            for (int j = 0; j < baskets.size(); j++) {
                if (fruits[i] <= baskets[j]) {
                    baskets[j] = 0;
                    cnt--;
                    break;
                }
            }
        }

        return cnt;
    }
};