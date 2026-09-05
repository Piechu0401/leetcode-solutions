class Solution {
public:
    // give this shit a try
    // https://www.youtube.com/watch?v=JBPzeMD64Qg

    inline const bool isPrime(
        const int& __n
    ) const noexcept {
        if( __n == 2 || __n == 3 || __n == 5 || __n == 7 ) return 1;
        else if( __n == 1 || !( __n & 1 ) ) return 0;

        for( int __i{3}; __i <= sqrt( __n ); ++__i )
            if( !( __n % __i ) ) return 0;

        return 1;

    }

    inline const int minOperations(
        vector<int>& __ns, 
        vector<int>& __nsd
    ) const noexcept {
        // also fuck you for this test case mother fucker
        if( __ns.size() == 1 && __ns.front() == 1 ) return 0;

        deque<int> __dq( __nsd.begin(), __nsd.end() );

        while( __dq.size() > 1 ) {
            int __gcd{ gcd( __dq[0], __dq[1] ) };

            __dq.pop_front();
            __dq.pop_front();
            __dq.emplace_front( __gcd );

        }

        // cout << __dq.front() << "\n";

        sort( __ns.begin(), __ns.end() );

        int __res{-1};

        if( !isPrime( __dq.front() ) ) {
            if( __dq.front() == 1 && __ns.front() == 1 ) return 0;
            else if( __dq.front() == 1 ) return -1;

            // cout << __dq.front() << " is not prime\n";
            for( int __i{2}; __i <= __dq.front(); ++__i ) {
                if( !( __dq.front() % __i ) ) {
                    int __b{};
                    int __e{(int)__ns.size() - 1};

                    while( __b <= __e ) {
                        int __mid{ __b + ( ( __e - __b ) >> 1 ) };

                        // cout << __mid << " " << __ns.size() << "\n";

                        if( __ns[__mid] >= __i ) {
                            if( __ns[__mid] == __i ) __res = __mid;
                            __e = --__mid;

                        } else __b = ++__mid;

                    }

                    if( __res != -1 ) return __res;

                }

            }

        }
        else {
            int __b{};
            int __e{(int)__ns.size() - 1};

            while( __b <= __e ) {
                int __mid{ __b + ( ( __e - __b ) >> 1 ) };

                if( __ns[__mid] >= __dq.front() ) {
                    if( __ns[__mid] == __dq.front() ) __res = __mid;
                    __e = --__mid;
                
                } else __b = ++__mid;

            }

        }

        return __res;
        
    }
};

// 2 2 2 3 3 4 5