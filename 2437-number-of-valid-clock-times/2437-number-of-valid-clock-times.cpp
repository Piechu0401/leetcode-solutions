class Solution {
public:
    inline const int countTime(
        string& __t
    ) const noexcept {
        short __res{};

        for( char __1{'0'}; __1 <= ( __t[1] == '?' || __t[1] < '4' ? '2' : '1' ); ++__1 ) {
            if( __t[0] != '?' ) __1 = __t[0];

            for( char __2{'0'}; __2 <= ( __1 == '2' ? '3' : '9' ); ++__2 ) {
                if( __t[1] != '?' ) __2 = __t[1];

                for( char __3{'0'}; __3 <= '5'; ++__3 ) {
                    if( __t[3] != '?' ) __3 = __t[1];

                    for( char __4{'0'}; __4 <= '9'; ++__4 ) {
                        if( __t[4] != '?' ) __4 = __t[1];

                        ++__res;

                        if( __t[4] != '?' ) break;

                    }

                    if( __t[3] != '?' ) break;

                }

                if( __t[1] != '?' ) break;

            }

            if( __t[0] != '?' ) break;

        }

        return __res;
        
    }
};