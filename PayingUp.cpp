/*
 * Problem Link: https://www.codechef.com/problems/MARCHA1
*/

#include <iostream>

#define MAXNUM 25
#define MAXSUM 20005 

using namespace std;

bool isSubsetSum( int notes[], int n, int sum ) {
    bool dp[ MAXSUM ][ MAXNUM ];
    for( int i = 0; i <= sum; ++i ) {
        for( int j = 0; j <= n; ++j ) {
            if( !i ) {
                dp[ i ][ j ] = 1;
            } else if( !j ) {
                dp[ i ][ j ] = 0;
            } else {
                dp[ i ][ j ] = dp[ i ][ j - 1 ];
                if( i >= notes[ j - 1 ] ) {
                    dp[ i ][ j ] |= dp[ i - notes[ j - 1 ] ][ j - 1 ];
                }
            }
        }
    }
    return dp[ sum ][ n ];
}

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        int notes[ MAXNUM ];
        for( int i = 0; i < n; ++i ) {
            cin >> notes[ i ];
        }
        if( isSubsetSum( notes, n, m ) ) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}
