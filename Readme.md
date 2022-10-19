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