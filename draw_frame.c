#include "so_long.h"


// void fill_fram(t_data *data, t_sprite *sprite, int frame_nbr)
// {
//     int x,y;
//     unsigned int color;

//     data->frame.frame_count = frame_nbr;
//     y = 0;
//     while (y < 100)
//     {
        
//         x = (frame_nbr - 1) * 100;
//         while (x < (frame_nbr * 100))
//         {
//            color = get_color(sprite,x,y);
//             //color = 0xFFFF00;
//             if (get_t(color) != 255)
//                 my_mlx_pixel_put(&data->frame,x,y,color);
//             else
//             {
//                 color = get_color(&data->floor,x,y);
//                 my_mlx_pixel_put(&data->frame,x,y,color);
//             }
//             x++;
//         }
//         y++;
//     }
// }

// void fill_fram(t_data *data, t_sprite *sprite, int frame_nbr)
// {
//     int x, y;
//     unsigned int color;
//     int sprite_x;

//     data->frame.frame_index = frame_nbr;
//     y = 0;
//     while (y < 100)
//     {
//         x = 0;
//         while (x < 100)
//         {
//             sprite_x = (frame_nbr - 1) * 100 + x;
//             color = get_color(sprite, sprite_x, y);

//             if (get_t(color) != 255)
//                 my_mlx_pixel_put(&data->frame, x, y, color);
//             else
//             {
//                 color = get_color(&data->floor, x, y);
//                 my_mlx_pixel_put(&data->frame, x, y, color);
//             }
//             x++;
//         }
//         y++;
//     }
// }

// void fill_fram(t_data *data, t_sprite *sprite, int frame_nbr)
// {
//     int x, y;
//     unsigned int color;
//     int sprite_x;
//     int sprite_width = sprite->width;  // Actual sprite width
//     int sprite_height = sprite->height; // Actual sprite height

//     data->frame.frame_index = frame_nbr;
//     y = 0;
//     while (y < 100) // Frame height
//     {
//         x = 0;
//         while (x < 100) // Frame width
//         {
//             // Calculate the x-coordinate in the sprite's frame
//             sprite_x = (frame_nbr - 1) * sprite_width + x;

//             if (x < sprite_width && y < sprite_height) // Inside sprite bounds
//                 color = get_color(sprite, sprite_x, y);
//             else // Outside sprite bounds, use floor texture
//                 color = get_color(&data->floor, x, y);

//             if (get_t(color) != 255) // If not transparent
//                 my_mlx_pixel_put(&data->frame, x, y, color);
//             else // Transparent, use floor texture
//             {
//                 color = get_color(&data->floor, x, y);
//                 my_mlx_pixel_put(&data->frame, x, y, color);
//             }
//             x++;
//         }
//         y++;
//     }
// }


void fill_enemy_fram(t_data *data, t_sprite *sprite, int frame_nbr)
{
    int x, y;
    unsigned int color;
    int sprite_x;

    data->frame.frame_index = frame_nbr;
    y = 0;
    while (y < 100)
    {
        x = 0;
        while (x < 100)
        {
            sprite_x = (frame_nbr - 1) * 100 + x;
            color = get_color(sprite, sprite_x, y);

            if (get_t(color) != 255)
                my_mlx_pixel_put(&data->frame, x, y, color);
            else
            {
                color = get_color(&data->floor, x, y);
                my_mlx_pixel_put(&data->frame, x, y, color);
            }
            x++;
        }
        y++;
    }
}


// void    fill_bg(t_data *data, t_sprite *frame, int s_x, int s_y)
// {
//     int x,y;
//     unsigned int color;

//     y = 0;
    
//     while (y < 100)
//     {
        
//         x = (data->frame.frame_count - 1) * 100;
//         while (x < (data->frame.frame_count * 100))
//         {
//             color = get_color(&data->frame, x, y);
//             my_mlx_pixel_put(&data->background, s_x + x, s_y + y, color);
//             x++;
//         }
//         y++;
//     }
// }

void fill_bg(t_data *data, t_sprite *frame, int s_x, int s_y)
{
    int x, y;
    unsigned int color;

    y = 0;
    while (y < 100)
    {
        x = 0;
        while (x < 100)
        {
            color = get_color(frame, x, y);
            my_mlx_pixel_put(&data->background, s_x + x, s_y + y, color);
            x++;
        }
        y++;
    }
}
