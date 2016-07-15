/*
 * https://www.codechef.com/problems/MARCHA2
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        int levels;
        cin >> levels;
        // First level can have one stem at max
        int stemCount = 1;
        bool res = true;

        while( levels-- ) {
            int leafCount;
            cin >> leafCount;
            // Actual number of stems at the current level
            stemCount -= leafCount; 
            // Maximum number of stems at the next level
            stemCount <<= 1;
            if( stemCount < 0 ) {
                res = false;
                // Throw away rest of the input
                while( levels-- ) {
                    cin >> leafCount;
                }
                break;
            }
        }
        
        // Last level must not have any stems
        if( !stemCount && res ) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
