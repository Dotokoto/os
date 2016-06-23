#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#define HOST "localhost"
#define PORT "7654"

int connectToHost(int height, int width) {

}

int main(int argc, char *argv[]) {
	// первый аргумент - длина поля
	// второй аргумент - ширина поля
	if (argc < 3) {
		printf("Need field height and width in arguments\n");
		return 1;
	}
	int height = atoi(argv[1]);
	int width = atoi(argv[2]);
	printf("%d %d\n", height, width);
	connectToHost(height, width);
	return 0;
}