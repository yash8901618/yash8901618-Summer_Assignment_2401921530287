#include<iostream>
#include<vector>
#include<string>
using  namespace std;

    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        int n = chars.size();

        while (read < n) {
            char current = chars[read];
            int count = 0;

            while (read < n && chars[read] == current) {
                read++;
                count++;
            }

            chars[write++] = current;

            if (count > 1) {
                string freq = to_string(count);
                for (char digit : freq) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
