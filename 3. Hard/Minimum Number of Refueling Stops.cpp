class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long int p = 0, curr_fuel = startFuel;
        int cnt = 0;
        priority_queue <int> pq;
        while(1) {
            if(curr_fuel >= target) {
                break;
            }
            while(p < stations.size()) {
                if(stations[p][0] <= curr_fuel) {
                    pq.push(stations[p][1]);
                    ++p;
                }
                else {
                    break;
                }
            }
            if(pq.empty()) {
                return -1;
            }
            curr_fuel += pq.top();
            ++cnt;
            pq.pop();
        }
        return cnt;
    }
};
