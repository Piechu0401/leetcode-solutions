class Solution {
public:
    inline int maxBottlesDrunk(
        int& __fb, 
        int& __ne
    ) const noexcept {
        char __bd{};
        char __eb{};
        
        while( __fb ) {
            __eb += __fb;
            __bd += __fb;
            __fb = 0;

            while( __ne <= __eb ) {
                ++__fb;
                __eb -= __ne;
                ++__ne;

            }

        }

        return __bd;
        
    }
};