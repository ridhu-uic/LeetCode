// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
class Disjointset {
	//parent
    int* p;
    //rank
	int* r;

public:
	Disjointset(int n)
	{
		p = new int[n];
		r = new int[n];

		for (int i = 0; i < n; i++) {
			p[i] = -1;
			r[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (p[i] == -1)
			return i;

		return p[i] = find(p[i]);
	}

	// Union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (r[s1] < r[s2]) {
				p[s1] = s2;
				r[s2] += r[s1];
			}
			else {
				p[s2] = s1;
				r[s1] += r[s2];
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

	int min_sum()
	{
		sort(edgelist.begin(), edgelist.end());
        Disjointset s(V);
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
        Graph g(n);
         // find distances from each pair of points
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                    int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    g.addEdge(d,make_pair(i,j));
            }
        }
        return g.min_sum();
        

    }
};

