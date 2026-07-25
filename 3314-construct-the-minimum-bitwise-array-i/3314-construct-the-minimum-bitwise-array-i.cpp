class Solution {
public:
    inline const vector<int> minBitwiseArray(
        vector<int>& __ns
    ) const noexcept {
        for( auto& __n : __ns ) {
            bool __minone{1};

            for( short __i{}; __i < __n; ++__i ) {
                // cout << ( __i | ( __i + 1 ) ) << "\n";
                if( ( __i | ( __i + 1 ) ) == __n ) {
                    __n = __i;
                    __minone = 0;
                    break;
                    
                }

            }

            if( __minone ) __n = -1;

        }

        return __ns;
        
    }
};