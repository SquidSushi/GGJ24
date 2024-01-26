#include <cstdlib>

#include "raylib.h"

#include "config.h"
#include "Player.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);

    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    int frameCount = 0;

    Player cattington(LoadTexture("assets/graphics/cat/idle.png"), {0, 0}, {8, 0, 16, 32});
    RenderTexture gameCanvas = LoadRenderTexture(16 * 16, 16 * 12);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        cattington.PlayerMovement();

        //Gravity Handling
        cattington.handleGravity();

        cattington.transformPosition();

        BeginDrawing();
        ClearBackground(DARKGRAY);
        BeginTextureMode(gameCanvas);
        {
            ClearBackground(BLACK);
            DrawRectangleGradientV(0, 0, 16 * 16, 16 * 12,PURPLE,DARKBLUE);
            DrawText("Hello, world!", 10, 10, 30, LIGHTGRAY);
            cattington.animation(frameCount);
        }
        EndTextureMode();
        int scale = GetScreenHeight() / gameCanvas.texture.height;
        DrawTexturePro(
                gameCanvas.texture,
                {0,0,float(gameCanvas.texture.width),float(-gameCanvas.texture.height)},
                {float(GetScreenWidth()/2 - gameCanvas.texture.width*scale/2), float(GetScreenHeight()/2 - gameCanvas.texture.height*scale/2), float(gameCanvas.texture.width*scale), float(gameCanvas.texture.height*scale)},

                {0,0},0,WHITE);
        EndDrawing();
        frameCount++;
    } // Main game loop end

    UnloadTexture(cattington.entityTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
