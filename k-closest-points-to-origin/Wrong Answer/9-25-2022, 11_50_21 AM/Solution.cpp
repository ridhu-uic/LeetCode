// https://leetcode.com/problems/k-closest-points-to-origin

typedef pair<int,vector<int>> pi;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> p_queue;
        int n=points.size();
        vector <int> point;
        int distance;
        for(int i=0;i<n;i++)
        {
            point=points[i];
            distance=point[0]*point[0]+point[1]*point[1];
            p_queue.push(make_pair(distance,point));
        }
        vector <vector<int>> k_points;
        for(int i=0;i<k;i++)
        {
            pair<int,vector<int>> pair=p_queue.top();
            k_points.push_back(pair.second);
        }
        return k_points;
    }
};