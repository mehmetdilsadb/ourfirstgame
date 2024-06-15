#include "raylib.h"

#define GRID_SIZE 60
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080

typedef struct {
    int x, y;
} Vector2Int;

void DrawPacman(Vector2Int position);

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
    SetTargetFPS(60);

    Vector2Int pacmanPos = {SCREEN_WIDTH / 2 / GRID_SIZE, SCREEN_HEIGHT / 2 / GRID_SIZE};

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_RIGHT)) pacmanPos.x++;
        if (IsKeyPressed(KEY_LEFT)) pacmanPos.x--;
        if (IsKeyPressed(KEY_UP)) pacmanPos.y--;
        if (IsKeyPressed(KEY_DOWN)) pacmanPos.y++;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawPacman(pacmanPos);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void DrawPacman(Vector2Int position) {
    int pixelX = position.x * GRID_SIZE + GRID_SIZE / 2;
    int pixelY = position.y * GRID_SIZE + GRID_SIZE / 2;
    DrawCircle(pixelX, pixelY, GRID_SIZE / 2 - 2, YELLOW);
}
