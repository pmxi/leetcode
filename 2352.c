// Time is O(n^3). This is NOT optimal.


int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int pairs = 0;
    // rows
    for (int i = 0; i < gridSize; i++) {
        // columns
        for (int j = 0; j < gridSize; j++) {
            bool equal = true;
            for (int k = 0; k < gridSize; k++) {
                if (grid[i][k] != grid[k][j]) {
                    equal = false;
                }
            }
            if (equal) pairs++;
        }
    }
    return pairs;
}
