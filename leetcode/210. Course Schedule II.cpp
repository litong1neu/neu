#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> indegree(numCourses);
		unordered_map<int, vector<int>> graph;
		vector<int> result;
		graphInit(graph, indegree, prerequisites);
		for (int i = 0; i < numCourses; i++)
		{
			int vertice = findIndegree0(indegree);
			if (vertice == -1)
				return vector < int > {};
			else
			{
				indegree[vertice] = -2;
				result.push_back(vertice);
				for (auto adjacent : graph[vertice])
					indegree[adjacent]--;
			}
		}
		return result;
	}
private:
	void graphInit(unordered_map<int, vector<int>> &graph, vector<int> &indegree, vector<pair<int, int>>& prerequisites)
	{
		for (auto p : prerequisites)
		{
			graph[p.second].push_back(p.first);
			indegree[p.first]++;
		}
	}
	int findIndegree0(vector<int> &indegree)
	{
		for (int i = 0; i < indegree.size(); i++)
			if (indegree[i] == 0)
				return i;
		return -1;
	}
};



int main()
{
	int n = 2;
	vector<pair<int, int>> v{ pair<int, int>(0, 1), pair<int, int>(1, 0) };
	Solution s;
	cout << s.canFinish(2, v);
	system("pause");
}