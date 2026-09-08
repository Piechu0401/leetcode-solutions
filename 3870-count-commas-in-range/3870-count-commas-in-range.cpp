class Solution {
public:
    inline const int countCommas(
        int& __n
    ) const noexcept { return __n < 1000 ? 0 : __n - 999; }
};