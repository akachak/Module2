#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct task{
    int id;
    int priority;
    char msg[100];
};

typedef struct _task_node{
    struct task nodetask;
    struct _task_node *next;
    struct _task_node *prev;
}task_node;

typedef struct _task_linked_list {
    size_t size;
    task_node *head;
    task_node *tail;
} task_linked_list;


task_linked_list* createtll();
void deletetll(task_linked_list **list);
void pushbacktll(task_linked_list *list, struct task newtask);
void deletetaskbyid(task_linked_list *list, int delid);
struct task getfrontfirst(task_linked_list *list);
struct task getfrontbypr(task_linked_list *list, int prior);
struct task getfrontnothigh(task_linked_list *list, int prior);
