class LRUCache {
public:
    explicit LRUCache(
        const int& __c
    ) noexcept :
        __limit(__c)
    {};
    
    inline const int get(
        const int& __k
    ) noexcept {
        if( !__elems.count( __k ) ) return -1;
        
        __vals.push_back( *__elems[__k] );
        __vals.erase( __elems[__k] );
        __elems[__k] = prev(__vals.end());
        return __vals.back().first;

    }
    
    inline void put(
        const int& __k, 
        const int& __v
    ) noexcept {
        if( !__elems.count( __k ) ) {
            if( __vals.size() < __limit ) {
                __vals.push_back( {__v, __k} );
                __elems[__k] = prev(__vals.end());
                return;

            }
            __elems.erase( __vals.begin()->second );
            __vals.pop_front();
            __vals.push_back({__v, __k});
            __elems[__k] = prev(__vals.end());
            return;

        }

        __vals.erase( __elems[__k] );
        __vals.push_back( { __v, __k } );
        __elems[__k] = prev(__vals.end());

    }

    int __limit;
    list<pair<int, int>> __vals;
    unordered_map<int, list<pair<int, int>>::iterator> __elems;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 // null null
 // get(2) = -1
 // put(2,6) = null 6
 // get(1) = -1
 // put(1,5) = 6 5
 // put(1,2) = 5 2