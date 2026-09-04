#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    int age;
};

void add_contact() {
    struct Contact c;
    printf("Enter name: ");
    scanf("%49s", c.name);
    printf("Enter age: ");
    scanf("%d", &c.age);

    FILE *file = fopen("contacts.txt", "a");
    if (!file) {
        printf("Error opening contacts.txt\n");
        return;
    }
    fprintf(file, "%s %d\n", c.name, c.age);
    fclose(file);

    printf("Contact added.\n");
}

void view_contacts() {
    FILE *file = fopen("contacts.txt", "r");
    if (!file) {
        printf("No contacts found.\n");
        return;
    }

    struct Contact c;
    printf("Contacts:\n");
    while (fscanf(file, "%49s %d", c.name, &c.age) == 2) {
        printf("Name: %s, Age: %d\n", c.name, c.age);
    }
    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add contact\n2. View contacts\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_contact();
        } else if (choice == 2) {
            view_contacts();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
