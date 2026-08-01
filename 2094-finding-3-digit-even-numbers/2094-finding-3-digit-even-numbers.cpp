class Solution {
public:
    inline const vector<int> findEvenNumbers(
        const vector<int>& __ds
    ) const noexcept {
        vector<int> __res;
        unordered_map<int, int> __um;

        for( auto& __d : __ds ) ++__um[__d];

        for( short __i{100}; __i < 1000; __i += 2 ) {
            if(
                ( ( __i % 10 ) & 1 ) ||
                (( __i / 100 ) == ( ( __i / 10 ) % 10 ) &&
                __i % 10 == ( ( __i / 10 ) % 10 ) &&
                (!__um.count( ( __i / 100 ) ) ||
                __um[( __i / 100 )] < 3)) ||
                (( __i / 100 ) == ( ( __i / 10 ) % 10 ) &&
                (!__um.count( ( __i / 100 ) ) ||
                __um[( __i / 100 )] < 2)) ||
                (__i % 10 == ( ( __i / 10 ) % 10 ) &&
                (!__um.count( ( ( __i / 10 ) % 10 ) ) ||
                __um[( ( __i / 10 ) % 10 )] < 2)) ||
                (__i % 10 == ( __i / 100 ) &&
                (!__um.count( ( __i / 100 ) ) ||
                __um[( __i / 100 )] < 2)) ||
                !__um.count( ( __i / 100 ) ) ||
                !__um.count( ( __i % 10 ) ) ||
                !__um.count( ( ( __i / 10 ) % 10 ) )
            ) continue;

            __res.emplace_back( __i );

        }

        return __res;
        
    }
};