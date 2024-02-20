#include "../so_long.h"

void	wall_error(int i)
{
	write(1, "Error\n", 6);
	if (i == -1)
		write(1, "lines are not the same lenght\n", 30);
	if (i == -2)
		write(1, "map is not surounded by walls\n", 30);
	if (i == -3)
		write(1, "Collectible, Player or exit is surounded by walls\n", 50);
	if (i == -4)
		write(1, "missing a filename\n", 19);
	if (i == -5)
		write(1, "to many or to little Exits or Players\n", 38);
	if (i == -6)
		write(1, "malloc failed\n", 14);
}
