/*
 * https://www.codechef.com/problems/MARCHA6
*/

#include <iostream>
#include <string>

using namespace std;

const int MAX = 1 << 23;
string parityBitString = "";

void generateParityBitString() {
    parityBitString += "0";
    for( int i = 1; i < MAX; ++i ) {
        char next = parityBitString[ i >> 1 ];
        if( i & 1 ) {
            next ^= 1;
        }
        parityBitString += next;
    }
}

int main() {
    generateParityBitString();
    int t;
    cin >> t;
    while( t-- ) {
        int len;
        cin >> len;
        int bit;
        string given = "";
        for( int i = 0; i < len; ++i ) {
            cin >> bit;
            if( bit ) {
                given += "1";
            } else {
                given += "0";
            }
            long long int pos = parityBitString.find( given );
            cout << pos;
            if( i == ( len - 1 ) ) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}
