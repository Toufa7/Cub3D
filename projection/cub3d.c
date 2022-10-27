#include "../cub3d.h"

/* TODO:
// {
			Poms
// 	[✅] Fixing 3D Rendring Strips
// 	[✅] Fixing fisheye effect
// 	[✅] Fixing keys
// 	[✅] Adding colors to wall
// 	[✅] Adding textures
// 	[❌] Fixing seeing between 2 walls

			Abdesssamad
// 	[✅] Handling More than 2 comma in rgb
// 	[✅] Handling newlines inside the map
// 	[✅] Convert RGB color to hexadecimal
// 	[✅] Don't forget to exit if an error happend
// 	[✅] Leaks
*/

int	main(int ac, char **av)
{
	t_mlx	wind;

	wind.parsing = read_and_add(av);
	wind.ceilling = rgb_to_hexa(wind.parsing.C);
	wind.floor = rgb_to_hexa(wind.parsing.F);
	if (ac == 2)
	{
		wind.map = ft_split(wind.parsing.full_map, '\n');
		wind.mlx = mlx_init();
		wind.window = mlx_new_window(wind.mlx, WIN_W, WIN_H, "Cub3D");
		images_to_xpm(&wind);
		get_player_position(&wind);
		projecting_rays(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}
