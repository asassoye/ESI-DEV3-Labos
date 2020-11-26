#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "slcircularlist.h"
#include "slcircularlist_utility.h"

static void printList(struct SLCircularList *list);

int main() {
    struct SLCircularList *list = newSLCL();

    if (list == NULL) {
        perror("La liste a eu un problème d'initialisation");
        return -1;
    }

    puts("\t===Empty list created====");
    printf("&liste = %p => %s\n", (void *) list, list == NULL ? "KO" : "OK");
    printList(list);

    puts("\n\n\t===Add 4 elements===");
    pushSLCL(list, 1);
    pushSLCL(list, 2);
    pushSLCL(list, 3);
    pushSLCL(list, 4);
    printList(list);

    puts("\n\n\t===Pop the list===");
    popSLCL(list);
    printList(list);

    puts("\n\n\t===Free the list===");
    deleteSLCL(&list);
    printf("&liste = %p => %s\n", (void *) list, list == NULL ? "OK" : "KO");

    return 0;
}

static void printList(struct SLCircularList *list) {
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
    printf("}");
}
