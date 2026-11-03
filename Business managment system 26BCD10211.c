#include <stdio.h>

int main(void)
{
    int   ids[100];
    float prices[100];
    int   stocks[100];
    int   mins[100];
    int   total = 0;
    int   choice;

    printf("=== SIMPLE SHOP ===\n");

    while (1) {
        printf("\n1. Add\n2. Show\n3. Sell\n4. Reorder list\n5. Exit\n> ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("ID: ");      scanf("%d", &ids[total]);
            printf("Price: ");   scanf("%f", &prices[total]);
            printf("Stock: ");   scanf("%d", &stocks[total]);
            printf("Min: ");     scanf("%d", &mins[total]);
            total++;
            printf("Added!\n");
        }

        else if (choice == 2) {
            int i;
            printf("\nID  Price  Stock  Min\n");
            for (i = 0; i < total; i++)
                printf("%-3d %6.2f %5d %5d\n",
                       ids[i], prices[i], stocks[i], mins[i]);
        }

        else if (choice == 3) {
            int id, qty, i, found = 0;
            printf("ID to sell: ");  scanf("%d", &id);
            printf("Quantity: ");    scanf("%d", &qty);
            for (i = 0; i < total; i++) {
                if (ids[i] == id) {
                    if (qty <= stocks[i]) {
                        stocks[i] -= qty;
                        printf("OK. Stock now: %d\n", stocks[i]);
                    } else {
                        printf("Not enough stock.\n");
                    }
                    found = 1;
                    break;
                }
            }
            if (!found) printf("ID not found.\n");
        }

        else if (choice == 4) {
            int i, low = 0;
            printf("\nNeed reorder:\n");
            for (i = 0; i < total; i++) {
                if (stocks[i] <= mins[i]) {
                    printf("  ID %d (stock %d, min %d)\n",
                           ids[i], stocks[i], mins[i]);
                    low++;
                }
            }
            if (low == 0) printf("  Nothing to reorder.\n");
        }

        else if (choice == 5) {
            printf("Bye!\n");
            break;
        }
    }
    return 0;
}