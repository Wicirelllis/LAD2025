#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 6


int main(int argc, char** argv) {
    // 1 - room is visited, 0 - room is not visited
    int rooms[MAZE_SIZE][MAZE_SIZE] = {};
    // 0 - wall is present, 1 - wall is absent
    int v_walls[MAZE_SIZE - 1][MAZE_SIZE] = {};
    int h_walls[MAZE_SIZE][MAZE_SIZE - 1] = {};

    int visited_rooms_count = 1;
    
    // fix seed
    srand(time(NULL));
    
    // current room coordinates
    int x = rand() % MAZE_SIZE;
    int y = rand() % MAZE_SIZE;
    rooms[x][y] = 1;

    while (visited_rooms_count < MAZE_SIZE * MAZE_SIZE) {
        switch (rand() % 4) {
            case 0:
                // go left
                if (x == 0) {
                    continue;
                }
                if (!rooms[x-1][y]) {
                    rooms[x-1][y] = 1;
                    v_walls[x-1][y] = 1;
                    visited_rooms_count++;
                }
                x--;
                break;
            case 1:
                // go right
                if (x == MAZE_SIZE-1) {
                    continue;
                }
                if (!rooms[x+1][y]) {
                    rooms[x+1][y] = 1;
                    v_walls[x][y] = 1;
                    visited_rooms_count++;
                }
                x++;
                break;
            case 2:
                // go down
                if (y == 0) {
                    continue;
                }
                if (!rooms[x][y-1]) {
                    rooms[x][y-1] = 1;
                    h_walls[x][y-1] = 1;
                    visited_rooms_count++;
                }
                y--;
                break;
            case 3:
                // go up
                if (y == MAZE_SIZE-1) {
                    continue;
                }
                if (!rooms[x][y+1]) {
                    rooms[x][y+1] = 1;
                    h_walls[x][y] = 1;
                    visited_rooms_count++;
                }
                y++;
                break;
        }
    }

    int art_size = 2 * MAZE_SIZE + 1;
    char art[art_size][art_size];
    // init
    for (int i = 0; i < art_size; i++) {
        for (int j = 0; j < art_size; j++) {
            if (i % 2 == 1 && j % 2 == 1) {
                art[i][j] = '.';
            } else {
                art[i][j] = '#';
            }
        }
    }
    // break the v-walls
    for (int i = 0; i < MAZE_SIZE-1; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (v_walls[i][j]) {
                art[2*i+2][2*j+1] = '.';
            }
        }
    }
    // break the h-walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE-1; j++) {
            if (h_walls[i][j]) {
                art[2*i+1][2*j+2] = '.';
            }
        }
    }

    // print the art
    for (int i = 0; i < art_size; i++) {
        for (int j = 0; j < art_size; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
    return 0;
}