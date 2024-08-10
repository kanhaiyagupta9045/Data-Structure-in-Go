import "fmt"


func DoDfs(matrix *[][]int, i, j int) {
    m := *matrix
    if i < 0 || i >= len(m) || j < 0 || j >= len(m[0]) || m[i][j] != 0 {
        return
    }
    m[i][j] = 1
    DoDfs(matrix, i+1, j)
    DoDfs(matrix, i-1, j)
    DoDfs(matrix, i, j+1)
    DoDfs(matrix, i, j-1)
}
func regionsBySlashes(grid []string) int {
	rows := len(grid)
	cols := len(grid[0])

	matrix := make([][]int, rows*3)

	for i := range matrix {
		matrix[i] = make([]int, cols*3)
	}

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == '/' {
				matrix[i*3][j*3+2] = 1
				matrix[i*3+1][j*3+1] = 1
				matrix[i*3+2][j*3] = 1
			}
			if grid[i][j] == '\\' {
				matrix[i*3][j*3] = 1
				matrix[i*3+1][j*3+1] = 1
				matrix[i*3+2][j*3+2] = 1
			}
		}
	}

   region := 0

    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if matrix[i][j] == 0 {
                DoDfs(&matrix, i, j)
                region++
            }
        }
    }

    return region

}