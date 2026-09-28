class Solution {
public:
    inline const int maxDepth(
        string& __s
    ) const noexcept {
        char __res{};
        char __bs{};

        for( auto& __c : __s ) {
            __bs += ( __c == '(' ? 1 : __c == ')' ? -1 : 0 );
            __res = ( __res < __bs ? __bs : __res );

        }

        return __res;
        
    }
};