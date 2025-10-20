#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
		return (1);
	else
	{
		i = 0;
		if (map_parser(argv[1]) != 0)
			return (1);
		map = map_translator(argv[1]);
		ft_printf("This is le map!\n");
		while (map[i])
		{
			ft_printf("%s\n", map[i]);
			i++;
		}
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