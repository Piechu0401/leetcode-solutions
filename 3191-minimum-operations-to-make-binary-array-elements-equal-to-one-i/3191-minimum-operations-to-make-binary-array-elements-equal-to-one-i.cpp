class Solution {
public:
    inline const int minOperations(
        vector<int>& __ns
    ) const noexcept {
        int __res{};

        for( int __i{}; __i < __ns.size() - 2; ++__i ) {
            if( __ns[__i] ) continue;
            
            ++__res;

            __ns[__i] = !__ns[__i];
            __ns[__i + 1] = !__ns[__i + 1];
            __ns[__i + 2] = !__ns[__i + 2];

        } 

        return (
            __ns[__ns.size() - 3] && __ns[__ns.size() - 2] && __ns[__ns.size() - 1] ?\
            __res :\
            -1
        );
        
    }

};