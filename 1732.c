int largestAltitude(int* gain, int gainSize) {
    int height = 0;
    int max_height = 0;
    for (int i = 0; i < gainSize; i++) {
        height += gain[i];
        if (height > max_height) max_height = height;
    }
    return max_height;
}
