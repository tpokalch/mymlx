
#include "mymlx.h"

t_fun_and_arg	user_pointer;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// triangle
/*float vertices[] = {
    -1.0f, -1.0f, 0.0f,
     -1.0f, 1.0f, 0.0f,
     1.0f, 1.0f, 0.0f,
     1.0f,  1.0f, 0.0f
};
*/
  float vertices[] = {
        // positions       // colors  //delete later         // texture coords
         1.0f,  -1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         1.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -1.0f, 1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -1.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  

/*
float vertices[] = {
    -1.0f, -1.0f, 0.0f,
     -1.0f, 1.0f, 0.0f,
     1.0f,  1.0f, 0.0f
};
*/



const char *vertexShaderSource =
	"#version 330 core\n"
//	"layout (location = 0) in int aColor;\n"

	"layout (location = 0) in vec3 aPos;\n"
	"layout (location = 1) in vec3 aColor;\n"
	"layout (location = 2) in vec2 aTexCoord;\n"

	"out vec3 ourColor;\n"
	"out vec2 TexCoord;\n"

//	"in int gl_VertexID;\n"
//	"out vec3 outColor;\n"

//	"uniform int width;\n"
//	"uniform int height;\n"

	"vec3 rgb(int c)\n"
	"{\n"
/*	"       vec3 ret;\n"

		"int x = c / 65536;\n"
		"int b = c - x * 65536;\n"
		"int y = b / 256;\n"
		"int a = b - y * 256;\n"
		"int z = a;\n"

		"ret.x = x;\n"
		"ret.y = y;\n"
		"ret.z = z;\n"
*/
		"vec3		ret;\n"

//		"uint g = uint(-5);\n"
//		"if (g == uint(4294967291))\n"
//		"	return (vec3(1, 0, 0));\n"

		"uint a = uint(c);\n"
//a = //0x00FFFFFF

//0x00FFFFFF
		"a = a & uint(0x00FFFFFF);\n"

		"uint x = (a & uint(0x00FF0000));\n"
		"x = x >> 16;\n"

		"uint y = (a & uint(0x0000FF00));\n"
		"y = y >> 8;\n"

		"uint z = (a & uint(0x000000FF));\n"
		"z = z >> 0;\n"

//(a >> 0);\n"

		"ret.z = z;\n"
		"ret.y = y;\n"
		"ret.x = x;\n"
/*		"if (a > uint(255) || y > uint(255) || x > uint(255))\n"
		"{\n"
			"ret.z = ret.x = ret.y = 0;\n"
		"}\n"
*/
		"ret.x /= 255.0;\n"
		"ret.y /= 255.0;\n"
		"ret.z /= 255.0;\n"

/*
		"ret.x /= 255.0;\n"
		"ret.y /= 255.0;\n"
		"ret.z /= 255.0;\n"

*/

		"return (ret);\n"
	
	"}\n"


//	find out which gl_VertexID corresponds to which pair of pixel
	"void main()\n"
	"{\n"
/*
//		"width = width * 2;\n"
//		"height = height * 2;\n"

		"int pixel1 = 1;\n"
		"int pixel2 = 2;\n"
		"float xpixel1 = pixel1 % width ;\n"
		"float ypixel1 = pixel1 / width;\n"

//		now xpixel and ypixel are in the range [0, 1]
		"xpixel1 = ((2 * xpixel1) / float(width) - 1);\n"
		"ypixel1 = ((-2 * ypixel1)  / float(height) + 1);\n"

		"float xpixel2 = pixel2 % width;\n"
		"float ypixel2 = pixel2 / width;\n"

//		now xpixel and ypixel are in the range [0, 1]
		"xpixel2 = ((2 * xpixel2) / float(width) - 1);\n"
		"ypixel2 = ((-2 * ypixel2)  / float(height) + 1);\n"

		"if (xpixel1 == xpixel2)\n"
		"{\n"
		"	outColor = vec3(0, 0, 1);\n"
		"}\n"
		"else\n"
		"	outColor = vec3(0, 1, 0);\n"
*/
////////////////////////////////////////////////////////////////
/*		"float xpixel = (gl_VertexID % width);\n"
		"float ypixel = (gl_VertexID / width);\n"

//		now xpixel and ypixel are in the range [0, 1]
		"xpixel = ((xpixel) / float(width) );\n"
		"ypixel = ((ypixel)  / float(height));\n"

//		now [-1, 1]

		"xpixel = 2 * xpixel - 1;\n"	
		"ypixel = -2 * ypixel + 1;\n"
*/
//		"gl_Position = vec4((xpixel), (ypixel), 1, 1);\n"

		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"ourColor = aColor;\n"
		"TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
		
//		"outColor = rgb(aColor);\n"
//		"outColor = vec3(1, 0, 0);\n"

	"}\0";


//
const char *fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"

"in vec3 ourColor;\n"
"in vec2 TexCoord;\n"

// texture sampler
"uniform sampler2D texture1;\n"

"void main()\n"
"{\n"
"	FragColor = texture(texture1, TexCoord);\n"
"}\0";

unsigned int    compileShader(const unsigned int type, const char* source)
{
	unsigned int thisShader;
	thisShader = glCreateShader(type);
	glShaderSource(thisShader, 1, &source, NULL);
	glCompileShader(thisShader);

	int  success;
	char infoLog[512];
	glGetShaderiv(thisShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(thisShader, 512, NULL, infoLog);
		printf("ERROR::SHADER::");
		if (type == GL_VERTEX_SHADER)
			printf("VERTEX");
		else if (type == GL_FRAGMENT_SHADER)
			printf("FRAGMENT");
		else if (type == GL_GEOMETRY_SHADER)
			printf("FRAGMENT");
		else if (type == GL_GEOMETRY_SHADER)
			printf("GEOMETRY");
		else
			printf("UNKNOWN_TYPE");
		printf("::COMPILATION_FAILED\n");
		printf("%s\n", infoLog);
	}
	return (thisShader);
}

int     compileProgram(const char *vertexShaderSource, const char *fragmentShaderSorce)
{
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	int ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	int success;
	char infoLog[512];

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		printf("ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n");
		printf("%s\n", infoLog);
	}

	glUseProgram(ID);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	printf("SUCCES COMPILE\n");
	return (ID);
}



