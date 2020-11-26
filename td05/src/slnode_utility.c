#include <assert.h>
#include "slnode_utility.h"

struct SLNode *forwardSLN(struct SLNode *pSLN, size_t distance) {
    assert(pSLN != NULL);

    struct SLNode *actual = pSLN;
    for (size_t i = 0; i < distance; ++i) {
        actual = actual->next;
        if (actual == NULL) {
            return NULL;
        }
    }

    return actual;
}
