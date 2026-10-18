class Solution {
public:
    inline const vector<string> uncommonFromSentences(
        string& __s1, 
        string& __s2
    ) const noexcept {
        vector<string> __res;
        unordered_map<string, int> __um;
        string __temp{};

        for( auto& __c : __s1 ) 
            if( __c == ' ' ) {
                ++__um[__temp];
                __temp = "";
            
            }
            else __temp += __c;

        ++__um[__temp];
        __temp = "";

        for( auto& __c : __s2 ) 
            if( __c == ' ' ) {
                ++__um[__temp];
                __temp = "";
            
            }
            else __temp += __c;

        ++__um[__temp];

        for( auto& __e : __um ) if( __e.second == 1 ) __res.emplace_back( __e.first ); 

        return __res;
        
    }
};