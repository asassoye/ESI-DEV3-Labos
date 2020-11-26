

#include <assert.h>
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
