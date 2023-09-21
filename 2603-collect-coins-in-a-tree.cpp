// https://leetcode.cn/problems/collect-coins-in-a-tree/?envType=daily-question&envId=2023-09-21

class Solution {
public:
	int collectTheCoins(vector<int>& c, vector<vector<int>>& e) {
		int n = c.size();
		vector<vector<pair<int, int>>> mu(n);//pair,first:节点编号，second:和最远子节点的距离
		for (int i = 0; i < e.size(); i++)
		{
			mu[e[i][0]].push_back({ e[i][1],-1e9 });
			mu[e[i][1]].push_back({ e[i][0],-1e9 });
		}
		function<pair<int, int>(int, int)> js = [&](int d, int f)->pair<int, int>
		{
			int he = 0, zs = -1e9;
			if (c[d])zs = 1;
			for (int i = 0; i < mu[d].size(); i++)
			{
				if (mu[d][i].first != f)
				{
					auto a = js(mu[d][i].first, d);
					he += a.first;
					a.second++;
					mu[d][i].second = a.second;
					zs = max(zs, a.second);
				}
			}
			return { he + (zs > 2 ? 1 : 0),zs };
		};
		auto b=js(0, -1);//随便拿一个当根，求初始值
		int ans = b.first;
		function<int(int, int)> cha = [&](int d, int i)//取不是子节点的最大深度，包括其他子节点和父节点
		{
			int n = mu[d].size();
			n = min(n, 3);
			for (int k = 0; k < n; k++)
			{
				if (mu[d][k].first != i )
				{
					return mu[d][k].second;
				}
			}
			return 0;
		};
		function<void(int, int, int,int)> jss = [&](int d, int f, int an,int zhi)
		{
			for (int i = 0; i < mu[d].size(); i++)//将父节点的最大深度放进当前数组
			{
				if (mu[d][i].first == f)
				{
					mu[d][i].second = zhi;
				}
			}
			ans = min(ans, an);
			sort(mu[d].begin(), mu[d].end(), [&](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second; });//对深度排序
			mu[0].push_back({-1,-1e9});
			for (int i = 0; i < mu[d].size(); i++)
			{
				int xia = mu[d][i].first;
				if (xia != f)
				{
					int dd = 0;
					if (mu[d][i].second > 3)//如果子节点深度大于3，将子节点变成根，结果需要减1
					{
						dd--;
					}
					int qt = cha(d, xia);
					if(c[d])qt=max(qt,1);//如果当前节点是金币，则可能变成最深的
					if(qt>=3)//如果其他节点深度大于3，将子节点变成根，结果需要加1
					{
						dd++;
					}
					jss(xia, d, an + dd, qt + 1);
				}
			}
		};
		jss(0,-1,ans,-1e9);
		if(ans==0)return 0;
		//最后，计算出来的是点的个数，结果需要的是边，且是来回走，故为边数减1再×2
		return (ans - 1)<<1;
	}
};