class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++) {
            map <pair<int, int>, int> mp;
            for(int j = 0; j < points.size(); j++) {
                if(i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;
                ++mp[{dy, dx}];
                ans = max(ans, mp[{dy, dx}]);
            }
        }
        return ans + 1;
    }
};