void    *mymlx_init()
{

	user_pointer.f[0] = NULL;

// glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	mlx *MLX = (mlx *)malloc(sizeof(mlx));
	return ((void *)MLX);
}

			//      not used
void    *mymlx_new_window(void *mlx_ptr, int width, int height, const char *name)
{
	mlx *MLX = (mlx *)mlx_ptr;	
	GLFWwindow *window = glfwCreateWindow(width, height, name, NULL, NULL);
	printf("created window %p\n", window);
	if (window == NULL)
	{
		glfwTerminate();
		printf("Couldn't open window\n");
		return (NULL);
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("GLAD failed");
		return (NULL);
	}

	printf("deref\n");
///////////////////
/*
unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
    }
    // link shaders
    MLX->ID = glCreateProgram();
    glAttachShader(MLX->ID, vertexShader);
    glAttachShader(MLX->ID, fragmentShader);
    glLinkProgram(MLX->ID);
    // check for linking errors
    glGetProgramiv(MLX->ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(MLX->ID, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
*/
//////////////


 	int ID = compileProgram(vertexShaderSource, fragmentShaderSource);
	printf("compiled\n");
	MLX->ID = ID;



//	int frameBufferWidth, frameBufferHeight;

/*
	glfwGetFramebufferSize(window, &(((mlx *)mlx_ptr)->width_in_pixels), &(((mlx *)mlx_ptr)->height_in_pixels));
	printf("frame buffer: %d,%d\n", ((mlx *)mlx_ptr)->width_in_pixels, ((mlx *)mlx_ptr)->height_in_pixels);

//	this os for when the image is on quarter screen
//	glViewport(0, 0, ((mlx *)mlx_ptr)->width_in_pixels, ((mlx *)mlx_ptr)->height_in_pixels);
	glViewport(0, 0, width, height);
*/


//      glEnable(GL_DEPTH_TEST);
//	this is sizecallback
//	glViewport(0, 0, width, height);

/*	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetKeyCallback(window, key_callback);
//	glfwSetMouseButtonCallback(window, mouse_button_callback);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
*/

	MLX->width = width;
	MLX->height = height;
	MLX->window = window;

//	setting up 2 triangles to color them in my tile
unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
	MLX->VAO = VAO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

///////////////////////////////////////
	printf("loading texture\n");
    // load and create a texture 
    // -------------------------
    unsigned int texture;
    glGenTextures(1, &texture);
	MLX->texture = texture;
   glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load image, create texture and generate mipmaps
//////////////////////////////////////


    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
	return ((void *)window);
}
  /*  float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 
*/

void    *mymlx_new_image(void *mlx_ptr, int width, int height)
{
# if 0
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

//	glBufferData(GL_ARRAY_BUFFER, sizeof(int) * width * height, (void *)img_ptr, GL_DYNAMIC_DRAW);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 1, GL_FLOAT /*WHY NOT INT?*/, GL_FALSE, sizeof(int), (void *)0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *)0);

 	glEnableVertexAttribArray(0);
#endif

	int     *img_ptr = (int *)malloc(sizeof(int) * width * height);


	return ((void *)img_ptr);

//	return (NULL);
}


void    *mymlx_get_data_addr(void *img_ptr, int *bpp, int *sz_l, int *e)
{
	*bpp = sizeof(int);
	*sz_l = 50;     //MAY HAVE PROBLEMS
	*e = 0;
	return (img_ptr);
}

