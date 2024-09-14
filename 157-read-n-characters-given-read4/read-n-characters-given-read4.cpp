/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    int offset=0;
    bool allRead=false;
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        while(!allRead){
            int curBytes = read4(buf+offset);
            offset += curBytes;
            if(curBytes == 0)
                allRead=true;
        }
        return n;
    }
};