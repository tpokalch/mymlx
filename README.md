# mymlx

The MiniLibX library creates windows, manages events and draws pixels. This is a 'simulation' of the features of mlx written using OpenGL to port it to other systems.
Currently it is not a complete simulation. Here is the list of it's main weaknesses:

1. Only mouse_move and key_press events are supported.
2. GLFW and MacOS graphics api don't share keycodes for the same keys, so if you want to press ESC, press the '5' key.
3. Do not mlx_new_image() before mlx_new_window(). Mlx allows this, but this library does not.
4. mlx_xpm_file_to_image() doesn't work, so no tiles.
5. It is much slower than MLX.
