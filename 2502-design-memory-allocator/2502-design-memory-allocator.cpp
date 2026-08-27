class Allocator {
public:
    explicit Allocator(
        const int& __n
    ) noexcept { __mem.resize( __n ); }
    
    inline const int allocate(
        const int& __size, 
        const int& __mid
    ) noexcept {
        for( short __i{}; __i < __mem.size(); ++__i ) {
            if( !__mem[__i] ) {
                int __l{};

                while(
                    __i + __l < __mem.size() &&
                    !__mem[__i + __l] &&
                    ++__l < __size
                );

                if( __l == __size ) {
                    __um[__mid].push_back( { __i, __size } );

                    for( __i = __i; __i < __size + __um[__mid].back().first; ++__i )
                        __mem[__i] = __mid;

                    return __um[__mid].back().first;

                }

            }

        }

        return -1;
        
    }
    
    inline const int freeMemory(
        const int& __mid
    ) noexcept {
        if( !__um.count( __mid ) ) return 0;

        short __res{};

        for( auto& __p : __um[__mid] ) {
            __res += __p.second;

            for( short __i{__p.first}; __i < __p.first + __p.second; ++__i )
                __mem[__i] = 0;

        }

        __um.erase( __mid );

        return __res;
        
    }

    private:

    unordered_map<short, vector<pair<short, short>>>    __um;
    vector<short>                                       __mem;

};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */