// https://leetcode.cn/problems/design-authentication-manager/

class AuthenticationManager {
private:
    int _ttl;
    map<string, int> _tokens;

private:
    bool isExpired(string tokenId, int currentTime) {
        return _tokens[tokenId] <= currentTime;
    }

public:
    AuthenticationManager(int timeToLive) {
        _ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        _tokens[tokenId] = currentTime + _ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(_tokens.find(tokenId) == _tokens.end()) return;

        if(!isExpired(tokenId, currentTime))
            _tokens[tokenId] = currentTime + _ttl;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;

        for(auto& token : _tokens)
        {
            if(!isExpired(token.first, currentTime)) ans++;
        }

        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */