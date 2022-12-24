#pragma once

#include <stddef.h>
#include <stdint.h>

// a linked list node to embed within another structure.
typedef struct klist_node {
  struct klist_node *next;
  struct klist_node *prev;
} klist_node;

// Iterate over a klist.
// @head a pointer the the klist_node within the structure being iterated.
// @type the type that @head is embedded in
// @member the member where the @klist_node exists
//
// This is a macro which constructs a for loop with a @data variable
// containing a variable of @type.
// The caller of the macro can manipulate the @data variable as they see
// fit then close the for loop with an ending "}"
#define KLIST_ITERATE(head, type, member)                                \
  klist_node *cur = head;                                                                                                       \
  type *data = (type *)((uint8_t *)cur - offsetof(type, member));        \
  for (; cur != NULL; cur = cur->next, data = (type *)((uint8_t *)cur - offsetof(type, member)))                             \

// Append an item to the list.
// Both @head and @node should be embedded into the same type.
//
// Returns a pointer of the list's head.
klist_node *klist_append(klist_node *head, klist_node *node);
