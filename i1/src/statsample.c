#include <assert.h>
#include <stdlib.h>
#include "statsample.h"

void init_stat(StatSample *s) {
    assert(s != NULL);
    s->count = 0;
    s->sum = 0;
    s->data = malloc(sizeof(int) * 10);
}
