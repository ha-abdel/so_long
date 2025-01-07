#include "so_long.h"


void flood_fill(char **test_map, int x, int y)
{
    if(x < 0 || y < 0 || test_map[y] == NULL || test_map[y][x] == '\0' ||test_map[y][x] == 'F' || test_map[y][x] == '1' )
        return;
    test_map[y][x] ='F';
    flood_fill(test_map, x + 1, y);
    flood_fill(test_map, x - 1, y);
    flood_fill(test_map, x, y + 1);
    flood_fill(test_map, x, y - 1);
}



int main(void)
{
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"
	};
    char *zone1[] = {
    strdup("11111111"),
    strdup("10001001"),
    strdup("10010001"),
    strdup("10110001"),
    strdup("11100001"),
    NULL 
};

    flood_fill(zone1, 0, 0);
    int y = 0;
    while (zone1[y])
    {
        printf("%s\n", zone1[y]);
        y++;
    }
    
}

