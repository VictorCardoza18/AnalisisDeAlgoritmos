#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define ROWS 1000
#define COLS 1000

void printMaze(int maze[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%d \t", maze[i][j]);

        printf("\n");
    }
}

bool is_valid_move(int maze[ROWS][COLS], int x, int y)
{
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0;
}

bool dfs(int maze[ROWS][COLS], int x, int y, int end_x, int end_y, int path[ROWS * COLS][2], int *path_length)
{
    if (x == end_x && y == end_y)
    {
        path[*path_length][0] = x;
        path[*path_length][1] = y;
        (*path_length)++;
        return true;
    }

    maze[x][y] = 2;
    int moves[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (is_valid_move(maze, nx, ny))
        {
            if (dfs(maze, nx, ny, end_x, end_y, path, path_length))
            {
                path[*path_length][0] = x;
                path[*path_length][1] = y;
                (*path_length)++;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int maze[ROWS][COLS] = {
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
    };

    // Primer propuesta
    int maze1[ROWS][COLS] = {
        {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}};

    // Segunda propuesta
    int maze2[ROWS][COLS] = {
        {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 1, 0}};

    // Variables utilizadas en propuesta 3, 4 y 5
    int tam = ROWS;
    srand(time(NULL));

    // Propuesta 3 Matriz Cuadrada de 100 elementos
    int maze3[ROWS][COLS];

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
            maze3[i][j] = rand() % 2;
    }

    // Propuesta 4 Matriz cuadrada de 500 elementos
    int maze4[ROWS][COLS]; // ROWS = 500, COLS = 500
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
            maze4[i][j] = rand() % 2;
    }

    // Propuesta 5 Matriz cuadrada de 1000 elementos
    int maze5[ROWS][COLS];
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
            maze5[i][j] = rand() % 2;
    }

    // printf("This is the maze\n");
    // printMaze(maze5);

    int start_x = 0;
    int start_y = 0;
    int end_x = tam - 1;
    int end_y = tam - 1;

    int path[ROWS * ROWS][2];
    int path_length = 0;

    // Medimos el tiempo de ejecucion del programa
    clock_t start, end;
    double cpu_time_used;
    // Inicia
    start = clock();
    if (dfs(maze4, start_x, start_y, end_x, end_y, path, &path_length))
    {
        printf("Maze solved! Path:\n");
        for (int i = path_length - 1; i >= 0; i--)
            printf("(%d, %d)\n", path[i][0], path[i][1]);
    }
    else
        printf("No solution found.\n");
    // Termina el programa
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("El tiempo de ejecución fue de %f segundos\n", cpu_time_used);
    return 0;
}
