#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char description[100];
  int completed;
} Task;

// Function to add a new task to the list
void add_task(Task list[], int *counter, const char *description) {
  if (*counter < 100) {
    Task new_task;
    strcpy(new_task.description, description);
    new_task.completed = 0; // Initially, the task is not completed

    list[*counter] = new_task;
    (*counter)++;

    printf("Task added successfully!\n");
  } else {
    printf("Task list is full. Cannot add more tasks.\n");
  }
}

// Function to remove a task from the list
void remove_task(Task list[], int *counter, int index) {
  if (index >= 0 && index < *counter) {
    for (int i = index; i < (*counter - 1); i++) {
      list[i] = list[i + 1];
    }

    (*counter)--;
    printf("Task removed successfully!\n");
  } else {
    printf("Invalid index. Task not removed.\n");
  }
}

// Function to mark a task as completed
void mark_completed(Task list[], int counter, int index) {
  if (index >= 0 && index < counter) {
    list[index].completed = 1;
    printf("Task marked as completed!\n");
  } else {
    printf("Invalid index. No changes made.\n");
  }
}

// Function to display the task list
void display_list(Task list[], int counter) {
  printf("Task List:\n");
  for (int i = 0; i < counter; i++) {
    printf("%d. [%s] %s\n", i + 1, (list[i].completed ? "X" : " "), list[i].description);
  }
  printf("\n");
}

int main() {
  Task task_list[100];
  int task_count = 0;
  int option, index;
  char description[100];

  do {
    printf("==== Task List App ====\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Display Task List\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter the description of the new task: ");
        scanf(" %[^\n]", description);
        add_task(task_list, &task_count, description);
        break;

      case 2:
        printf("Enter the index of the task to be removed: ");
        scanf("%d", &index);
        remove_task(task_list, &task_count, index - 1);
        break;

      case 3:
        printf("Enter the index of the task to be marked as completed: ");
        scanf("%d", &index);
        mark_completed(task_list, task_count, index - 1);
        break;

      case 4:
        display_list(task_list, task_count);
        break;

      case 0:
        printf("Exiting the app. See you later!\n");
        break;

      default:
        printf("Invalid option. Please try again.\n");
    }

  } while (option != 0);

  return 0;
}