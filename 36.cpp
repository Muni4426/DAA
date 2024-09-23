//Sharan.B(192210486//
#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

int items[MAX_ITEMS];
int containers[MAX_CONTAINERS];
int n_items, n_containers;

bool canFit(int item, int container) {
    return containers[container] >= items[item];
}

void loadItem(int item, int container) {
    containers[container] -= items[item];
}

bool loadItems(int item) {
    if (item == n_items)
        return true;

    for (int i = 0; i < n_containers; i++) {
        if (canFit(item, i)) {
            loadItem(item, i);
            if (loadItems(item + 1))
                return true;
            containers[i] += items[item]; // backtrack
        }
    }
    return false;
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n_items);
    printf("Enter item sizes:\n");
    for (int i = 0; i < n_items; i++)
        scanf("%d", &items[i]);

    printf("Enter number of containers: ");
    scanf("%d", &n_containers);
    printf("Enter container capacities:\n");
    for (int i = 0; i < n_containers; i++)
        scanf("%d", &containers[i]);

    if (loadItems(0))
        printf("All items can be loaded.\n");
    else
        printf("Not all items can be loaded.\n");

    return 0;
}

