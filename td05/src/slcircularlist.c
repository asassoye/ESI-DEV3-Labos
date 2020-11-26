#include "slcircularlist.h"
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

    // TODO
    return NULL;
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
    //TODO
    return NULL;
}
