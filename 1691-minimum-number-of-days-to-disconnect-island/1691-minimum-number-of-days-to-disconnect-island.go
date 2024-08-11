func DFS(grid *[][]int, vis *[][]bool, i, j int) {
	if i < 0 || i >= len(*grid) || j < 0 || j >= len((*grid)[0]) || (*grid)[i][j] == 0 || (*vis)[i][j] == true {
		return
	}
	(*vis)[i][j] = true
	DFS(grid, vis, i+1, j)
	DFS(grid, vis, i-1, j)
	DFS(grid, vis, i, j+1)
	DFS(grid, vis, i, j-1)
}

func numberOfIslands(grid *[][]int, m, n int) int {

	island := 0
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if (*grid)[i][j] == 1 && !vis[i][j] {
				DFS(grid, &vis, i, j)
				island++
			}
		}
	}
	return island
}

func minDays(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	island := numberOfIslands(&grid, m, n)
	if island == 0 || island > 1 {
		return 0
	} else {
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j] == 1 {
					grid[i][j] = 0
					islands := numberOfIslands(&grid, m, n)
					grid[i][j] = 1
					if islands == 0 || islands > 1 {
						return 1
					}
				}
			}
		}
	}
	return 2
}
