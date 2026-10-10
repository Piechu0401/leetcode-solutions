class Router {
public:
    explicit Router(
        const int                               __ml
    ) noexcept :
        __limit( __ml )
    {}
    
    inline const bool addPacket(
        const int&                              __src, 
        const int&                              __dst, 
        const int&                              __ts
    ) noexcept {
        if( __used.count( { __src, __dst, __ts } ) ) return 0;

        if( __dsts.size() == __limit ) {
            __used.erase(
                {
                    __packets[__dsts.front()].front().first,    
                    __dsts.front(),
                    __packets[__dsts.front()].front().second
                }
            );
            __packets[__dsts.front()].pop_front();
            
            if( !__packets[__dsts.front()].size() ) __packets.erase( __dsts.front() );
            
            __dsts.pop_front();
            __dsts.emplace_back( __dst );
            __packets[__dst].push_back( { __src, __ts } );
            __used.insert(
                {
                    __src,
                    __dst,
                    __ts
                }
            );
            
            return 1;

        }

        __dsts.emplace_back( __dst );
        __packets[__dst].push_back( { __src, __ts } );
        __used.insert(
            {
                __src,
                __dst,
                __ts
            }
        );

        return 1;

    }
    
    inline const vector<int> forwardPacket() noexcept {
        if( !__dsts.size() ) return {};

        vector<int> __res = {
            __packets[__dsts.front()].front().first,
            __dsts.front(),
            __packets[__dsts.front()].front().second
        };

        __used.erase( __res );

        __packets[__dsts.front()].pop_front();
            
        if( !__packets[__dsts.front()].size() ) __packets.erase( __dsts.front() );
            
        __dsts.pop_front();   

        return __res;
    
    }
    
    inline const int getCount(
        const int&                              __dst, 
        const int&                              __st, 
        const int&                              __et
    ) noexcept {
        int __b{};
        int __e{ (int)__packets[__dst].size() - 1 };
        int __i1{-1};
        int __i2{-1};

        while( __b <= __e ) {
            int __m{ __b + ( ( __e - __b ) >> 1 ) };

            if( __packets[__dst][__m].second < __st ) __b = ++__m;
            else { __i1 = __m; __e = --__m; }

        }

        __b = 0;
        __e = __packets[__dst].size() - 1;

        while( __b <= __e ) {
            int __m{ __b + ( ( __e - __b ) >> 1 ) };

            if( __packets[__dst][__m].second > __et ) __e = --__m;
            else { __i2 = __m; __b = ++__m; }

        }

        cout << __i1 << " " << __i2 << "\n";

        return ( ( __i1 == -1 || __i2 == -1 ) ? 0 : __i2 - __i1 + 1 );
        
    }

    struct __vecHash {
        inline const unsigned long operator()(
            const vector<int>& __v
        ) const noexcept {
            unsigned long __res = __v[0];
            __res ^= __v[1] + 0x9e3779b9 + ( __res << 6 ) + ( __res >> 2 );
            __res ^= __v[2] + 0x9e3779b9 + ( __res << 6 ) + ( __res >> 2 );

            return __res;

        }

    };

    const int                                   __limit;
    unordered_map<int, deque<pair<int, int>>>   __packets;
    deque<int>                                  __dsts;
    unordered_set<vector<int>, __vecHash>       __used;

};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */