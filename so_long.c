#include "so_long.h"



int	main(int argc, char **argv)
{
	char		**map;
	t_catalog	*c;

	c = malloc(sizeof(t_catalog));
	if (argc != 2)
		return (1);
	else
	{
		//map_parser checks the user input for a valid map file (format)
		if (map_parser(argv[1]) != 0)
			return (1);
		//map_translator gets a copy of the map given by the user
		map = map_translator(argv[1]);
		//map_check checks the map for its elements and if its conforms
		//with the rules i.e. no more than 1 player, exit etc.
		if (map_check(map, c) == 1)
			return (1);
		//map_display displays the map in character form and prints
		//the number of each element
		map_display(map, c);
		return (0);
	}
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;

// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 		return (printf("error\n"), 1);
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Screw you, I don't play your games");
// 	mlx_loop(mlx);
// 	return (0);
// }