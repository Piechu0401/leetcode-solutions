class Solution {
public:
    inline const int minOperations(
        const vector<int>& __ns, 
        const int& __k
    ) const noexcept {
        int __xor{};

        for( auto& __n : __ns ) __xor ^= __n;

        if( __k == __xor ) return 0;

        int __p{1};
        char __res{};

        // cout << __xor << " " << __k << "\n";

        while(
            __p <= __k ||
            __p <= __xor
        ) {
            if( ( __k & __p ) != ( __xor & __p ) ) ++__res;
            __p <<= 1;

        }

        return __res;

    }
};