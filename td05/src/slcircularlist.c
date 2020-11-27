#include "slcircularlist.h"
#include "slcircularlist_utility.h"
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

struct SLCircularList *newSLCL(void) {
    struct SLCircularList *list = malloc(sizeof(struct SLCircularList));

    if (list == NULL) {
        errno = ESLLMEMORYFAIL;
        return NULL;
    }

    struct SLNode *sentinel = newSLN((value_t) 0);

    if (sentinel == NULL) {
        free(list);
        errno = ESLLMEMORYFAIL;
        return NULL;
    }
    sentinel->next = sentinel;
    list->entry = sentinel;

    return list;
}

void deleteSLCL(struct SLCircularList **adpSLCL) {
    assert(adpSLCL != NULL);
    assert(*adpSLCL != NULL);

    // Clear the list
    clearSLCL(*adpSLCL);

    // Free the sentinel
    struct SLNode *sentinel = (*adpSLCL)->entry;
    deleteSLN(&sentinel);

    // Free the list
    free(*adpSLCL);
    *adpSLCL = NULL;
}

void clearSLCL(struct SLCircularList *pSLCL) {
    assert(pSLCL != NULL);

    struct SLNode *sentinel = pSLCL->entry;
    struct SLNode *actual = nextSLN(sentinel);
    struct SLNode *next;
    while (actual != sentinel) {
        next = actual->next;
        deleteSLN(&actual);
        actual = next;
    }
    sentinel->next = sentinel;
}

struct SLNode *entrySLCL(const struct SLCircularList *pSLCL) {
    assert(pSLCL != NULL);

    return pSLCL->entry;
}

bool emptySLCL(const struct SLCircularList *pSLCL) {
    assert(pSLCL != NULL);

    struct SLNode *sentinel = pSLCL->entry;
    return sentinel->next == sentinel ? true : false;
}

struct SLNode *pushSLCL(struct SLCircularList *pSLCL, value_t value) {
    assert(pSLCL != NULL);

    struct SLNode *sentinel = pSLCL->entry;
    struct SLNode *newElement = newSLN(value);

    if (newElement == NULL) {
        errno = ESLLMEMORYFAIL;
        return NULL;
    }

    setNextSLN(newElement, nextSLN(sentinel));
    setNextSLN(sentinel, newElement);

    return newElement;
}

struct SLNode *insertSLCL(struct SLCircularList *pSLCL, struct SLNode *pSLN, value_t value) {
    assert(pSLCL != NULL);

    struct SLNode *sentinel = pSLCL->entry;
    if (pSLN == NULL || pSLN == sentinel->next) {
        return pushSLCL(pSLCL, value);
    }

    struct SLNode *previous = previousSLCL(pSLCL, pSLN);
    struct SLNode *new = newSLN(value);

    setNextSLN(new, pSLN);
    setNextSLN(previous, new);

    return new;
}

struct SLNode *popSLCL(struct SLCircularList *pSLCL) {
    assert(pSLCL != NULL);

    struct SLNode *sentinel = pSLCL->entry;
    if (sentinel->next == sentinel) {
        errno = ESLLEMPTY;
        return NULL;
    }

    struct SLNode *actual = sentinel->next;
    sentinel->next = actual->next;
    deleteSLN(&actual);

    return sentinel->next == sentinel ? NULL : sentinel->next;
}

struct SLNode *eraseSLCL(struct SLCircularList *pSLCL, struct SLNode *pSLN) {
    assert(pSLCL != NULL);
    assert(pSLN != NULL);
    assert(isElementOfSLCL(pSLCL, pSLN));

    struct SLNode *sentinel = entrySLCL(pSLCL);

    if (pSLN == nextSLN(sentinel)) {
        return popSLCL(pSLCL);
    }

    struct SLNode *previous = previousSLCL(pSLCL, pSLN);
    setNextSLN(previous, nextSLN(pSLN));
    deleteSLN(&pSLN);

    return getNextSLCN(pSLCL, previous);
}
