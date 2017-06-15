#ifndef __PROGRESSBAR_H
#define __PROGRESSBAR_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct progressbar {
	int cur;
	int max;
	char *title;
	char *filler;
	int filler_len;
	const char *(*fill)();
	int sym_count;
	bool randomize_output;
#define PROGRESS_BAR_WIDTH 60
};

struct progressbar *progressbar_new(char *title, int max, const char *(*fill)());
void progressbar_inc(struct progressbar *bar);
void progressbar_finish(struct progressbar *bar);

#ifdef __cplusplus
}
#endif

#endif // __PROGRESSBAR_H
