// #include <mlx.h>
// #include <stdlib.h>

// typedef struct s_data {
//     void    *mlx;
//     void    *win;
//     double     x;      // x position of our moving square
//     double     dir;    // direction (1 = right, -1 = left)
// } t_data;

// // This function will be called repeatedly by mlx_loop
// int render_next_frame(t_data *data)
// {
//     // Clear the window by drawing a black rectangle
//     mlx_clear_window(data->mlx, data->win);
    
//     // Update square position
//     if (data->x >= 380)  // If reaching right edge
//         data->dir = -0.005;  // Change direction to left
//     else if (data->x <= 0)  // If reaching left edge
//         data->dir = 0.005;   // Change direction to right
    
//     data->x += data->dir;  // Move the square
    
//     // Draw a white 20x20 square at the current position
//     int y = 190;  // Vertical center (400/2 - 10)
//     for (int i = 0; i < 20; i++)
//         for (int j = 0; j < 20; j++)
//             mlx_pixel_put(data->mlx, data->win, data->x + i, y + j, 0xFFFFFF);
    
//     return (0);
// }

// int main(void)
// {
//     t_data  data;
    
//     // Initialize MLX and create window
//     data.mlx = mlx_init();
//     if (!data.mlx)
//         return (1);
    
//     data.win = mlx_new_window(data.mlx, 400, 400, "Animation Example");
//     if (!data.win)
//     {
//         free(data.mlx);
//         return (1);
//     }
    
//     // Initialize animation variables
//     data.x = 0;    // Start at left edge
//     data.dir = 1;  // Move right initially
    
//     // Register the render function to be called repeatedly
//     mlx_loop_hook(data.mlx, render_next_frame, &data);
    
//     // Start the main loop
//     mlx_loop(data.mlx);
    
//     return (0);
// }


//==============================

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PLAYER_SPEED 5

typedef struct s_img {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_img;

typedef struct s_game {
    void    *mlx;
    void    *win;
    t_img   buffer[2];     // Two buffers for double buffering
    int     current_buffer; // Track which buffer is currently being drawn to
    int     player_x;
    int     player_y;
    int     move_left;
    int     move_right;
    int     move_up;
    int     move_down;
} t_game;

// Draw a rectangle to our image
void draw_rectangle(t_img *img, int x, int y, int color)
{
    int i, j;
    int size = 50;
    
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (x + i < WINDOW_WIDTH && y + j < WINDOW_HEIGHT)
            {
                char *dst = img->addr + ((y + j) * img->line_length + 
                           (x + i) * (img->bits_per_pixel / 8));
                *(unsigned int*)dst = color;
            }
        }
    }
}

void clear_image(t_img *img)
{
    int i, j;
    
    for (i = 0; i < WINDOW_HEIGHT; i++)
    {
        for (j = 0; j < WINDOW_WIDTH; j++)
        {
            char *dst = img->addr + (i * img->line_length + 
                       j * (img->bits_per_pixel / 8));
            *(unsigned int*)dst = 0x000000;
        }
    }
}

void update_player(t_game *game)
{
    if (game->move_left)
        game->player_x -= PLAYER_SPEED;
    if (game->move_right)
        game->player_x += PLAYER_SPEED;
    if (game->move_up)
        game->player_y -= PLAYER_SPEED;
    if (game->move_down)
        game->player_y += PLAYER_SPEED;
    
    // Keep player in bounds
    if (game->player_x < 0) game->player_x = 0;
    if (game->player_x > WINDOW_WIDTH - 50) game->player_x = WINDOW_WIDTH - 50;
    if (game->player_y < 0) game->player_y = 0;
    if (game->player_y > WINDOW_HEIGHT - 50) game->player_y = WINDOW_HEIGHT - 50;
}

int render_frame(t_game *game)
{
    int next_buffer;
    
    // Calculate which buffer to draw to
    next_buffer = !game->current_buffer;
    
    // Update game state
    update_player(game);
    
    // Clear next buffer
    clear_image(&game->buffer[next_buffer]);
    
    // Draw to next buffer
    draw_rectangle(&game->buffer[next_buffer], game->player_x, game->player_y, 0x0000FF);
    
    // Display the next buffer
    mlx_put_image_to_window(game->mlx, game->win, game->buffer[next_buffer].img, 0, 0);
    
    // Switch current buffer
    game->current_buffer = next_buffer;
    
    return (0);
}

int key_press(int keycode, t_game *game)
{
    if (keycode == 65361)      // Left arrow
        game->move_left = 1;
    else if (keycode == 65363) // Right arrow
        game->move_right = 1;
    else if (keycode == 65362) // Up arrow
        game->move_up = 1;
    else if (keycode == 65364) // Down arrow
        game->move_down = 1;
    else if (keycode == 65307) // ESC
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == 65361)      // Left arrow
        game->move_left = 0;
    else if (keycode == 65363) // Right arrow
        game->move_right = 0;
    else if (keycode == 65362) // Up arrow
        game->move_up = 0;
    else if (keycode == 65364) // Down arrow
        game->move_down = 0;
    return (0);
}

int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    //exit(0);
    return (0);
}

int main(void)
{
    t_game game;
    
    // Initialize MLX
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);
    
    // Create window
    game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Double Buffer Example");
    if (!game.win)
    {
        free(game.mlx);
        return (1);
    }
    
    // Create both buffer images
    for (int i = 0; i < 2; i++)
    {
        game.buffer[i].img = mlx_new_image(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
        game.buffer[i].addr = mlx_get_data_addr(game.buffer[i].img, 
                                               &game.buffer[i].bits_per_pixel,
                                               &game.buffer[i].line_length,
                                               &game.buffer[i].endian);
    }
    
    // Initialize game state
    game.current_buffer = 0;
    game.player_x = WINDOW_WIDTH / 2;
    game.player_y = WINDOW_HEIGHT / 2;
    game.move_left = 0;
    game.move_right = 0;
    game.move_up = 0;
    game.move_down = 0;
    
    // Set up hooks
    mlx_hook(game.win, 2, 1L<<0, key_press, &game);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_loop_hook(game.mlx, render_frame, &game);
    
    // Start game loop
    mlx_loop(game.mlx);
    
    return (0);
}