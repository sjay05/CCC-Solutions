/*
 * Author: DynamicSquid
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *((int*)a) < *((int*)b);
}

int r, c;
char grid[25][26];

int rooms_size = 0;
int rooms[10] = { 0 };

void flood(int x, int y) {
	if (x < 0 || x >= c || y < 0 || y >= r || grid[y][x] == 'I')
		return;
	grid[y][x] = 'I';

	flood(x + 1, y);
	flood(x - 1, y);
	flood(x, y + 1);
	flood(x, y - 1);

	rooms[rooms_size]++;
}

int main() {
	int flooring;
	scanf("%i %i %i", &flooring, &r, &c);

	for (int a = 0; a < r; ++a)
		scanf("%s", grid[a]);

	for (int a = 0; a < r; ++a) {
		for (int b = 0; b < c; ++b) {
			if (grid[a][b] == '.') {
				flood(b, a);
				rooms_size++;
			}
		}
	}

	qsort(rooms, rooms_size, sizeof(int), cmp);

	int ans = 0;
	for (int i = 0; i < rooms_size; ++i, ++ans) {
		if (flooring - rooms[i] < 0)
			break;
		
		flooring -= rooms[i];
	}

	if (ans == 1)
		printf("1 room, %i square metre(s) left over", flooring);
	else
		printf("%i rooms, %i square metre(s) left over", ans, flooring);
}