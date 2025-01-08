class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1;
        int max_speed = *max_element(piles.begin(), piles.end());
        int ans_speed = min_speed;

        while (min_speed <= max_speed) {
            int speed = (max_speed + min_speed) / 2;

            long long total_hour = 0;

            for (int banana_cnt: piles) {
                double cost_hours = static_cast<double>(banana_cnt) / speed;
                total_hour += (ceil(cost_hours));
            }

            if (total_hour <= h) {
                ans_speed = speed;
                max_speed = speed - 1;
            } else {
                min_speed = speed + 1;
            }
        }

        return ans_speed;
    }
};
