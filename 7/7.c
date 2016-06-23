#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>

#define HEIGHT 10
#define WIDTH 10

int field[HEIGHT][WIDTH] = {
	{0,0,0,0,0,0,0,0,0,0},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{}
};


int serverHandler() {

}

int lifeStep() {

}



int main(int argc, char *argv[]) {
	phtread_t pth;
	int error;
	// запускаем поток для сервера
	if (error = phtread_create(&pth, NULL, &serverHandler, NULL)) {
		printf("Error with create server thread\n");
		return 1;
	}
	phtread_t life;
	// потоки, которые считают конфигурацию жизни
	while(1) {
		if (error = phtread_create(&lifeStep, NULL, &lifeStep, NULL)) {
			printf("Error with create life thread\n");
			return 1;
		}
		sleep(1);
		// если не завершился за секунду, выдать ошибку
		if ((error = pthread_kill(life, 0)) == 0) {
			pthread_cancel(life);
			printf("Thread running longer than 1 second\n");
			return 2;
		}
	}
	return 0;
}