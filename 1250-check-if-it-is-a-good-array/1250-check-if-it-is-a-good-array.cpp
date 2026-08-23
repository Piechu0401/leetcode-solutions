class Solution {
public:
    inline const bool isGoodArray(
        const vector<int>& __ns
    ) const noexcept {
        deque<int> __dq;

        for( auto& __n : __ns ) {
            if( __n == 1 ) return 1;

            __dq.emplace_back( __n );

        }

        while( __dq.size() > 1 ) {
            int __gcd{ gcd( __dq[0], __dq[1] ) };

            if( __gcd == 1 ) return 1;

            __dq.pop_front();
            __dq.pop_front();
            __dq.emplace_front( __gcd );

        }

        return __dq.front() == 1;

    }
};