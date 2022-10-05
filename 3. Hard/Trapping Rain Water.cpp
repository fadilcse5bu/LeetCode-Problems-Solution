class Solution {
public:
    int trap(vector<int>& height) {
        vector <int> cSum;
        cSum.push_back(height[0]);
        for(int i = 1; i < height.size(); i++) {
            cSum.push_back(height[i] + cSum[i-1]);
        }

        stack <pair<int, int>> stk;
        stk.push({height[0], 0});
        vector <int> ans;
        ans.push_back(0);
        for(int i = 1; i < height.size(); i++) {
            int indx = -1;
            while(1) {
                if(stk.empty()) break;
                pair<int, int> p = stk.top();
                indx = p.second;
                if(p.first > height[i]) break;
                stk.pop();
            }
            if(indx == -1) ans.push_back(ans[i-1]);
            else {
                int df = min(height[indx], height[i]);
                int cell = cSum[i-1] - cSum[indx];
                ans.push_back(ans[indx] + (df * (i - indx - 1)) - (cSum[i-1] - cSum[indx]));
            }

            stk.push({height[i], i});
        }
        return ans[height.size() - 1];
    }
};
