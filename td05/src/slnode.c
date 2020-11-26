#include "slnode.h"
#include <stdlib.h>
#include <assert.h>

struct SLNode *newSLN(value_t value) {
    struct SLNode *slNode = malloc(sizeof(struct SLNode));

    if (slNode == NULL) {
        return NULL;
    }

    slNode->next = NULL;
    slNode->value = value;

    return slNode;
}

void deleteSLN(struct SLNode **adpSLN) {
    assert(adpSLN != NULL);
    assert(*adpSLN != NULL);

    free(*adpSLN);
    *adpSLN = NULL;
}

struct SLNode *nextSLN(const struct SLNode *pSLN) {
    assert(pSLN != NULL);

    return pSLN->next;
}

void setNextSLN(struct SLNode *pSLN, struct SLNode *pNexNext) {
    assert(pSLN != NULL);

    pSLN->next = pNexNext;
}

value_t valueSLN(const struct SLNode *pSLN) {
    assert(pSLN != NULL);

    return pSLN->value;
}

void setValueSLN(struct SLNode *pSLN, value_t newValue) {
    assert(pSLN != NULL);

    pSLN->value = newValue;
}
