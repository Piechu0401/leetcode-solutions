class Solution {
public:
    inline const int longestSubarray(
        const vector<int>& __ns
    ) const noexcept {
        vector<int> __chunks( 1, 1 );
        char __prev = __ns.front();

        for( int __i{1}; __i < __ns.size(); ++__i ) {
            if( __prev == __ns[__i] ) ++__chunks.back();
            else __chunks.emplace_back(1);

            __prev = __ns[__i];

        }

        if( __chunks.size() == 1 ) return __ns.front() * ( __chunks.front() - 1 );
        else if( __chunks.size() == 2 ) return __ns.front() ? __chunks.front() : __chunks.back();
        else if( __chunks.size() == 3 )
            if( __ns.front() ) 
                return __chunks[1] == 1 ? __chunks.front() + __chunks.back() : max( __chunks.front(), __chunks.back() );
            else return __chunks[1];

        int __res{};

        if( __ns.front() )
            for( int __i{1}; __i < __chunks.size() - 1; __i += 2 ) {
                int __l = max( __chunks[__i - 1], __chunks[__i + 1] );
                __res = __res < __l ? __l : __res;
                
                if( __chunks[__i] == 1 )
                __res = __res < __chunks[__i - 1] + __chunks[__i + 1] ? __chunks[__i - 1] + __chunks[__i + 1] : __res;

            }
        else
            for( int __i{2}; __i < __chunks.size() - 1; __i += 2 ) {
                int __l = max( __chunks[__i - 1], __chunks[__i + 1] );
                __res = __res < __l ? __l : __res;
                
                if( __chunks[__i] == 1 )
                __res = __res < __chunks[__i - 1] + __chunks[__i + 1] ? __chunks[__i - 1] + __chunks[__i + 1] : __res;

            }

        return __res;

    }
};