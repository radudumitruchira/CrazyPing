#include <raylib.h>

int
main() {
    InitWindow(800, 600, "Hello!");
    int currentFps = 60;
    SetTargetFPS(currentFps);

    while (WindowShouldClose() == false) {
        PollInputEvents();

        ClearBackground((Color){0});
        BeginDrawing();
        {
            const char *fpsText = 0;
            if (currentFps <= 0)
                fpsText = TextFormat("FPS: unlimited (%i)", GetFPS());
            else
                fpsText = TextFormat("FPS: %i (target: %i)", GetFPS(), currentFps);
            DrawText(fpsText, 10, 10, 20, DARKGRAY);
        }
        EndDrawing();
    }

    CloseWindow();
}
