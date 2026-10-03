

class Solution {
    public int islandPerimeter(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int perimeter = 0;

        // Iterate through each cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If the cell is land
                if (grid[r][c] == 1) {
                    // Start with 4 sides
                    perimeter += 4;
                    // Subtract 2 for each adjacent land cell (up and left)
                    if (r > 0 && grid[r-1][c] == 1) perimeter -= 2;
                    if (c > 0 && grid[r][c-1] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
}