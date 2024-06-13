#include <stdio.h>
#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = { 
	{2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2},
	{2,2,2,0,0,0,0,2,2,2},
	{2,2,2,2,0,0,0,2,2,2},
	{2,2,2,2,0,0,0,2,2,2},
	{2,2,2,2,0,0,0,0,2,2},
	{2,2,2,2,0,2,2,2,2,2},
	{2,2,2,2,0,2,2,2,2,2},
	{2,2,2,2,0,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2},
};

char read_pixel(int x, int y) {
	return screen[x][y];
}

void write_pixel(int x, int y, int color) {
	screen[x][y] = color;
}

void flood_fill(int x, int y)
{
	if (read_pixel(x, y) == WHITE) {
		write_pixel(x, y, BLACK);
		flood_fill(x, y + 1);
		flood_fill(x+1, y);
		flood_fill(x, y-1);
		flood_fill(x-1, y);
	}
}


int main() {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			printf("%d ", screen[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	flood_fill(5, 4);

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			printf("%d ", screen[i][j]);
		}
		printf("\n");
	}

}