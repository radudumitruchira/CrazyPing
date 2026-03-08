#include "rchelper.h"
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

typedef enum CONST {
    CONST_SPRITE_SIZE = 32,

    CONST_ENEMY_VELOCITY = 50,
    CONST_PLAYER_VELOCITY = 100,
    CONST_BULLET_VELOCITY = 400,

    CONST_ENEMIES_COUNT = 100,
} CONST;

global Vector2 player = {0};
global Vector2 bullet = {0};
global Vector2 enemies[CONST_ENEMIES_COUNT] = {0};
global Vector2 mouse_pos = {0};

function void
Render() {
    BeginDrawing();
    {
        ClearBackground(GRAY);

        for (u32 i = 0; i < 800; i++) {

            DrawRectangle(i, 0, 32, 32, WHITE);
            DrawRectangle(i, 600 - 32, 32, 32, WHITE);
        }
        for (u32 i = 0; i < 600; i++) {
            DrawRectangle(0, i, 32, 32, WHITE);
            DrawRectangle(800 - 32, i, 32, 32, WHITE);
        }
        DrawCircleV(player, CONST_SPRITE_SIZE, RAYWHITE);
        DrawCircleV(bullet, CONST_SPRITE_SIZE / 6, RED);
        for (u64 i = 0; i < CONST_ENEMIES_COUNT; i++) {
            DrawCircleV(enemies[i], 25.0f, RED);
        }
    }
    DrawFPS(0, 0);
    EndDrawing();
}

function void
HandleInput() {
    PollInputEvents();
}

global Vector2 bullet_v = {0};
function void
Update() {
    f32 delta_time = GetFrameTime();

    mouse_pos = GetMousePosition();

    // Move Bullet
    bullet = Vector2Add(bullet, Vector2Scale(bullet_v, CONST_BULLET_VELOCITY * delta_time));
    if (bullet.y <= 0.0f || bullet.y >= 600 || bullet.x <= 0.0f || bullet.x >= 800) {
        bullet = player;
        bullet_v = Vector2Normalize(Vector2Subtract(mouse_pos, player));
    }

    // Move player
    if (IsKeyDown(KEY_A)) {
        player.x -= CONST_PLAYER_VELOCITY * delta_time;
    }
    if (IsKeyDown(KEY_D)) {
        player.x += CONST_PLAYER_VELOCITY * delta_time;
    }
    if (IsKeyDown(KEY_W)) {
        player.y -= CONST_PLAYER_VELOCITY * delta_time;
    }
    if (IsKeyDown(KEY_S)) {
        player.y += CONST_PLAYER_VELOCITY * delta_time;
    }

    // Enemies follow the player
    for (u64 i = 0; i < CONST_ENEMIES_COUNT; i++) {
        Vector2 v = Vector2Normalize(Vector2Subtract(player, enemies[i]));
        enemies[i] = Vector2Add(enemies[i], Vector2Scale(v, 50.0f * delta_time));
    }
}

function void
InitSystems() {
    const u32 currentFps = 60;
    const u32 WINDOW_WIDTH = 800;
    const u32 WINDOW_HEIGHT = 600;
    // const u32 WINDOW_WIDTH_MIDDLE = WINDOW_WIDTH / 2;
    // const u32 WINDOW_HEIGHT_MIDDLE = WINDOW_HEIGHT / 2;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CrazyPing");
    SetTargetFPS(currentFps);
    SetExitKey(KEY_ESCAPE);

    mouse_pos = GetMousePosition();

    player.x = WINDOW_WIDTH / 2.0f - 3.0f / 2;
    player.y = WINDOW_HEIGHT / 2.0f - 3.0f / 2;

    bullet = player;
    bullet_v = Vector2Normalize(Vector2Subtract(mouse_pos, player));

    for (u64 i = 0; i < CONST_ENEMIES_COUNT; i++) {
        enemies[i].x = (f32)GetRandomValue(10, WINDOW_WIDTH - 10);
        enemies[i].y = (f32)GetRandomValue(10, WINDOW_HEIGHT - 10);

        if (enemies[i].x == player.x) {
            enemies[i].x = (f32)GetRandomValue(10, WINDOW_WIDTH - 10);
        }
        if (enemies[i].y == player.y) {
            enemies[i].y = (f32)GetRandomValue(10, WINDOW_WIDTH - 10);
        }
    }
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
