class Solution {
public:
    inline const bool checkRecord(
        const string& __s
    ) const noexcept {
        short __a{};
        short __l{};

        for( auto& __c : __s )
            if( __c == 'A' ) {
                __l = 0;
                ++__a;
                if( __a > 1 ) return 0;

            }
            else if( __c == 'L' ) {
                ++__l;
                if( __l > 2 ) return 0;

            }
            else __l = 0;
        
        return 1;

    }
};