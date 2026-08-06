class Solution {
public:
    inline const int smallestNumber(
        int& __n, 
        const int& __t
    ) const noexcept {
        while( 1 ) {
            int __temp{__n};
            int __prod{1};

            while( __temp ) {
                __prod *= __temp % 10;
                __temp /= 10;

            }

            if( !( __prod % __t ) ) return __n;

            ++__n;

        }

        return -1;
        
    }
};