#include "event_res.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    struct event newEvent;
    //predefined events
    struct event e1 = {1, "Baraat", "Karachi", "12-12-2020"};
    struct event e2 = {2, "Mehndi", "Lahore", "13-12-2020"};
    struct event e3 = {3, "Walima", "Islamabad", "14-12-2020"};
    adding_event(e1);
    adding_event(e2);
    adding_event(e3);
    int id;
    while(1) {
        printf("1. Add Event\n");
        printf("2. Display Event\n");
        printf("3. Update Event\n");
        printf("4. Delete Event\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter event id: ");
                scanf("%d", &newEvent.id);
                printf("Enter event name: ");
                scanf("%s", newEvent.name);
                printf("Enter event place: ");
                scanf("%s", newEvent.place);
                printf("Enter event date: ");
                scanf("%s", newEvent.event_date);
                adding_event(newEvent);
                break;
            case 2:
                display_event();
                break;
            case 3:
                printf("Enter event id to update: ");
                scanf("%d", &id);
                updatig_event(id);
                break;
            case 4:
                printf("Enter event id to delete: ");
                scanf("%d", &id);
                deleting_event(id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}