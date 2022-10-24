# Introduction :

Wolfenstein 3D, released on May 5th, 1992, established the First Person Shooter genre. The game design, powered by an engine enabling beautiful 256 color graphics, speed, high framerate, clever AI, crisp sound effects, and engaging music, was universally acclaimed.

# Project goals :

A Cub3D a 1337's projects that aims to explore raycasting and making a dynamic view inside a maze, in which you’ll have to find your way.

# Walkthrough :

:warning: If you don't have any idea about the Minilibx library please check the resources down below after diving into the walkthrough

:one: Creating our window with :

    WIN_WIDTH = 1920;
    WIN_HEIGHT = 1080;
    mlx.window = mlx_new_window(wind.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/69e8684df1de3c65f45df3d16731c41e4311d1b8/images/window.png" width="700"/>
</p>

:two: Getting the player position in the map and define the field of view based on the character inserted in the map :

    if (map[y][x] == 'N')
        fov = 270
    else if (map[y][x] == 'S')
        fov = 90
    else if (map[y][x] == 'E')
        fov = 360
    else if (map[y][x] == 'W')
        fov = 180

:three: Starting to cast some rays :

:warning: Let's go back to some of the high school math :

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/1021897d7f6a75ce61b804b15aa847147aa79897/images/circle.png" width="400"/>
</p>	
	
<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/1021897d7f6a75ce61b804b15aa847147aa79897/images/unit_circle.png" width="400"/>
</p>

Once we've got the player [y,x] so starting from his position we draw pixels as line we'll be using the minilibx function (mlx_pixel_put) to draw rays

The number of rays will be the width of the window is 1920

    void	player_view()
    {
	    int i = -1;
	    double fov = the fov setted in the map - 32;
	    while (++i < nbr_of_rays)
	    {
		    cast_ray(fov);
		    fov += 0.033333;
	    }
    }

0.03 this number came from dividing our player angle 64 on window's witdh 1920, with it we ensure to cast every pixel in our angle

So as you know if our player has a 4 direction 2 vertical and 2 horizontal it's gonna be easy to implement his moves by simply increasing and decreasing his current positions [x,y],

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/fed5291a246a236e5a65148537472698ebd5d6d3/images/player%20directions.png" width="400"/>
</p>

But what if the player want to go to diffrent angle :

<p align="center">	
<img src="https://github.com/Toufa7/Cub3D/blob/5827035ebea0bd06d041e241b78fdd2df5d26c89/images/which_direction.png" width="400"/>
</p>

To go to that direction we need the intersection in term of the a-axis and the y-axis, here is a short refresher on a piece of
high school math which forms the foundation of most calculations in the game : SOH-CAH-TOA

	
<p align="center">
	
<img src="https://github.com/Toufa7/Cub3D/blob/6c1598beb10949713c87323e2777010007e9540c/images/intersections.png" width="400"/>
</p>

<p align="center">

<img src="https://github.com/Toufa7/Cub3D/blob/0f29555a21a8c86fdc66918e2dcbc06479563645/images/calculations.png" width="400"/>
</p>

You can see it like this way the player moves up to the px then the py like this ^_^

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/cdc9b641d15db278830aa814d1071fadc61d2fad/images/moving.gif" width="400"/>
</p>

As you know the raycasting  doesn't draw the whole scene once each column represents a single ray cast out from the player at a particuler angle
if the ray hits the wall we calcualted the distance  

    void	cast_ray(double fov)
    {
	    double px = player x position;
	    double py = player y position;
	    while (True)
	    {
		    // now we need to starting casting ray from the angle that the player see's
	    py += cos(fov) * distance between each ray;	 	
	    px += sin(fov) * distance between each ray;
	        if (map[py][px] == '1'])
		        break ;
        // which means that we've reached the wall, remembre we need that intersection for the 3d part
	    }
    }

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/19f5be94c3bcb2bf58fa816e8f2296566b120932/images/Screen%20Shot%202022-10-19%20at%206.37.50%20PM.png" width="1000"/>
</p>

