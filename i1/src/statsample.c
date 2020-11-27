#include <assert.h>
#include <stdlib.h>
#include "statsample.h"

static void double_capacity(StatSample *s);

void init_stat(StatSample *s) {
    assert(s != NULL);
    s->count = 0;
    s->sum = 0;
    s->data = malloc(sizeof(int) * 10);
    s->capacity = 10;
}

void free_stat(StatSample *s) {
    assert(s != NULL);
    assert(s->data != NULL);

    free(s->data);
    s->data = NULL;
    s->capacity = 0;
}

void update_stat(int n, StatSample *s) {
    assert(s != NULL);
    assert(s->data != NULL);

    if (s->capacity == s->count) {
        double_capacity(s);
    }

    s->data[s->count] = n;
    (s->count)++;
    s->sum += n;
}

static void double_capacity(StatSample *s) {
    assert(s != NULL);
    assert(s->data != NULL);

    int newCapacity = s->capacity * 2;
    s->data = realloc(s->data, sizeof(int) * newCapacity);
    s->capacity = newCapacity;
}

int sample_avg(StatSample s) {
    return s.sum / s.count;
}
