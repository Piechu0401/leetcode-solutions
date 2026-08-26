/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    inline void doTheTrick(
        vector<vector<int>>&    __g,
        Node**                  __res,
        const char&             __x,
        const char&             __y,
        const char&             __len
    ) const noexcept {
        if( !__len ) return;

        char __esc{1};

        for( char __i{__y}; __i < __y + __len; ++__i ) {
            for( char __j{__x}; __j < __x + __len; ++__j ) {
                __esc = ( __g[__y][__x] == __g[__i][__j] );

                if( !__esc ) break;

            }

            if( !__esc ) break;

        }

        if( __esc ) {
            (*__res)->isLeaf = 1;
            (*__res)->val = __g[__y][__x];
            (*__res)->topLeft = nullptr;
            (*__res)->topRight = nullptr;
            (*__res)->bottomLeft = nullptr;
            (*__res)->bottomRight = nullptr;
            
            return;

        }

        (*__res)->isLeaf = 0;
        (*__res)->val = 1;
        (*__res)->topLeft = new Node( 0, 0 );
        (*__res)->topRight = new Node( 0, 0 );
        (*__res)->bottomLeft = new Node( 0, 0 );
        (*__res)->bottomRight = new Node( 0, 0 );

        doTheTrick(
            __g,
            &(*__res)->topLeft,
            __x,
            __y,
            ( __len >> 1 )
        );

        doTheTrick(
            __g,
            &(*__res)->topRight,
            __x + ( __len >> 1 ),
            __y,
            ( __len >> 1 )
        );

        doTheTrick(
            __g,
            &(*__res)->bottomLeft,
            __x,
            __y + ( __len >> 1 ),
            ( __len >> 1 )
        );

        doTheTrick(
            __g,
            &(*__res)->bottomRight,
            __x + ( __len >> 1 ),
            __y + ( __len >> 1 ),
            ( __len >> 1 )
        );

    }

    inline Node* construct(
        vector<vector<int>>& __g
    ) const noexcept {
        Node* __res = new Node( 0, 0 );

        doTheTrick(
            __g,
            &__res,
            0,
            0,
            __g.size()
        );

        return __res;

    }
};