:warning: Remembre if you face this problem simply you have to check if there's any close wall to the position that's it hits the wall

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/190f522295450f248b63db86c341d65f418e9fc4/images/inside_cub.png" width="700"/>
</p>

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/190f522295450f248b63db86c341d65f418e9fc4/images/inside_cub1.png" width="700"/>
</p>
	
    void	cast_ray(double fov)
    {
	    double px = player x position;
	    double py = player y position;
	    while (True)
	    {
	    py += cos(fov) * distance between each ray;	 	
	    px += sin(fov) * distance between each ray;
        // Protect you self (Seg Fault)
	    if (map[py][px] == '1'] || map[py + 1][px + 1] == '1'] || || map[py - 1][px - 1] == '1'])
		    break ;
	        mlx_pixel_put(wind->mlx, wind->window, px, py, HEX_Color);

	    }
    }

:four: For the key's part here's what you should do :

    int keys()
    {
        if (KeyPressed = 124)
            look_right();
        if (KeyPressed = 123)
            look_left();
        if (KeyPressed = 2)
            move_right();
        if (KeyPressed = 0)
            move_left();
        if (KeyPressed = 13)
            move_forward();
        if (KeyPressed = 1)
          move_backword();
     }

:five: Another challange we have is to set which direction the player sees of the Cub :

We already know that a cub has 4 interfaces (not included bottom and top)

<p align="center">
<img src="https://2.bp.blogspot.com/-20Fu4yugxXw/VPjLSxkru_I/AAAAAAAAFD0/6RfOlTjgD-0/s1600/CSS_cube.gif" width="300"/>
</p>

anyway we need to each interfaces with the corrspondant color the process we'll be :

1) Let's start by casting a single ray :

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/91d3b34918d144e3398901852118c063e49301f3/images/Screen%20Shot%202022-10-21%20at%2012.24.50%20PM.png" width="700"/>
</p>

2) We've got the player [y,x] and the end of ray [y,x] by a simple calculation we can remove 2 options as follows :

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/e15763faf0329fd7e5d1e5166c3f2f3e8448ff7c/images/Screen%20Shot%202022-10-24%20at%2011.31.51%20AM.png" width="1000"/>
</p>

3) So how to set directly which directions he sees we'll since each cub i've got i don't only have the position of the player and the end of ray in the map only but also with pixels, so as you know every cub tbc

:information_source: And if you wanna take you game to the next level to look like this

<p align="center">
<img src="https://raw.githubusercontent.com/ael-bekk/Advanced-Raycasting-Cub3D/db34ea5c33af4e89f18c2c4fcf51da9265a5a24b/img_srces/Blank%208%20Grids%20Collage.png" width="1000"/>
</p>

<p align="center">
<b> Here's your path ⤵️ : </b>
</p>

<p align="center">
	<b> <a href="https://github.com/ael-bekk/Advanced-Raycasting-Cub3D"target="_blank" > Advanced Raycasting Cub3D </a> </b>
</p>


# Questions and answers

:question: How computer store and dispplay graphics ?

>As we know every image  divided into small squares called pixels and each pixel requires 1 bit of memory let's take a simple example :
<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/191525ef73d4e3495579df26a88e6a7cbf55715e/images/appel_in_pxels.png" width="350" height="400"/>
</p>

> each pixel has it's own color an example is that the top left has a green color in pixel so the computer define it with a numerical value and these numbers are called Pixel Values. These pixel values denote the intensity of the pixels, we have pixel values ranging from 0 to 255. The smaller numbers closer to zero represent the darker shade while the larger numbers closer to 255 represent the lighter or the white shade.
> This image is composed of many colors and almost all colors can be generated from the three primary colors  :heart: :green_heart: and :blue_heart:, 


:question: Why mlx_pixel_put so slow ?

> Because it tries to put pixel instantly on window without waiting for the frame to be rendered entirely

:question: So what's the solution ?

