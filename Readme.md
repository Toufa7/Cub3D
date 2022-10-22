:one: Creating our window with :

    WIN_WIDTH = 1920;
    WIN_HEIGHT = 1080;
    mlx.window = mlx_new_window(wind.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
    
<img src="https://github.com/Toufa7/Cub3D/blob/69e8684df1de3c65f45df3d16731c41e4311d1b8/images/window.png" width="700"/>


:two: Getting the player position in the map and define the field of view based on  the char inserted in the map ;

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


<img src="https://github.com/Toufa7/Cub3D/blob/1021897d7f6a75ce61b804b15aa847147aa79897/images/circle.png" width="400"/>

<img src="https://github.com/Toufa7/Cub3D/blob/1021897d7f6a75ce61b804b15aa847147aa79897/images/unit_circle.png" width="400"/>





Once we've got the player [y,x] so starting from his position we draw pixels as line we'll be using the minilibx function (mlx_pixel_put) to draw rays

The number of rays will be the width of the window is 1920

    void	player_view()
    {
	    int i = -1;
	    float fov = the fov setted in the map - 32;
	    while (++i < nbr_of_rays)
	    {
		    cast_ray(fov);
		    fov += 0.033333;
	    }
    }

0.03 this number came from dividing our player angle 64 on window's witdh 1920, with it we ensure to cast every pixel in our angle


So as you know if our player has a 4 direction 2 vertical and 2 horizontal it's gonna be easy to implement his moves by simply increasing and decreasing his current positions [x,y],

<img src="https://github.com/Toufa7/Cub3D/blob/fed5291a246a236e5a65148537472698ebd5d6d3/images/player%20directions.png" width="400"/>

But what if the player want to go to diffrent angle :

<img src="https://github.com/Toufa7/Cub3D/blob/5827035ebea0bd06d041e241b78fdd2df5d26c89/images/which_direction.png" width="400"/>

To go to that direction we need the intersection in term of the a-axis and the y-axis, here is a short refresher on a piece of
high school math which forms the foundation of most calculations in the game : SOH-CAH-TOA

<img src="https://github.com/Toufa7/Cub3D/blob/6c1598beb10949713c87323e2777010007e9540c/images/intersections.png" width="400"/>


<img src="https://github.com/Toufa7/Cub3D/blob/0f29555a21a8c86fdc66918e2dcbc06479563645/images/calculations.png" width="400"/>


You can see it like this way the player moves up to the px then the py like this ^_^


<img src="https://github.com/Toufa7/Cub3D/blob/cdc9b641d15db278830aa814d1071fadc61d2fad/images/moving.gif" width="400"/>


As you know the raycasting  doesn't draw the whole scene once each column represents a single ray cast out from the player at a particuler angle
if the ray hits the wall we calcualted the distance  

    void	cast_ray(float fov)
    {
	    float px = player x position;
	    float py = player y position;
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

<img src="https://github.com/Toufa7/Cub3D/blob/19f5be94c3bcb2bf58fa816e8f2296566b120932/images/Screen%20Shot%202022-10-19%20at%206.37.50%20PM.png" width="1000"/>


:warning: Remembre if you face this problem simply you have to check if there's any close wall to the position that's it hits the wall


<img src="https://github.com/Toufa7/Cub3D/blob/190f522295450f248b63db86c341d65f418e9fc4/images/inside_cub.png" width="700"/>

<img src="https://github.com/Toufa7/Cub3D/blob/190f522295450f248b63db86c341d65f418e9fc4/images/inside_cub1.png" width="700"/>

    void	cast_ray(float fov)
    {
	    float px = player x position;
	    float py = player y position;
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



Starting to casting rays with the help of mlx_pixel_put it turn up that it works but in the 3D part we're going to face a few problems becuase that latter it tries to put pixel instantly on window without waiting for the frame to be rendered entirely so the solution we'll be to buffer or to put our pixels in an image then push it into the window that's what my_mlx_pixel_put do :


1) Creating an image with the width and height:

    mlx_new_image(mlx->mlx_ptr, height, width)
    
2) We need some informations about the created image, we'll be using (mlx_get_data_addr) as follows :

    bits per pixel : nbr of bytes needed to express the color of a pixel
    
    Size line : nbr of bytes required to stroe one horizontal line in memory
    
    Endian : Little 0 Big 1 Endian



<img src="https://github.com/Toufa7/Cub3D/blob/6945f32893b4c4d1abfc2ccefe889f0ae638ad6e/images/formula_my_mlx.png" width="600"/>



The above fomula it's actually in my_mlx_pixel_put :

Line lenght : we'll be the number of bytes required to stroe on image hortizontal line in memory * y to move to the other place

BPP : 32bits ? because we have (ARGB) red, green, blue, alpha . the alpha parameter is a number between 0.0 and 1.0 for transparancy 


How computer store and dispplay graphics ?

    as you know computer monitor made up of tiny pixels 

Why mlx_pixel_put so slow ?

    Because it tries to put pixel instantly on window without waiting for the frame to be rendered entirely

Solution ?

    W need to buffer to put our pixels in an image then push it into the window


What an mlx image requires ?

    We need to pass some pointers to mlx_pointer :

        -   bits per pixel : pixels are basicly int (4 bytes)



Why in my_mlx_pixel_put bpp it's 32 and not 24 ?

    An RGBA color value is specified with: rgba(red, green, blue, alpha).
    The alpha parameter is a number between 0.0 (fully transparent) and 1.0 (fully opaque).



What does mlx_get_data_addr do ?

    it provide us with information about the generated image
    if it works as it should it should provide 3 informations ;
    bpp         : how many bits required to express a color of a pixel
    size_line   : how many bytes required to store 
    endian      : techinque to store data (Hex Format  ) in your RAM




What's endian means ?

    Endianness is the representation of word of digital data in computer memory

How to write pixels on top of image ?

    So after creating your image you'll need to call mlx_get_address to retrive the memory address of that pixels ??

    We pass the reference in ordre to set that current data address

    Now that we have created our image it's time to push them to window 


The images divided into small squares called pixels
and each pixel requires 1 bit of memory
we're working with RGB (0-255) each color takes 8 bits
