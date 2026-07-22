class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruit_cnt;
        int slow = 0;
        int result = 0;

        for (int fast = 0; fast < fruits.size(); fast++) {
            fruit_cnt[fruits[fast]]++;

            while(fruit_cnt.size() > 2) {
                fruit_cnt[fruits[slow]]--;

                if (fruit_cnt[fruits[slow]] == 0)
                    fruit_cnt.erase(fruits[slow]);
                slow++;
            }

            result = result > (fast - slow + 1) ? result : (fast - slow + 1);
        }

        return result;
    }
};