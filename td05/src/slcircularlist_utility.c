#include <assert.h>
#include <stdio.h>
#include "slcircularlist_utility.h"

size_t sizeSLCL(const struct SLCircularList *pSLCL) {
    assert(pSLCL != NULL);

    size_t count = 0;
    struct SLNode *sentinel = pSLCL->entry;
    struct SLNode *actual = nextSLN(sentinel);
    while (actual != sentinel) {
        ++count;
        actual = nextSLN(actual);
    }

    return count;
}

void printList(struct SLCircularList *list, bool newline) {
    assert(list != NULL);

    size_t length = sizeSLCL(list);
    struct SLNode *sentinel = entrySLCL(list);
    struct SLNode *actual = nextSLN(sentinel);

    printf("liste = {");
    for (size_t i = 0; i < length; ++i) {
        if (i == length - 1) {
            printf("%d", valueSLN(actual));
        } else {
            printf("%d, ", valueSLN(actual));
        }
        actual = nextSLN(actual);
    }
    if (newline) {
        printf("}\n");
    } else {
        printf("}");
    }
}

struct SLNode *previousSLCL(const struct SLCircularList *pSLCL, const struct SLNode *pSLN) {
    assert(pSLCL != NULL);
    assert(pSLN != NULL);
    assert(isElementOfSLCL(pSLCL, pSLN));

    struct SLNode *actual = (struct SLNode *) pSLN;
    struct SLNode *next = getNextSLCN(pSLCL, actual);

    while (next != pSLN) {
        actual = next;
        next = getNextSLCN(pSLCL, actual);
    }

    return actual;
}

bool isElementOfSLCL(const struct SLCircularList *pSLCL, const struct SLNode *pSLN) {
    assert(pSLCL != NULL);
    assert(pSLN != NULL);

    size_t length = sizeSLCL(pSLCL);
    struct SLNode *sentinel = entrySLCL(pSLCL);
    struct SLNode *actual = nextSLN(sentinel);

    for (size_t i = 0; i < length; ++i) {
        if (actual == pSLN) {
            return true;
        }
        actual = nextSLN(actual);
    }

    return false;
}

struct SLNode *getNextSLCN(const struct SLCircularList *pSLCL, const struct SLNode *pSLN) {
    assert(pSLCL != NULL);
    assert(pSLN != NULL);
    assert(isElementOfSLCL(pSLCL, pSLN));

    struct SLNode *sentinel = entrySLCL(pSLCL);
    struct SLNode *next = nextSLN(pSLN);

    if (next == sentinel) {
        return nextSLN(sentinel);
    }

    return next;
}

struct SLNode *getSLCNByPositionSLCN(const struct SLCircularList *pSLCL, size_t position) {
    assert(pSLCL != NULL);
    assert(position >= 0);

    if (emptySLCL(pSLCL)) {
        return NULL;
    }

    struct SLNode *sentinel = entrySLCL(pSLCL);
    struct SLNode *actual = nextSLN(sentinel);

    for (size_t i = 0; i < position; ++i) {
        actual = getNextSLCN(pSLCL, actual);
    }

    return actual;
}
