class Solution {
public:
    inline const int maximumProduct(
        vector<int>& __ns
    ) const noexcept {
        if( __ns.size() == 3 ) return __ns[0] * __ns[1] * __ns[2];

        sort( __ns.begin(), __ns.end() );

        if( __ns.size() == 4 ) return max({
            __ns[0] * __ns[1] * __ns[2],
            __ns[0] * __ns[1] * __ns[3],
            __ns[0] * __ns[2] * __ns[3],
            __ns[1] * __ns[2] * __ns[3],
        });

        return
            max(
                {
                    __ns[0] * __ns[1] * __ns[2],
                    __ns[__ns.size() - 1] * __ns[__ns.size() - 2] * __ns[__ns.size() - 3],
                    __ns[0] * __ns[__ns.size() - 2] * __ns[__ns.size() - 3],
                    __ns[__ns.size() - 1] * __ns[0] * __ns[__ns.size() - 3],
                    __ns[__ns.size() - 1] * __ns[__ns.size() - 2] * __ns[0],
                    __ns[1] * __ns[__ns.size() - 2] * __ns[__ns.size() - 3],
                    __ns[__ns.size() - 1] * __ns[1] * __ns[__ns.size() - 3],
                    __ns[__ns.size() - 1] * __ns[__ns.size() - 2] * __ns[1],
                    __ns[2] * __ns[__ns.size() - 2] * __ns[__ns.size() - 3],
                    __ns[__ns.size() - 1] * __ns[2] * __ns[__ns.size() - 3],
                    __ns[__ns.size() - 1] * __ns[__ns.size() - 2] * __ns[2],
                    __ns[__ns.size() - 1] * __ns[1] * __ns[0],
                    __ns[__ns.size() - 2] * __ns[1] * __ns[0],
                    __ns[__ns.size() - 3] * __ns[1] * __ns[0],
                    __ns[__ns.size() - 1] * __ns[1] * __ns[2],
                    __ns[__ns.size() - 2] * __ns[1] * __ns[2],
                    __ns[__ns.size() - 3] * __ns[1] * __ns[2],
                    __ns[__ns.size() - 1] * __ns[2] * __ns[0],
                    __ns[__ns.size() - 2] * __ns[2] * __ns[0],
                    __ns[__ns.size() - 3] * __ns[2] * __ns[0]
                }
            );
        
    }
};