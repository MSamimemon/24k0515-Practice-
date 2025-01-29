#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addSupplies(char ***animal, int totalAnimals, int totalSpecies);
void updateSupplies(char ***animal, int totalAnimals, int totalSpecies);
int removeSpecies(char ***animal, int totalAnimals, int totalSpecies);
void displayInventory(char ***animal, int totalAnimals, int totalSpecies);

int main() {
    printf("Pets in Heart\n");
    
    char ***animal; 
    int totalAnimals, totalSpecies;
    
    
    printf("Enter total animals: ");
    scanf("%d", &totalAnimals);
    printf("Enter total species: ");
    scanf("%d", &totalSpecies);

    
    animal = (char ***)malloc(totalAnimals * sizeof(char**));
    for (int i = 0; i < totalAnimals; i++) {
        animal[i] = (char **)malloc((totalSpecies + 1) * sizeof(char*));  
    }

    int choice; 
    do {
       
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSupplies(animal, totalAnimals, totalSpecies);
                break;
            case 2:
                updateSupplies(animal, totalAnimals, totalSpecies);
                break;
            case 3:
                totalAnimals = removeSpecies(animal, totalAnimals, totalSpecies);
                break;
            case 4:
                displayInventory(animal, totalAnimals, totalSpecies);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5); 

    
    for (int i = 0; i < totalAnimals; i++) {
        for (int y = 0; y <= totalSpecies; y++) {
            free(animal[i][y]);
        }
        free(animal[i]);
    }
    free(animal);

    return 0;
}

void addSupplies(char ***animal, int totalAnimals, int totalSpecies) {
    for (int i = 0; i < totalAnimals; i++) {
        printf("Enter information for animal %d\n", i + 1);
        
        animal[i][0] = (char*)malloc(100 * sizeof(char));
        printf("Enter Animal name: ");
        scanf("%s", animal[i][0]);
        
        for (int j = 1; j <= totalSpecies; j++) {
            animal[i][j] = (char*)malloc(100 * sizeof(char));
            printf("Enter supply for species %d: ", j);
            scanf("%s", animal[i][j]);
        }
    }
}

void updateSupplies(char ***animal, int totalAnimals, int totalSpecies) {
    char name[500];
    printf("Enter animal name whose species to be updated: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < totalAnimals; i++) {
        if (strcmp(animal[i][0], name) == 0) {
            char supplyName[500], newSupply[500];
            printf("Enter supply name to be updated: ");
            scanf("%s", supplyName);
            
            for (int j = 1; j <= totalSpecies; j++) {
                if (strcmp(animal[i][j], supplyName) == 0) {
                    found = 1;
                    printf("Enter new supply name: ");
                    scanf("%s", newSupply);
                    strcpy(animal[i][j], newSupply);
                    return;
                }
            }
        }
    }
    
    if (!found) {
        printf("Animal or supply not found.\n");
    }
}

int removeSpecies(char ***animal, int totalAnimals, int totalSpecies) {
    char name[500];
    printf("Enter animal name to be removed: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < totalAnimals; i++) {
        if (strcmp(animal[i][0], name) == 0) {
            found = 1;
            
            
            for (int j = 1; j <= totalSpecies; j++) {
                free(animal[i][j]);
            }
            
            
            free(animal[i]);
            
            
            for (int k = i; k < totalAnimals - 1; k++) {
                animal[k] = animal[k + 1];
            }
            
            totalAnimals--;
            printf("Animal '%s' removed successfully.\n", name);
            break;
        }
    }
    
    if (!found) {
        printf("Animal not found.\n");
    }
    
    return totalAnimals;
}

void displayInventory(char ***animal, int totalAnimals, int totalSpecies) {
    for (int i = 0; i < totalAnimals; i++) {
        printf("Information for animal %d:\n", i + 1);
        printf("Animal name: %s\n", animal[i][0]);
        
        for (int j = 1; j <= totalSpecies; j++) {
            printf("Supply %d: %s\n", j, animal[i][j]);
        }
    }
}
