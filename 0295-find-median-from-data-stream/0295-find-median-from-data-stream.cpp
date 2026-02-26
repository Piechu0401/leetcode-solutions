class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(
        const int& __n
    ) {
        if( __nums.size() > 1 ) {
            if( __nums[0] >= __n ) {
                __nums.push_front(__n);
                return;
                    
            }
            else if( __nums[__nums.size() - 1] <= __n ) { 
                __nums.emplace_back(__n);
                return;

            }
            
            int __beg = 0;
            int __end = __nums.size() - 1;

            while( __beg <= __end ) {
                int __mid = __beg + ( ( __end - __beg ) >> 1 );

                if( 
                    __nums[ __mid ] <= __n &&
                    __nums[ __mid + 1 ] >= __n 
                ) { 
                    __nums.insert( __nums.begin() + __mid + 1, __n ); 
                    // print(); 
                    return; 
                }
                else if(
                    __nums[ __mid + 1 ] < __n
                ) __beg = __mid + 1;
                else if( 
                    __nums[ __mid ] > __n 
                ) __end = __mid - 1;

            }

            // print();

        }
        else if( __nums.size() == 1 ) 
            if( __nums[0] > __n ) __nums.insert( __nums.begin(), __n ); 
            else __nums.emplace_back(__n); 
        else __nums.emplace_back(__n);

    }
    
    double findMedian() {
        return __nums.size() % 2 == 1 ? (double)__nums[ (__nums.size() >> 1) ] : (double)( __nums[ ( __nums.size() >> 1 ) ] + __nums[ ( __nums.size() >> 1 ) - 1 ] ) / 2.00000;

    }

    deque<int> __nums;
// 
    // void print() {
    //     for( auto __n : __nums )
    //         cout << __n << " ";
// 
    //     cout << "\n";
// 
    // }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */