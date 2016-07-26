/*
 * https://www.codechef.com/problems/MARCHA6
*/

#include <iostream>
#include <string>

#define MAX 1000000

using namespace std;

void generateParityBitString( string& parityBitString ) {
    parityBitString += "0110100110010110";
    string repeating = "1001011001101001";
    
    for( int i = 0; i < MAX / 16; ++i ) {
        parityBitString += repeating;
    }
}

int main() {
    string parityBitString = "";
    generateParityBitString( parityBitString );

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
            int pos = parityBitString.find( given );
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
