func finalPositionOfSnake(n int, commands []string) int {
	i := 0
	j := 0
	// matrix := make([][]int, n)
	// for i := range matrix {
	// 	matrix[i] = make([]int, n)
	// }
	// cnt := 0
	// for a := 0; a < len(matrix); a++ {
	// 	for b := 0; b < n; b++ {
	// 		matrix[a][b] = cnt
	// 		cnt += 1
	// 	}
	// }

	for k := 0; k < len(commands); k++ {
		if commands[k] == "RIGHT" {
			j += 1
		} else if commands[k] == "UP" {
			i = i - 1
		} else if commands[k] == "DOWN" {
			i = i + 1
		} else {
			j = j - 1
		}
	}
	return i*n+j

}