//			      not used		not use		 not	     used
void    mymlx_put_image_to_window(void *mlx_ptr, void *win_ptr, int *img_ptr, int ignore1, int ignore2)
{
//      is this the same as model.draw?
//      no, same as updateVertices()}
	printf("inside putting umage\n");
	mlx MLX = *(mlx *)mlx_ptr;
	printf("deref\n");
	int width = MLX.width;
	int height = MLX.height;
//	for (int i = 0; i < MLX.width * MLX.height; i++)
	{
		printf("deref img ptr\n");
		printf("img_ptr[i] is %d\n", img_ptr[width / 2 + width * height / 2]);
	}
	printf("puting i,age\n");
	
//	glBufferData(GL_ARRAY_BUFFER, sizeof(int) * MLX.width * MLX.height, img_ptr, GL_DYNAMIC_DRAW);
//	glFlush();
//	glDrawArrays(GL_POINTS, 0, MLX.width * MLX.height);

////////////////////////////////////
	int texture_width, texture_height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	printf("seg fault here due to size of array\n");
//    unsigned char *data = (unsigned char *)malloc(sizeof(unsigned char) * 30000/** width * height*/);
	unsigned char *data = (unsigned char *)img_ptr;
/*	for( int i = 0; i < 30000; i++)
	{
		data[i] = 255;
	}
*/
	printf("abcd\n");
  //  if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width , height , 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
	printf("image uploaded\n");
    }
/* 
   else
    {
        printf("Failed to load texture\n");
	free(data);
    }
*/
//	free(data);
//    stbi_image_free(data);

////////////////////////////////////////////////


	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(MLX.window);

}

void	mymlx_destroy_image(void *mlx_ptr, void *img_ptr)
{
	free((int *)img_ptr);
}


void	mymlx_destroy_window(void *mlx_ptr, void *img_ptr)
{
	mlx *a = (mlx *)mlx_ptr;
	GLFWwindow *window = a->window;
	glfwDestroyWindow(window);
}




void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
//	printf("inside key callback\n");
	if (action == 0)
		return ;
	t_fun_and_arg *user_pointer = (t_fun_and_arg *)glfwGetWindowUserPointer(window);
//	key_press(key, param);
	user_pointer->f[2](key, user_pointer->param);
}

void cursor_position_callback(GLFWwindow* window, double x, double y)
{
//	printf("inside callback cursor is %f,%f\n", x, y);
	t_fun_and_arg *user_pointer = (t_fun_and_arg *)glfwGetWindowUserPointer(window);
//	printf("address in callback %p\n", user_pointer->param);
	(user_pointer->f[6])(lround(x), lround(y), user_pointer->param);
//	glDrawArrays(GL_POINTS, 0, 10);
//	glDrawArrays(GL_POINTS, 0, 12030);

}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	t_fun_and_arg *user_pointer = (t_fun_and_arg *)glfwGetWindowUserPointer(window);
	double x,y;
	glfwGetCursorPos(window, &x, &y);

	printf("position is %f,%f\n", x, y);
//	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		(user_pointer->f[4])(button, lround(x), lround(y), user_pointer->param);
	}
}

//					ignore i
void	mymlx_hook(void *win_ptr, int n, int i, int (*f) (), void *param)
{
//	t_fun_and_arg	user_pointer;
	user_pointer.f[n] = f;
	user_pointer.param = param;


	glfwSetWindowUserPointer((GLFWwindow *)win_ptr, &user_pointer);
	if (n == 2)
		glfwSetKeyCallback(win_ptr, key_callback);
	else if (n == 4)
		glfwSetMouseButtonCallback(win_ptr, mouse_button_callback);
	else if (n == 6)
		glfwSetCursorPosCallback(win_ptr, cursor_position_callback);
}

void	mymlx_loop_hook(void *mlx_ptr, int (*f)(), void *param)
{
	mlx *MLX = (mlx *)mlx_ptr;

	GLFWwindow *window = MLX->window;
	user_pointer.f[0] = f;
	user_pointer.param = param;
	glfwSetWindowUserPointer(window, &user_pointer);
}

void    processInput(GLFWwindow *window)
{
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, 1);
        //returns GLFW_RELEASE otherwise

	t_fun_and_arg *user_pointer = (t_fun_and_arg *)glfwGetWindowUserPointer(window);
	if (user_pointer->f[0])
		user_pointer->f[0](user_pointer->param);

}

void    mymlx_loop(void *mlx_ptr)
{
	printf("looping\n");
	mlx *MLX = (mlx *)mlx_ptr;
//	int numberofpixels = MLX->width * MLX->height;

    while (!glfwWindowShouldClose(MLX->window))
    {
        // input
        // -----
//	printf("MLX->widnow is %p\n", MLX->window);
        processInput(MLX->window);
//	printf("s\n");
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glBindTexture(GL_TEXTURE_2D, MLX->texture);

        // draw our first triangle
        glUseProgram(MLX->ID);
        glBindVertexArray(MLX->VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------

        glfwSwapBuffers(MLX->window);
        glfwPollEvents();
    }
    glDeleteProgram(MLX->ID);
}




