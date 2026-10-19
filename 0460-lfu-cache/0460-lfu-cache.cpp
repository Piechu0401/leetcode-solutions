class LFUCache {
public:
    // pretty much same shit as in frequency stack
    // enter the fucking sandman!!!11! https://www.youtube.com/watch?v=BETH8cW9VWQ&list=RDBETH8cW9VWQ&start_radio=1

    explicit LFUCache(
        const int& __capa
    ) noexcept :
        __maxCapa( __capa ),
        __size( 0 ),
        __count( 0 )
    {}

    struct __triple {
        int __freq;
        int __used;
        int __value;

    };
    
    inline const int get(
        const int& __k
    ) noexcept {
        if( !__vals.count( __k ) ) return -1;

        __order.erase(
            {
                __k,
                __vals[__k]
            }
        );
        ++__vals[__k].__freq;
        __vals[__k].__used = __count++;
        __order.insert(
            {
                __k,
                __vals[__k]
            }
        );

        return __vals[__k].__value;

    }
    
    inline void put(
        const int& __k, 
        const int& __v
    ) noexcept {
        if( __vals.count( __k ) ) {
            __order.erase(
                {
                    __k,
                    __vals[__k]
                }
            );
            ++__vals[__k].__freq;
            __vals[__k].__used = __count++;
            __vals[__k].__value = __v;
            __order.insert(
                {
                    __k,
                    __vals[__k]
                }
            );
            
            return;

        }

        if( __size + 1 > __maxCapa ) {
            __vals.erase( __order.begin()->first );
            __order.erase( *__order.begin() );
            __vals[__k] = __triple{
                .__freq = 1,
                .__used = __count++,
                .__value = __v
            };
            __order.insert(
                {
                    __k,
                    __vals[__k]
                }
            );
            
            return;

        }

        ++__size;

        __vals[__k] = __triple{
            .__freq = 1,
            .__used = __count++,
            .__value = __v
        };
        __order.insert(
            {
                __k,
                __vals[__k]
            }
        );

    }

    struct __orderBy {
        inline const bool operator()(
            const pair<int, __triple>& __a,
            const pair<int, __triple>& __b
        ) const noexcept {
            if( __a.second.__freq == __b.second.__freq )
                return __a.second.__used < __b.second.__used;

            return __a.second.__freq < __b.second.__freq;

        }

    };

    const int                                   __maxCapa;
    int                                         __size;
    int                                         __count;
    // key and its value
    unordered_map<int, __triple>                __vals;
    set<pair<int, __triple>, __orderBy>         __order;

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */