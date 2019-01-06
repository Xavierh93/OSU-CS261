#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list)
{
    struct Link *front = (struct Link*)malloc(sizeof(struct Link));
    assert(front != 0);
    
    struct Link *last = (struct Link *)malloc(sizeof(struct Link));
    assert(last != 0);
    
    front -> prev = last;
    front -> next = NULL;
    
    last -> next = front;
    last -> prev = NULL;
    
    list -> frontSentinel = front;
    list -> backSentinel = last;
    list -> size = 0;
   
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
    struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
    struct Link *prevLink;
    prevLink = link -> prev;
    
    link -> prev = newLink;
    prevLink -> next = newLink;
    newLink -> prev = prevLink;
    newLink -> next = link;
    
    newLink -> value = value;
    
    list -> size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
    assert(list -> size != 0);
    
    struct Link *garbage = link;
    
    garbage -> next = NULL;
    garbage -> prev = NULL;
    free(garbage);

    list -> size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list -> frontSentinel);
	free(list -> backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
    struct Link * new = (struct Link *)malloc(sizeof(struct Link));
    struct Link * prevLink;
    prevLink = list -> frontSentinel -> prev;
    
    prevLink -> next = new;
    list -> frontSentinel -> prev = new;
    new -> next = list -> frontSentinel;
    new -> prev = prevLink;
    
    new -> value = value;
    
    list -> size++;
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
    struct Link *new = (struct Link *)malloc(sizeof(struct Link));
    struct Link *prevLink;
    prevLink = list -> backSentinel -> next;
    
    prevLink -> prev = new;
    list -> backSentinel -> next = new;
    
    new -> prev = list -> backSentinel;
    new -> next = prevLink;
    
    
    new -> value = value;
    
    
    list->size++;}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
    assert(list -> size != 0);
    return list -> frontSentinel -> prev -> value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
    assert(list -> size != 0);
    return list -> backSentinel -> next -> value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
    assert(list -> size != 0);
    
    struct Link *garbage = list -> frontSentinel -> prev;
    struct Link *new = list -> frontSentinel -> prev -> prev;
    
    new -> next = list -> frontSentinel;
    list -> frontSentinel -> prev = new;
    
    garbage -> prev = NULL;
    garbage -> next = NULL;
    free(garbage);
    garbage = NULL;
    
    list -> size--;
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
    assert(list -> size != 0);
    
    struct Link *garbage;
    garbage = list -> backSentinel -> next;
    
    struct Link *new = list -> backSentinel -> next -> next;
    new -> prev = list -> backSentinel;
    list -> backSentinel -> next = new;
    
    garbage -> next = NULL;
    garbage -> prev = NULL;
    free(garbage);
    garbage = NULL;
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
    if (list -> size == 0) {
        return 1;
    }
    
    else {
        return 0;
    }
    
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
    assert(list->size != 0);
    struct Link *temp = list -> frontSentinel -> prev;
    
    do {
        printf(" %d ", temp -> value);
        temp = temp -> prev;
        
    } while (temp -> prev != 0);
    
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
    linkedListAddBack(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
    assert(list->size != 0);
    struct Link * current = list -> frontSentinel -> prev;
    
    do {
        if (current -> value == value) {
            return 1;
        }
        current = current -> prev;
        
    } while (current -> prev != 0);
    return 0;}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
    assert(list->size != 0);
    assert(linkedListContains(list, value));
    
    struct Link * current = list->frontSentinel->prev;
    
    do {
        
        if (current -> value == value)
        {
            current -> next -> prev = current -> prev;
            current -> prev -> next = current -> next;
            
            current -> next = NULL;
            current -> prev = NULL;
            free(current);
            
            list -> size--;
            
            return;
        }
        current = current -> prev;
    } while (current != 0);
}
