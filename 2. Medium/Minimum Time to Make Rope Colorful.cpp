class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mxTime = neededTime[0], sumTime = neededTime[0];
        int totalNeededTime = 0;
        bool haveToRemove = false;
        for(int i = 1; i < colors.size(); i++) {
            if(colors[i] == colors[i-1]) {
                haveToRemove = true;
                mxTime = max(mxTime, neededTime[i]);
                sumTime += neededTime[i];
            }
            else {
                if(haveToRemove) totalNeededTime += (sumTime - mxTime);
                mxTime = neededTime[i];
                sumTime = neededTime[i];
                haveToRemove = false;
            }
        }
        
        if(haveToRemove) totalNeededTime += (sumTime - mxTime);
        return totalNeededTime;
    }
};
