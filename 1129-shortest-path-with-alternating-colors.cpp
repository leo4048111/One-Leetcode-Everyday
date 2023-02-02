// https://leetcode.cn/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    enum class Color 
    {
        RED = 0, 
        BLUE
    };

    typedef struct {
        Color color;
        int vex;
    }Arc;

    const int INF = 0x3f3f3f3f;

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<Arc>> graph(n);
        
        for(auto& e : redEdges) {
            graph[e[0]].push_back({Color::RED, e[1]});
        }

        for(auto& e : blueEdges) {
            graph[e[0]].push_back({Color::BLUE, e[1]});
        }

        vector<vector<int>> dis(n, vector<int>(2, INF));

        queue<Arc> q;
        q.push({Color::RED, 0});
        q.push({Color::BLUE, 0});
        dis[0][(int)Color::RED] = 0;
        dis[0][(int)Color::BLUE] = 0;

        while(!q.empty()) 
        {
            auto tmp = q.front();
            q.pop();

            for(auto& arc : graph[tmp.vex])
            {
                if(arc.color != tmp.color && dis[arc.vex][(int)arc.color] > (dis[tmp.vex][(int)tmp.color] + 1))
                {
                    dis[arc.vex][(int)arc.color] = dis[tmp.vex][(int)tmp.color] + 1;
                    q.push({arc.color, arc.vex});
                }
            }
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            ans[i] = min(dis[i][(int)Color::RED], dis[i][(int)Color::BLUE]);

            if(ans[i] == INF) ans[i] = -1;
        }

        return ans;
    }
};