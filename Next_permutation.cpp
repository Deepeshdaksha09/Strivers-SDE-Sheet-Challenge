#include <bits/stdc++.h> 

using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if (n == 1) {
        return permutation;
    }
    
    int idx1 = -1;
    int idx2 = -1;
    
    for (int i = n - 2; i >= 0; i--) {
        if (permutation[i] < permutation[i + 1]) {
            idx1 = i;
            break;
        }
    }
    
    if (idx1 < 0) {
        reverse(permutation.begin(), permutation.end());
    } else {
        for (int i = n - 1; i >= 0; i--) {
            if (permutation[i] > permutation[idx1]) {
                idx2 = i;
                break;
            }
        }
        swap(permutation[idx1], permutation[idx2]);
        reverse(permutation.begin() + idx1 + 1, permutation.end());
    }
    
    return permutation;
}
