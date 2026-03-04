#include "rchelper.h"
#include <math.h>
#include <raylib.h>

global Texture2D bgs[9] = {0};
global Rectangle bgs_rect[9] = {0};

global const u32 window_width = 1720;
global const u32 window_height = 800;

function void
Render() {

    BeginDrawing();
    {

        ClearBackground((Color){0});

        const Rectangle window_rect = {0, 0, (f32)window_width, (f32)window_height};
        for (u64 i = 0; i < 9; i++) {
            DrawTexturePro(bgs[i], bgs_rect[i], window_rect, (Vector2){0}, 0.0f, WHITE);
        }

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
    for (u64 i = 1; i < 9; i++) {
        bgs_rect[i].x += 10.0f * (i + 1) * delta_time;

        if (bgs_rect[i].x >= bgs_rect[i].width)
            bgs_rect[i].x = 0.0f;
    }
    bgs_rect[0].x += 100 * delta_time;
}

function void
InitSystems() {

    const u32 currentFps = 60;
    InitWindow(window_width, window_height, "CrazyPing");
    SetTargetFPS(currentFps);

    for (u64 i = 0; i < 9; i++) {
        const char *path = TextFormat("../../assets/bg/layer%d.png", i);
        bgs[i] = LoadTexture(path);
        bgs_rect[i].x = 0;
        bgs_rect[i].y = 0;
        bgs_rect[i].width = (f32)bgs[i].width;
        bgs_rect[i].height = (f32)bgs[i].height;
        SetTextureWrap(bgs[i], TEXTURE_WRAP_REPEAT);
    }
}

function void
Cleanup() {
    CloseWindow();
    for (u64 i = 0; i < 9; i++) {
        UnloadTexture(bgs[i]);
    }
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
