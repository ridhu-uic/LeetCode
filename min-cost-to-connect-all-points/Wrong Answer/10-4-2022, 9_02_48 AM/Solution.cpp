// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:

    struct distance{
        int cost;
        map<int,int> dest;
        map<int,int> source;
    };
    struct compare{
        bool operator()(distance d1,distance d2)
        {
            return d1.cost>d2.cost;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        //priority_queue<distance, vector<distance>, compare> pq();

        double x_centroid=0;
        double y_centroid=0;
        double distance=0;
        int n=points.size();

        for(int i=0;i<n;i++)
        {
            x_centroid=x_centroid+points[i][0];
            y_centroid=y_centroid+points[i][1];
        }
        x_centroid=x_centroid/n;
        y_centroid=y_centroid/n;

        for(int i=0;i<n;i++)
        {
            distance=distance+sqrt(pow((points[i][0]-x_centroid),2)+pow((points[i][1]-y_centroid),2));
        }

        return ceil(distance);
    }
};