#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int enterprior();
void createtask(task_linked_list *list, int *cgr);
void createrandomtask(task_linked_list *list, int *cgr, int counter);
void printfronttll(task_linked_list *list);
struct task getfrontchoose(task_linked_list *list);