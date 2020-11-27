

#ifndef DEV3_STATSAMPLE_H
#define DEV3_STATSAMPLE_H

typedef struct StatSample {
    int count;
    int sum;
    int *data;
} StatSample;

void init_stat(StatSample *s);

#endif //DEV3_STATSAMPLE_H
