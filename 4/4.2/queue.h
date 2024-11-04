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

int enterprior();
struct task createtask(int *cgr);
struct task createrandomtask(int *cgr);
task_linked_list* createtll();
void deletetll(task_linked_list **list);
void pushbacktll(task_linked_list *list,  bool checkrandom, int *cgr, int *count_r);
void printfronttll(task_linked_list *list);
int getprintfronttll(task_linked_list *list, bool checkcmd, int prior);
bool checkbyid(task_linked_list *list, int checkid);
struct task gettaskbyid (task_linked_list *list, int getid);
void deletetaskbyid(task_linked_list *list, int delid);
struct task getfronttll(task_linked_list *list);
