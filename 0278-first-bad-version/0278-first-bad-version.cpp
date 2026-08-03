// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    inline const int firstBadVersion(
        int& __end
    ) const noexcept {
        int __beg{1};
        int __res{};

        while( __beg <= __end ) {
            const int __mid{
                __end - ( ( __end - __beg ) >> 1 )
            };

            if( !isBadVersion( __mid ) ) __beg = __mid + 1;
            else {
                __res = __mid;
                __end = __mid - 1;

            }

        }

        return __res;
        
    }
};