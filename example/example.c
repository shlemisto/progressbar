#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <progressbar.h>

#define usec_to_msec(n) (1000*(n))

#define NRM    "\x1B[0m"
#define RED(s) "\x1B[31m" s RESET
#define GRN(s) "\x1B[32m" s RESET
#define YEL(s) "\x1B[33m" s RESET
#define BLU(s) "\x1B[34m" s RESET
#define MAG(s) "\x1B[35m" s RESET
#define CYN(s) "\x1B[36m" s RESET
#define WHT(s) "\x1B[37m" s RESET
#define RESET  "\033[0m"

const char *rand_bit()
{
	return rand() % 2 ? WHT("1") : RED("0");
}

const char *eq()
{
	return "=";
}

int main()
{
	struct progressbar *bar;
	int i;

	srand(time(NULL));

	bar = progressbar_new("READ ", 1000, rand_bit);
	for (i = 0; i < 1000; ++i) {
		usleep(usec_to_msec(1));
		progressbar_inc(bar);
	}
	progressbar_finish(bar);
	
	bar = progressbar_new("ERASE", 20, eq);
	for (i = 0; i < 20; ++i) {
		usleep(usec_to_msec(100));
		progressbar_inc(bar);
	}
	progressbar_finish(bar);
	
	bar = progressbar_new("WRITE", 200, rand_bit);
	for (i = 0; i < 200; ++i) {
		usleep(usec_to_msec(10));
		progressbar_inc(bar);
	}
	progressbar_finish(bar);

	return 0;
}
