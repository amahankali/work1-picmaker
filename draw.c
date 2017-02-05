#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define M 500
#define N 500
#define MAXVAL 255

int abs(int n)
{
	if(n < 0) return -1 * n;
	return n;
}

int main () {

	umask(0000);
	int fd = open("arrow.ppm", O_CREAT | O_RDWR | O_EXCL, 0644);

	char header[20];
	bzero(header, 20);
	sprintf(header, "P3 %d %d %d\n", M, N, MAXVAL);
	write(fd, header, strlen(header));

	char pixel[20];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			bzero(pixel, 20);

			int r, g, b;
			if(abs(i - j) <= 10) r = g = b = 0;
			else
			{
				r = (i + j) % (MAXVAL + 1);
				g = (2 * i + j) % (MAXVAL + 1);
				b = (i + 2 * j) % (MAXVAL + 1);
			}

			sprintf(pixel, "%d %d %d\n", r, g, b);
			write(fd, pixel, strlen(pixel));
		}
	}

	close(fd);
}