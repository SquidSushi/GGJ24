#include <cstdlib>

#include "raylib.h"

#include "config.h"
#include "Player.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    Player cattington(LoadTexture("assets/graphics/testimage.png"), {0,0}, {0,0,120,120});

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        cattington.PlayerMovement();

        //Gravity Handling
        cattington.handleGravity();

        cattington.transformPosition();

        BeginDrawing();
            ClearBackground(WHITE);
            DrawText("Hello, world!", 10, 10, 30, LIGHTGRAY);
            DrawTexturePro(cattington.entityTexture, cattington.sourceRec,{cattington.position.x, cattington.position.y, 16, 24}, {0,0}, 0, WHITE);

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(cattington.entityTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
