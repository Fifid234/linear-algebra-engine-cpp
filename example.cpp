#include <raylib.h>
#include "graph.h"

int main()
{
    const Vector2 windowSize = {1000, 1000};

    InitWindow(windowSize.x, windowSize.y, "My window");
    SetTargetFPS(60);

    Plot plot({1000, 1000}, {500, 500}, 30);

    Vector2 i = {1, 0};
    Vector2 j = {0, 1};
    Vector2 v = {1, 1};

    while (!WindowShouldClose())
    {
        i = rotateVector(1, i);
        j = rotateVector(1, j);
        BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(0, 0);
            drawGrid(plot, 1, GRAY, i, j);
            drawAxes(plot, 3, WHITE, i, j);
            drawBorder(plot, 3, WHITE, i, j);
            drawVector(plot, 3, YELLOW, i, j, v);
            drawFunction(plot, 3, RED, i, j, [] (float x) {return x*x;});
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
