#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
    TYPE value;
    struct Link * next;
    struct Link * prev;
};

struct CircularList
{
    int size;
    struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
    list -> sentinel = (struct Link*)malloc(sizeof(struct Link));
    assert(list -> sentinel != 0);
    
    list -> sentinel -> next = list -> sentinel;
    list -> sentinel -> prev = list -> sentinel;
    list -> sentinel -> value = -1;
    list -> size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
    struct Link *newLink = (struct Link*)malloc(sizeof(struct Link));
    
    newLink -> next = NULL;
    newLink -> prev = NULL;
    newLink -> value = value;
    return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
    
    struct Link *temp = createLink(value);
    
    
    temp -> prev = link;
    temp -> next = link -> next;
    
    temp -> next -> prev = temp;
    temp -> prev -> next = temp;
    
    list -> size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
    link -> prev -> next = link -> next;
    link -> next -> prev = link -> prev;
    
    link -> next = NULL;
    link -> prev = NULL;
    free(link);
    link = NULL;
    list -> size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
    struct CircularList* list = (struct CircularList *)malloc(sizeof(struct CircularList));
    init(list);
    return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
    while (!circularListIsEmpty(list))
    {
        struct Link *temp = list -> sentinel -> next;
        removeLink(list,temp);
    }
    free(list -> sentinel);
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
    addLinkAfter(list, list -> sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
    addLinkAfter(list, list -> sentinel -> prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
    assert(list != 0);
    assert(list -> size > 0);
    
    return list -> sentinel -> next -> value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
    assert(list != 0);
    assert(list -> size > 0);
    
    return list -> sentinel -> prev -> value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
    assert(!circularListIsEmpty(list));
    
    removeLink(list, list -> sentinel -> next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
    assert(!circularListIsEmpty(list));
    
    removeLink(list, list -> sentinel -> prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
    assert(list != 0);
    
    if (list -> size == 0)
        return 1;
    return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
    assert(list != 0);
    assert(!circularListIsEmpty(list));
    int size = list -> size;
    
    struct Link *temp = list -> sentinel -> next;
    
    while (size)
    {
        printf("%g, ", temp -> value);
        temp = temp -> next;
        size--;
    }
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
    assert(list != 0);
    assert(!circularListIsEmpty(list));
    
    struct Link *itr = list -> sentinel;
    
    for (int i = 0; i < list -> size + 1; i++)
    {
        struct Link *temp = itr -> next;
        itr -> next = itr -> prev;
        itr -> prev = temp;
        itr = itr -> next;
    }
}
