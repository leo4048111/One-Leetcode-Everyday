// https://leetcode.cn/problems/subdomain-visit-count/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> smap;
        for(auto& s: cpdomains)
        {
            string url;
            int idx = 0;
            while(s[idx] != ' ') url += s[idx++];
            int cnt = atoi(url.c_str());

            for(idx; idx < s.size(); idx++)
            {
                if(s[idx] == ' ' || s[idx] == '.')
                {
                    url = s.substr(++idx, s.size() - idx);
                    if(smap.find(url) == smap.end()) smap.insert(make_pair(url, cnt));
                    else smap[url] += cnt;
                }
            }
        }

        vector<string> ans;
        for(auto& pair : smap)
        {
            char buffer[256];
            sprintf(buffer, "%d %s", pair.second, pair.first.c_str());
            ans.push_back(buffer);
        }

        return ans;
    }
};