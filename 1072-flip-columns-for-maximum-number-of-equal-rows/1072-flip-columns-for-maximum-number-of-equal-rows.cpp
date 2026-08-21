class Solution {
public:
    inline const int maxEqualRowsAfterFlips(
        const vector<vector<int>>& __g
    ) const noexcept {
        int __res{};
        unordered_map<string, int> __um;

        for( auto& __v : __g ) {
            string __a{""};
            string __b{""};

            for( auto& __c : __v ) {
                __a += __c + 48;
                __b += !__c + 48;

            }

            __res = max( { ++__um[__a], ++__um[__b], __res } );
            // cout << __a << " " << __b << " " << __res << "\n";

        }

        return __res;
        
    }
};