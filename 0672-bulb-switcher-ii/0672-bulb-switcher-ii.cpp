class Solution {
public:
    inline const int flipLights(
        const int& __n, 
        const int& __ps
    ) const noexcept { // dear author, fuck you and your math you piece of shit
        return
            !__ps ? 1 :\
            __n == 1 ? 2 :\
            __n == 2 && __ps == 1 ? 3 :\
            __n == 2 || __ps == 1 ? 4 :\
            __ps == 2 ? 7 : 8;

    }
};