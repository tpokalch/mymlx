
#include <glad/glad.h>
//GLAD should be included before GLFW
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

#ifndef MYMLX_H
# define MYMLX_H

typedef struct  s_mlx
{
	int width;
        int height;

	// in pixels! use getFrameBufferSize to get
	// size of your window in real pixels!
 
        int width_in_pixels;
        int height_in_pixels;



        GLFWwindow *window;
	int ID;
}               mlx;

typedef struct	s_fun_and_arg
{
//	these functions are initialized to event functions like
//	key press, mouse press, mouse move in main, according to
//	the event number specofoed in main. they are called by
//	glfw callbakcs

	int (*f[10])();
	void *param;

}		t_fun_and_arg;

unsigned int    compileShader(const unsigned int type, const char* source);
int     compileProgram(const char *vertexShaderSource, const char *fragmentShaderSorce);

void    *mymlx_init();
void    *mymlx_new_window(void *mlx_ptr, int width, int height, const char *name);
void    *mymlx_new_image(void *mlx_ptr, int width, int height);
void    *mymlx_get_data_addr(void *img_ptr, int *bpp, int *sz_l, int *e);
void    mymlx_put_image_to_window(void *mlx_ptr, void *win_ptr, int *img_ptr, int ignore1, int ignore2);
void    mymlx_loop(void *mlx_ptr);

void	mymlx_destroy_window(void *mlx_ptr, void *img_ptr);
void	mymlx_destroy_image(void *mlx_ptr, void *img_ptr);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double x, double y);
void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void    mymlx_hook(void *win_ptr, int n, int i, int (*f) (), void *param);

#endif



