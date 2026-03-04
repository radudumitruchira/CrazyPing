#include "rchelper.h"
#include <math.h>
#include <raylib.h>

global Texture2D background1;
global Texture2D background2;
// global Texture2D background3;

global Rectangle bg1_rect;
global Rectangle bg2_rect;

global const u32 window_width = 1024;
global const u32 window_height = 800;

function void
Render() {

    BeginDrawing();
    {
        ClearBackground((Color){0});

        DrawTexturePro(background1, bg1_rect,
                       (Rectangle){.x = 0, .y = 0, .width = (f32)window_width, .height = (f32)window_height},
                       (Vector2){0, 0}, 0, WHITE);
        DrawTexturePro(background2, bg2_rect,
                       (Rectangle){.x = 0, .y = 0, .width = (f32)window_width, .height = (f32)window_height},
                       (Vector2){0, 0}, 0, WHITE);

        SetTextureWrap(background1, TEXTURE_WRAP_REPEAT);
        SetTextureWrap(background2, TEXTURE_WRAP_REPEAT);

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

    bg1_rect.x += 50.f * delta_time;
    if (bg1_rect.x >= bg1_rect.width)
        bg1_rect.x = 0;

    bg2_rect.x += 50.f * delta_time;
    if (bg2_rect.x >= bg2_rect.width)
        bg2_rect.x = 0;
}

function void
InitSystems() {

    const u32 currentFps = 60;
    InitWindow(window_width, window_height, "CrazyPing");
    SetTargetFPS(currentFps);

    background1 = LoadTexture("../../assets/platformer/background1.png");
    background2 = LoadTexture("../../assets/platformer/background2.png");

    bg1_rect.x = 0;
    bg1_rect.y = 0;
    bg1_rect.width = (f32)background1.width;
    bg1_rect.height = (f32)background1.height;
    bg1_rect.x = 0;

    bg2_rect.x = 0;
    bg2_rect.y = 0;
    bg2_rect.width = (f32)background2.width;
    bg2_rect.height = (f32)background2.height;
}

function void
Cleanup() {
    UnloadTexture(background2);
    UnloadTexture(background1);
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
