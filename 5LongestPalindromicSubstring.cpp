#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        string Q = "@";
        for (int i = 0; i < n; i++) {
            Q += "#" + s.substr(i, 1);
        }
        Q += "#$";
        int Q_size = Q.size();
        int P[Q_size];  
        memset(P, 0, sizeof(P));
        int c = 0, r = 0;
        for (int i = 1; i < Q_size - 1; i++) {
            int iMirror = 2 * c - i;
            if (r > i) {
                P[i] = min(r - i, P[iMirror]);
            } else {
                P[i] = 0;
            }
            while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]) {
                P[i]++;
            }
            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
            }
        }
        int maxPalindrome = 0;
        int centerIndex = 0;
        for (int i = 1; i < Q_size - 1; i++) {
            if (P[i] > maxPalindrome) {
                maxPalindrome = P[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - 1 - maxPalindrome) / 2;
        return s.substr(start, maxPalindrome);
    }
};