var square = [
  [1, 2, 3, 6, 2, 8, 1],
  [4, 8, 2, 4, 3, 1, 9],
  [1, 5, 3, 7, 9, 3, 1],
  [4, 9, 2, 1, 6, 9, 5],
  [7, 6, 8, 4, 7, 2, 6],
  [2, 1, 6, 2, 4, 8, 7],
  [8, 4, 3, 9, 2, 5, 8]];

function minPathBASIC(grid, x, y) {  
  if(x > 0 && y > 0)
    return grid[y][x] + Math.min(minPath(grid, x-1, y), minPath(grid, x, y-1));
  else if(x > 0)
    return grid[y][x] + minPath(grid, x-1, y)
  else if(y > 0)
    return grid[y][x] + minPath(grid, x, y-1)
  else
    return grid[y][x]
}

function minPath(grid, x, y) {  
  var mem = [];
  for(var i =0; i < grid.length; ++i){
    mem[i] = []
    for(var j = 0; j < grid.length; ++j){
      if(i == 0 && j == 0)
        mem[i][j] = grid[0][0]
      else if(i == 0)
        mem[0][j] = mem[0][j-1] + grid[0][j]
      else if(j == 0)
        mem[i][0] = mem[i-1][0] + grid[i][0]
      else mem[i][j] = Math.min(mem[i-1][j], mem[i][j-1]) + grid[i][j]
    }
  }
  return mem[y][x]
}

console.log(minPath(square, 2, 2))