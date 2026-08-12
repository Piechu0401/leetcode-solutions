class Solution {
public:
    inline const int maxSubarrayLength(
        const vector<int>& __ns, 
        const int& __k
    ) const noexcept {
        unordered_map<int, int> __um;
        deque<int> __dq;
        int __res{};
        int __j{};

        while(
            __j < __ns.size() &&
            __um[__ns[__j]] + 1 <= __k
        ) {
            __dq.emplace_back( __ns[__j] );
            ++__um[__ns[__j]];
            ++__j;

        }

        if( __dq.size() > __res ) __res = __dq.size();

        // cout << __res << "\n";

        for( int __i{}; __i <= __ns.size() - __res; ++__i ) {
            __j = __dq.size() + __i;
            --__um[__dq.front()];
            __dq.pop_front();

            while(
                __j < __ns.size() &&
                __um[__ns[__j]] + 1 <= __k
            ) {
                __dq.emplace_back( __ns[__j] );
                ++__um[__ns[__j]];
                ++__j;

            }

            if( __dq.size() > __res ) {
                // cout << __dq.size() << " " << __res << "\n"; 
                __res = __dq.size();

            }

        }

        return __res;
        
    }
};