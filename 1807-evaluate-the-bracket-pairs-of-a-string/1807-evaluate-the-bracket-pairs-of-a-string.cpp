class Solution {
public:
    inline const string evaluate(
        string&                         __s, 
        const vector<vector<string>>&   __ke
    ) const noexcept {
        unordered_map<string, string> __um;

        for( auto& __k : __ke ) __um[__k[0]] = __k[1];

        string __temp{};
        char __gather{};
        string __res{};
        
        for( int __i{}; __i < __s.length(); ++__i )
            if( __s[__i] == '(' ) { __gather = 1; continue; }
            else if( __s[__i] == ')' ) {
                __gather = 0;

                if( __um.count( __temp ) ) __res += __um[__temp];
                else __res += '?';

                __temp = "";

            }
            else if( __gather ) __temp += __s[__i];
            else __res += __s[__i];

        return __res;

    }
};