> W need to buffer to put our pixels in an image then push it into the window , starting to casting rays with the help of mlx_pixel_put it turn up that it works but in the 3D part we're going to face a few problems becuase that latter it tries to put pixel instantly on window without waiting for the frame to be rendered entirely so the solution we'll be to buffer or to put our pixels in an image then push it into the window that's what my_mlx_pixel_put do :

1) Creating an image with the width and height:

	`mlx_new_image(mlx->mlx_ptr, height, width)`
    
2) We need some informations about the created image, we'll be using `mlx_get_data_addr` as follows :

	for more informations about `mlx_get_data_addr` check it down below 🙂
	
2) We need to put pixels on top of our image :

	we're using `my_mlx_pixel_put(&my_mlx, height, width++, hex_color)`

<p align="center">
<img src="https://github.com/Toufa7/Cub3D/blob/6945f32893b4c4d1abfc2ccefe889f0ae638ad6e/images/formula_my_mlx.png" width="600"/>
</p>

The above fomula it's actually in `my_mlx_pixel_put` : We'll discuss about it latter :arrow_heading_down: 	
			
3) After that fire up your `mlx_put_image_to_window` to put it on the windows

	`mlx_put_image_to_window(wind->mlx_ptr, wind->window, wind->image_created_before, starting_x, staring_y)`
	
4) Then after every move clear your window with the help of `mlx_clear_window` and repeat again,

	`mlx_clear_window(wind->mlx, wind->window);`

:question: What an mlx image requires ?

> We need to pass some pointers to mlx_pointer :

:small_blue_diamond: bits per pixel : pixels are basicly int (4 bytes)

:question: Why in my_mlx_pixel_put bpp it's 32 and not 24 ?

> An RGBA color value is specified with: rgba(red, green, blue, alpha).

The alpha parameter is a number between 0.0 (fully transparent) and 1.0 (fully opaque).

:question: What does mlx_get_data_addr do ?

> it provide us with information about the generated image, if it works as it should it should provide you with 3 informations :

:small_blue_diamond: bpp         : how many bits required to express a color of a pixel

:small_blue_diamond: size_line   : how many bytes required to store one horizontal line in memory

:small_blue_diamond: endian      : techinque to store data (Hex Format) in your RAM

:question: What's endian means ?

> Endianness is the representation of word of digital data in computer memory

:question: How to write pixels on top of image ?

> So after creating your image, you'll need to call mlx_get_address to retrieve the memory address of that pixels ??, We pass the reference in order to set that current data address, now that we have created our image it's time to push them to the window with the help of mlx_put_image_to_window we can do it quickly. 


:question: Does printf slow down my program ?

> Absolutly yes I/O is always slow in comparison to straight computation how i don't know actually sorry but you can try to redirect output in shell from console to a file and also don't forget that scrolling is usually a killer 


# Ressources :

* Minilibx Library : 

https://gontjarow.github.io/MiniLibX/

https://velog.io/@parksj3205/miniLibX%EB%A1%9C-%EC%9C%88%EB%8F%84%EC%9A%B0-%EC%83%9D%EC%84%B1%EA%B3%BC-%EA%B0%84%EB%8B%A8%ED%95%9C-%EB%8F%84%ED%98%95-%EA%B7%B8%EB%A6%AC%EA%B8%B0

https://github.com/sejinpark12/MiniLibX_man_kor

* Raycasting

Very Very Verrrrrrry useful 👌 :

https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

This amazing book which explains every details in the game :

<p align="center">
<img src="https://app.thebookpatch.com/PublishedBooks/c1ab64b2-6df8-4ae7-91ae-64318af85a64/c1ab64b2-6df8-4ae7-91ae-64318af85a64_C.jpg" width="800"/>
</p>

https://fabiensanglard.net/gebbwolf3d/

* Math

https://blog.prepscholar.com/unit-circle-chart-radians-degrees
https://www.khanacademy.org/math/algebra2/x2ec2f6f830c9fb89:trig/x2ec2f6f830c9fb89:unit-circle/v/unit-circle-definition-of-trig-functions-1




bitwise operator is much faster than traditional computation 


