#include "rchelper.h"
#include <raylib.h>

global Rectangle block = {
    .x = 100,
    .y = 200,
    .width = 200,
    .height = 200,
};

global f32 block_speed = 30.0f;

function void
Render() {

    ClearBackground((Color){0});
    BeginDrawing();
    {
        DrawRectangleRec(block, RAYWHITE);
        DrawFPS(0, 0);
    }
    EndDrawing();
}

function void
HandleInput() {
    PollInputEvents();
}

function void
Update() {
    f32 delta_time = GetFrameTime();
    if (IsKeyDown(KEY_A)) {
        block_speed *= 2;
    }
    block.x += block_speed * delta_time;
}

function void
InitSystems() {

    const u32 window_width = 800;
    const u32 window_height = 600;
    const u32 currentFps = 60;

    InitWindow(window_width, window_height, "CrazyPing");
    SetTargetFPS(currentFps);
}

function void
Cleanup() {
    CloseWindow();
}

function bool
IsRunning() {
    return WindowShouldClose() == false;
}

int
main() {
    InitSystems();
    while (IsRunning()) {
        HandleInput();
        Update();
        Render();
    }
    Cleanup();
}
