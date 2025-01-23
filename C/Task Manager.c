#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_LENGTH 50

enum PriorityList {
    LOW, MODERATE, HIGH
};

// function prototype
void menu();

// global variables
int id;
char *options[] = {"Add Task", "Delete Task", "Mark Task as Completed", "Exit"};
char descriptionList[MAX_SIZE][MAX_LENGTH];
enum PriorityList priorityList[MAX_SIZE];
int size = sizeof(options) / sizeof(options[0]);
char input[10];
char description, name[MAX_LENGTH];
int currentTasks = 0;

void menu() {
    int flag = 1;
    while (flag) {
        printf("Hello, enter your name so we can know you: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Enter your ID (at least 8 in length): ");
        scanf("%d", &id);
        getchar();

        for (int i = 0; i < size; i++) {
            printf("%d. %s\n", i + 1, options[i]);
        }

        printf("Enter desired operation (1-4): ");
        int desire;
        scanf("%d", &desire);
        getchar();

        switch (desire) {
            case 1: {
                printf("How many tasks do you want to add? Enter here: ");
                int numOfTasks;
                scanf("%d", &numOfTasks);
                getchar();

                for (int a = 0; a < numOfTasks; a++) {
                    if (currentTasks >= MAX_SIZE) {
                        printf("Task list is full!\n");
                        break;
                    }

                    printf("Enter task %d: ", a + 1);
                    fgets(descriptionList[currentTasks], sizeof(descriptionList[currentTasks]), stdin);
                    descriptionList[currentTasks][strcspn(descriptionList[currentTasks], "\n")] = 0;

                    printf("Priority (Low, Moderate, High): ");
                    fgets(input, sizeof(input), stdin);
                    input[strcspn(input, "\n")] = 0;

                    for (int b = 0; input[b]; b++) {
                        input[b] = tolower(input[b]);
                    }

                    if (strcmp(input, "low") == 0) {
                        priorityList[currentTasks] = LOW;
                    } else if (strcmp(input, "moderate") == 0) {
                        priorityList[currentTasks] = MODERATE;
                    } else if (strcmp(input, "high") == 0) {
                        priorityList[currentTasks] = HIGH;
                    } else {
                        printf("Invalid priority, setting to LOW by default.\n");
                        priorityList[currentTasks] = LOW;
                    }

                    currentTasks++;
                }

                printf("List of tasks:\n");
                for (int d = 0; d < currentTasks; d++) {
                    printf("%d. Description: %s\n", d + 1, descriptionList[d]);
                    switch (priorityList[d]) {
                        case LOW:
                            printf("   Priority: Low\n");
                            break;
                        case MODERATE:
                            printf("   Priority: Moderate\n");
                            break;
                        case HIGH:
                            printf("   Priority: High\n");
                            break;
                        default:
                            printf("   Invalid priority\n");
                            break;
                    }
                }
                break;
            }
            case 2: {
                int toDelete, index;
                printf("How many tasks do you want to delete? Enter here: ");
                scanf("%d", &toDelete);
                getchar();

                for (int e = 0; e < toDelete; e++) {
                    printf("Enter task number to remove (1 to %d): ", currentTasks);
                    scanf("%d", &index);
                    getchar();

                    if (index <= 0 || index > currentTasks) {
                        printf("Invalid index!\n");
                    } else {
                        for (int f = index - 1; f < currentTasks - 1; f++) {
                            strcpy(descriptionList[f], descriptionList[f + 1]);
                            priorityList[f] = priorityList[f + 1];
                        }
                        currentTasks--;
                        printf("Task deleted successfully.\n");
                    }
                }
                break;
            }
            case 3: {
                int completedTask;
                printf("Enter task number to mark as completed (1 to %d): ", currentTasks);
                scanf("%d", &completedTask);
                getchar();

                if (completedTask <= 0 || completedTask > currentTasks) {
                    printf("Invalid task number!\n");
                } else {
                    printf("Task %d: \"%s\" marked as completed.\n", completedTask, descriptionList[completedTask - 1]);
                }
                break;
            }
            case 4:
                printf("Exiting program.\n");
                flag = 0;
                break;
            default:
                printf("Invalid option. Please choose between 1 and 4.\n");
                break;
        }
    }
}

int main(int argc, char **argv) {
    menu();
    return 0;
}
