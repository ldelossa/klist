#include "./klist.h"

klist_node * klist_append(klist_node *head, klist_node *node) {
    if (!head) {
        return node;
    }

    for (klist_node *cur = head;; cur = cur->next) {
        if (!cur->next) {
            cur->next = node;
            node->prev = cur;
            break;
        }
    }
    return head;
}
