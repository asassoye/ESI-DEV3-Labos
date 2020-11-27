#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "slcircularlist.h"
#include "slcircularlist_utility.h"

int main() {
    struct SLCircularList *list = newSLCL();

    if (list == NULL) {
        perror("La liste a eu un problème d'initialisation");
        return -1;
    }

    puts("\t===Empty list created====");
    printf("&liste = %p => %s\n", (void *) list, list == NULL ? "KO" : "OK");
    printList(list, true);

    puts("\n\n\t===Add 4 elements===");
    struct SLNode *value1 = pushSLCL(list, 1);
    pushSLCL(list, 2);
    struct SLNode *valeur3 = pushSLCL(list, 3);
    struct SLNode *value4 = pushSLCL(list, 4);
    printList(list, true);

    puts("\n\t===Verifier si un Node est bien dans la liste===");
    struct SLNode *valeur6 = newSLN(6);
    printf("L'élement %d est dans la liste => %s\n", valueSLN(valeur3),
           isElementOfSLCL(list, valeur3) == true ? "Oui" : "Non");
    printf("L'élement %d est dans la liste => %s\n", valueSLN(valeur6),
           isElementOfSLCL(list, valeur6) == true ? "Oui" : "Non");
    deleteSLN(&valeur6);

    puts("\n\t===Element précédent===");
    struct SLNode *previous = previousSLCL(list, value1);
    printf("L'élement %d precede l'élement %d\n", valueSLN(previous), valueSLN(value1));
    previous = previousSLCL(list, valeur3);
    printf("L'élement %d precede l'élement %d\n", valueSLN(previous), valueSLN(valeur3));
    previous = previousSLCL(list, value4);
    printf("L'élement %d precede l'élement %d\n", valueSLN(previous), valueSLN(value4));

    puts("\n\t===Get element by position in list===");
    size_t position = 0;
    printf("L'élement a la position %zd est %d\n", position, valueSLN(getSLCNByPositionSLCN(list, position)));
    position = 1;
    printf("L'élement a la position %zd est %d\n", position, valueSLN(getSLCNByPositionSLCN(list, position)));
    position = 2;
    printf("L'élement a la position %zd est %d\n", position, valueSLN(getSLCNByPositionSLCN(list, position)));
    position = 3;
    printf("L'élement a la position %zd est %d\n", position, valueSLN(getSLCNByPositionSLCN(list, position)));
    position = 4;
    printf("L'élement a la position %zd est %d\n", position, valueSLN(getSLCNByPositionSLCN(list, position)));

    puts("\n\t===Pop the list===");
    popSLCL(list);
    printList(list, true);

    puts("\n\t===Insertion en milieu de la liste===");
    struct SLNode *value42 = insertSLCL(list, value1, 42);
    printList(list, true);
    struct SLNode *value69 = insertSLCL(list, valeur3, 69);
    printList(list, true);

    puts("\n\t===Supprimer en mileu de liste===");
    eraseSLCL(list, value42);
    printList(list, true);
    eraseSLCL(list, value69);
    printList(list, true);

    puts("\n\t===Free the list===");
    deleteSLCL(&list);
    printf("&liste = %p => %s\n", (void *) list, list == NULL ? "OK" : "KO");

    return 0;
}
