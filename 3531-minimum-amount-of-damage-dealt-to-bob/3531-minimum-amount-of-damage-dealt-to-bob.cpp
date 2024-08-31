class Solution {
public:
long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<int, double>> efficiency(n);

        // Calculate efficiency as damage per total time to defeat
        for (int i = 0; i < n; ++i) {
            efficiency[i] = {i, (double)damage[i] / ((health[i] + power - 1) / power)};
        }

        // Sort by efficiency (higher is better)
        sort(efficiency.begin(), efficiency.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second > b.second;
        });

        long long totalDamage = 0;
        long long elapsedTime = 0;

        // Calculate total damage by processing the most efficient enemies first
        for (int i = 0; i < n; ++i) {
            int idx = efficiency[i].first;
            long long timeToDefeat = (health[idx] + power - 1) / power;
            totalDamage += damage[idx] * (elapsedTime + timeToDefeat);
            elapsedTime += timeToDefeat;
        }

        return totalDamage;
    }
};