#include<stdio.h>

struct Pet {
    int id;
    char name[20];
    char species[20];
    int age;    // in years
    float adoption_fee;
};

void displayAllPets(struct Pet p[], int n) {
    printf("\n");
    for(int i = 0 ; i < n ; i++) {
        printf("ID: %d\n", p[i].id);
        printf("Name: %s\n", p[i].name);
        printf("Species: %s\n", p[i].species);
        printf("Age: %d\n", p[i].age);
        printf("Adoption Fee: %.2f\n", p[i].adoption_fee);
        printf("\n");
    }
}

struct Pet* searchPetByID(struct Pet p[], int n, int id) {
    for(int i = 0 ; i < n ; i++) {
        if(p[i].id == id) {
            return &p[i];
        }
    }
    return NULL;
}

void applyDiscount(struct Pet *p, float discount) {
    p->adoption_fee = p->adoption_fee - discount;
}

struct Pet findLowestFeePet(struct Pet p[], int n) {
    struct Pet lowest = p[0];

    for (int i = 0 ; i < n ; i++) {
        if (p[i].adoption_fee < lowest.adoption_fee) {
            lowest = p[i];
        }
    }
    printf("ID: %d\n", lowest.id);
    printf("Lowest fee pet: %s\n", lowest.name);
    printf("Lowest fee: %.2f\n", lowest.adoption_fee);
    printf("Species: %s\n", lowest.species);
    printf("Age: %d\n", lowest.age);

    return lowest;
}

void main() {
    int n;
    struct Pet p[100];
    printf("Pet Adoption Center:");
    printf("\nEnter the number of pets: ");
    scanf("%d", &n);
    printf("\nEnter details of pets:");
    for (int i = 0; i < n ; i++) {
        printf("\nPet #%d:", i+1);
        printf("\nPet Name: ");
        scanf("%s", p[i].name);
        printf("Pet Species: ");
        scanf("%s", p[i].species);
        printf("Pet Age: ");
        scanf("%d", &p[i].age);
        printf("Pet Adoption Fee: ");
        scanf("%f", &p[i].adoption_fee);
        p[i].id = i+1;
    }
    displayAllPets(p, n);
    int id;
    printf("\nEnter the ID of the pet to search: ");
    scanf("%d", &id);
    struct Pet *pet = searchPetByID(p, n, id);
    if(pet != NULL) {
        printf("\nPet found!\n");
        printf("ID: %d\n", pet->id);
        printf("Name: %s\n", pet->name);
        printf("Species: %s\n", pet->species);
        printf("Age: %d\n", pet->age);
        printf("Adoption Fee: %.2f\n", pet->adoption_fee);
    } else {
        printf("\nPet not found.\n");
    }

    float discount;
    printf("\nEnter discount amount: ");
    scanf("%f", &discount);
    applyDiscount(pet, discount);
    printf("Updated Adoption Fee: %.2f\n\n", pet->adoption_fee);

    struct Pet lowest = findLowestFeePet(p, n);
    printf("Lowest fee pet: %s\n", lowest.name);
    printf("Lowest fee: %.2f\n", lowest.adoption_fee);
}