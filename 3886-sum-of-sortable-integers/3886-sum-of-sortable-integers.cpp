class Solution {
public:
    inline const int sortableIntegers(
        vector<int>& __ns
    ) const noexcept {
        if( __ns.size() == 1 ) return 1;

        // I will just do what hints say...
        vector<int> __sorted = __ns;
        int __res{};
        sort( __sorted.begin(), __sorted.end() );

        if( __sorted == __ns ) {
            __res += __ns.size() + 1;

            for( int __i{2}; __i <= ( __ns.size() >> 1 ); ++__i )
                if( !(__ns.size() % __i) ) __res += __i;

            return __res;

        }

        for( int __i{2}; __i <= __ns.size(); ++__i ) {
            if( __i == ( __ns.size() >> 1 ) + 1 ) __i = __ns.size();

            if( !( __ns.size() % __i ) ) {
                char __valid{};

                for( int __subBegIdx{}; __subBegIdx <= __ns.size() - __i; __subBegIdx += __i ) {
                    int __match{__subBegIdx};

                    for( char __rep{}; __rep < 2; ++__rep ) {
                        char __brk{};

                        for( int __idx{__subBegIdx}; __idx < __subBegIdx + __i; ++__idx ) {
                            //cout << __ns[__match] << " ";
                            
                            if( __sorted[__match] == __ns[__idx] ) {
                                if( ( ++__match - __subBegIdx ) == __i ) { __valid = 1; __brk = 1; break; } 
                            }
                            else __match = __subBegIdx;

                        }

                        if( __brk ) break;

                    }

                    // cout << "\n";
                    __valid = ( ( __match - __subBegIdx ) == __i );

                    //cout << "\n" << (int)__valid << " " << __match << "\n";

                    if( !__valid ) break;

                }

                if( __valid ) __res += __i;

            }

        }

        char __valid{1};

        for( int __i{}; __i < __ns.size() - 1; ++__i )
            if( __ns[__i] > __ns[__i + 1] ) { __valid = 0; break; }

        return __res + __valid;

    }

};

// 4 5 6 4 5 6