#include <iostream>
#include <string>
using namespace std;

void computeLPS(string pat, int M, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(string txt, string pat) {
    int M = pat.length();
    int N = txt.length();
    int lps[100];
    computeLPS(pat, M, lps);
    
    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) return i - j;
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;
    int result = KMPSearch(txt, pat);
    cout << (result != -1 ? "Found" : "Not found") << endl;
    return 0;
}