import numpy as np


def solve_maze(maze, start, end):
    def is_valid_move(x, y):
        return 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] == 0

    def dfs(x, y):
        if (x, y) == end:
            return [(x, y)]

        maze[x][y] = 2  # Mark the cell as visited
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if is_valid_move(nx, ny):
                path = dfs(nx, ny)
                if path:
                    return [(x, y)] + path

        return None

    return dfs(*start)


maze = [
    [0, 0, 0, 1, 0],
    [1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0],
]

tam = 1000

# Propuestas, [10, 100, 200, 500, 1000] elementos
matriz = np.random.randint(2, size=(tam, tam))

print('The maze is')
for line in matriz:
    print(line)
print()

start = (0, 0)
end = (tam - 1, tam - 1)

path = solve_maze(matriz, start, end)
if path:
    print("Maze solved! Path:", path)
else:
    print("No solution found.")
