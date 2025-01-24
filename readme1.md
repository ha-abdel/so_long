
Here are the **MiniLibX key codes** for handling keyboard input with `mlx_key_hook` or `mlx_hook` on Linux. These key codes are based on the **X11** keysym values that MiniLibX uses.

---

### **Key Codes for MiniLibX on Linux**

#### **Alphanumeric Keys**
| Key          | Key Code |
|--------------|----------|
| `A`          | 97       |
| `B`          | 98       |
| `C`          | 99       |
| `D`          | 100      |
| `E`          | 101      |
| `F`          | 102      |
| `G`          | 103      |
| `H`          | 104      |
| `I`          | 105      |
| `J`          | 106      |
| `K`          | 107      |
| `L`          | 108      |
| `M`          | 109      |
| `N`          | 110      |
| `O`          | 111      |
| `P`          | 112      |
| `Q`          | 113      |
| `R`          | 114      |
| `S`          | 115      |
| `T`          | 116      |
| `U`          | 117      |
| `V`          | 118      |
| `W`          | 119      |
| `X`          | 120      |
| `Y`          | 121      |
| `Z`          | 122      |

---

#### **Numeric Keys**
| Key          | Key Code |
|--------------|----------|
| `0`          | 48       |
| `1`          | 49       |
| `2`          | 50       |
| `3`          | 51       |
| `4`          | 52       |
| `5`          | 53       |
| `6`          | 54       |
| `7`          | 55       |
| `8`          | 56       |
| `9`          | 57       |

---

#### **Arrow Keys**
| Key             | Key Code |
|------------------|----------|
| `Left Arrow`     | 65361    |
| `Up Arrow`       | 65362    |
| `Right Arrow`    | 65363    |
| `Down Arrow`     | 65364    |

---

#### **Control Keys**
| Key            | Key Code |
|-----------------|----------|
| `Escape`        | 65307    |
| `Enter`         | 65293    |
| `Backspace`     | 65288    |
| `Tab`           | 65289    |
| `Shift`         | (varies by configuration, often 65505 or 65506) |
| `Control`       | (varies by configuration, often 65507 or 65508) |
| `Space`         | 32       |

---

#### **Function Keys**
| Key        | Key Code |
|------------|----------|
| `F1`       | 65470    |
| `F2`       | 65471    |
| `F3`       | 65472    |
| `F4`       | 65473    |
| `F5`       | 65474    |
| `F6`       | 65475    |
| `F7`       | 65476    |
| `F8`       | 65477    |
| `F9`       | 65478    |
| `F10`      | 65479    |
| `F11`      | 65480    |
| `F12`      | 65481    |

---

### **Using Key Codes in MiniLibX**

You can capture these key codes in the `mlx_key_hook` or `mlx_hook` callbacks to handle keyboard events.

#### Example Code:
```c
#include <mlx.h>
#include <stdio.h>

int key_press(int keycode, void *param)
{
    printf("Key Pressed: %d\n", keycode);

    if (keycode == 65307) // Escape key
    {
        printf("Exiting program.\n");
        mlx_destroy_window(param, param);
        exit(0);
    }
    return 0;
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Key Hook Example");

    mlx_key_hook(win, key_press, mlx);
    mlx_loop(mlx);
    return 0;
}
```

---

### **Notes**
1. **Platform Specific**:
   - These codes are specific to Linux using X11.
   - They may differ on macOS or other systems where MiniLibX is used.

2. **Customizing Input**:
   - You can define constants in your code for readability:
     ```c
     #define ESC_KEY 65307
     #define LEFT_ARROW 65361
     #define RIGHT_ARROW 65363
     ```

Let me know if you need further assistance!




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