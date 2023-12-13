#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30
#define PHONE_LEN 20
/* Code by Daniel Redington:
This program manages and tracks a guest list at a restauraunt and then creates reservations based on entered information
Should the phone number match one already in the system, it will return an error message. This system allows the user to add guest
information, print out information, remove informationn, and quit the system.
*/


struct guest {
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    int party_size;
    struct guest *next;
};

struct guest *add_guest(struct guest *list);
struct guest *remove_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);

int main(void) {
    char code;
    struct guest *new_list = NULL;

    printf("Operation Code: a for adding to the list at the end, r for removing from the list, p for printing the list; q for quit.\n");

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */;
        
        switch (code) {
            case 'a':
                new_list = add_guest(new_list);
                break;
            case'r':
                new_list = remove_guest(new_list);
                break;
            case 'p':
                print_list(new_list);
                break;
            case 'q':
                clear_list(new_list);
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}
// This program allocates the memory for the guest list and allows it to expannd
struct guest *add_guest(struct guest *list) {
    
    struct guest *newPeep = (struct guest *)malloc(sizeof(struct guest));

    if (newPeep == NULL) {
      printf("Unable to allocate memory\n");
       return list;
    }

    printf("Enter phone number: ");
    read_line(newPeep->phone, PHONE_LEN);
    // This section compares to see if the phone number is already in the system
        struct guest *temp = list;
    while (temp != NULL) {
        if (strcmp(temp->phone, newPeep->phone) == 0) {
            printf("guest already exists.\n");
            free(newPeep);
            return list; 
        }
       temp= temp->next;
    }
    printf("Enter guest's last name: ");
    read_line(newPeep->last, NAME_LEN);
    printf("Enter guest's first name: ");
    read_line(newPeep->first, NAME_LEN);
    printf("Enter party size: ");
    scanf("%d", &(newPeep->party_size));
    newPeep->next = NULL;
    // if the list is empty this sets newPeep as the head and if it's not empty then it makes it point to the next list
    if (list == NULL) {
        list = newPeep;
    } else {
        struct guest *temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPeep;
    }

    return list;
}
// This function searches for a guest and removes it from the list
struct guest* remove_guest(struct guest *list) {
    if (list == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    char templast[NAME_LEN + 1];
    char tempfirst[NAME_LEN + 1];
    char tempnum[PHONE_LEN + 1];
    printf("Enter phone number:");
    read_line(tempnum, PHONE_LEN);
    printf("Enter guest's last name:");
    read_line(templast, NAME_LEN);
    printf("Enter guest's first name:");
    read_line(tempfirst, NAME_LEN);

    struct guest *cur = list;
    struct guest *prev = NULL;

    while (cur != NULL) {
        if (strcmp(templast, cur->last) == 0 && strcmp(tempfirst, cur->first) == 0 && strcmp(tempnum, cur->phone) == 0) {
            if (prev == NULL) { 
                list = cur->next;
                free(cur);
                return list;
            } else {
                prev->next = cur->next;
                free(cur);
                return list;
            }
        }
        prev = cur;
        cur = cur->next;
    }

    printf("Guest not found.\n");
    return list; // Guest not found, return the original list
}

void print_list(struct guest *list) {

    while (list != NULL) {
        printf("%-15s%-20s%-20s%5d\n", list->phone, list->last, list->first, list->party_size);
        list = list->next;
    }
}
// This section clears out all the data by storing the address of the next node before freeing the memory of the current node
void clear_list(struct guest *list) {
    struct guest *temp = list;
    struct guest *next;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;

    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0';
    return i;
}
