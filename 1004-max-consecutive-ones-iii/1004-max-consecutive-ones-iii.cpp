class Solution {
public:
    inline const int longestOnes(
        const vector<int>& __ns, 
        const int& __k
    ) const noexcept {
        if( !__k ) {
            int __res{};
            for( int __i{}; __i < __ns.size(); ++__i )
                if( __ns[__i] ) {
                    int __count{};
                    while(
                        __i < __ns.size() &&
                        __ns[__i]
                    ) { ++__i; ++__count; }

                    if( __count > __res ) __res = __count;

                }

            return __res;

        }

        deque<char> __dq;
        int __ones{__k};
        int __i{};

        while( 
            __i < __ns.size() &&
            (__ns[__i] ||
            __ones > 0) 
        ) {
            __ones -= !__ns[__i];
            __dq.emplace_back( __ns[__i] );

            ++__i;

        }

        if( __i == __ns.size() ) return __dq.size();

        int __res{ (int)__dq.size() };

        // cout << __ones << "\n";

        for( __i = __i; __i < __ns.size(); ++__i ) {
            __ones += !__dq.front();
            __dq.pop_front();
            __ones -= !__ns[__i];
            __dq.emplace_back(__ns[__i]);

            if( __ones < 0 ) continue;

            // cout << __ones << " " << __i << "\n";

            int __j{__i + 1};

            while( 
                __j < __ns.size() &&
                (__ns[__j] ||
                __ones > 0)
            ) {
                __ones -= !__ns[__j];
                __dq.emplace_back( __ns[__j] );

                ++__j;

            }

            __i = --__j;

            if( __res < __dq.size() ) __res = __dq.size();

        }

        return __res;

    }
};