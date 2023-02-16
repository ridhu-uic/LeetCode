// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	// Union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph {
	vector <pair<int, pair <int,int>> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	void addEdge(int cost, pair<int, int> source_dest)
	{
		edgelist.push_back({cost, source_dest});
	}

	int kruskals_mst()
	{
		sort(edgelist.begin(), edgelist.end());
        DSU s(V);
        int sum=0;
        int cost=0;
        for (auto edge : edgelist) {
            cost=edge.first;
            int a = edge.second.first;
            int b = edge.second.second;

            if(s.find(a)!=s.find(b))
            {
                s.unite(a,b);
                sum=sum+cost;
            }


        }
        return sum;
	}
};
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)  // edge case 
            return 0;
        //no of edges = n-1*n/2
        int no_edges=(n-1)*n/2;
        Graph g(no_edges);
         // find distances from each pair of points
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                    int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    g.addEdge(d,make_pair(i,j));
            }
        }
        return g.kruskals_mst();
        

    }
};