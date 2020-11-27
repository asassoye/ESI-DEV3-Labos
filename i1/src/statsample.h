

#ifndef DEV3_STATSAMPLE_H
#define DEV3_STATSAMPLE_H

typedef struct StatSample {
    int count;
    int sum;
    int *data;
    int capacity;
} StatSample;

void init_stat(StatSample *s);

void free_stat(StatSample *s);

void update_stat(int n, StatSample *s);

#endif //DEV3_STATSAMPLE_H
