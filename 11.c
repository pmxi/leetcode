#include <stdlib.h>

// Read this excellent article about this problem by Lei Mao
// https://leimao.github.io/blog/Proof-Container-With-Most-Water-Problem/


int maxArea(int* height, int heightSize);
int volume(int *height, int heightSize, int i, int j);

/*
 * leetcode 11
 */

int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int maxVol = -1;
    int vol;
    while (l < r) {
        vol = volume(height, heightSize, l, r);
        if (vol > maxVol) {
            maxVol = vol;
        }
        if (height[l] < height[r]) {
            l++;
        }
        else {
            r--;
        }
    }
    return maxVol;
}

static inline int min(int a, int b) {
    return a < b ? a : b;
}


int volume(int *height, int heightSize, int i, int j) {
    return abs(i - j) * min(height[i], height[j]);
}
