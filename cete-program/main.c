#include <stdio.h>
#include <stdlib.h>
#define P_COUNT 6

enum MealPreference {
  VEG,
  NONVEG,
  VEGAN,
  JAIN,
  GLUTENFREE,
  KIDS,
};

char *meal_to_string(enum MealPreference meal) {
  switch (meal) {
  case VEG:
    return "Veg";
    break;
  case NONVEG:
    return "Non-Veg";
    break;

  case VEGAN:
    return "Vegan";
    break;

  case JAIN:
    return "Jain";
    break;

  case GLUTENFREE:
    return "Gluten-Free";
    break;

  case KIDS:
    return "Kids";
    break;
  }
}

typedef struct {
  char *name;
  enum MealPreference meal_pref;
} Passenger;

// Reading the input
void read_input(Passenger *passengers) {
  printf("Enter the data for %d passengers: ", P_COUNT);
  Passenger *temp_pass;
  for (int i = 0; i < P_COUNT; i++) {
    printf("Inside for");
    int temp_meal;
    passengers[i].name = (char *)malloc(10 * sizeof(char));
    printf("Name of Passenger #%d: ", i + 1);
    scanf("%s", passengers[i].name);
    printf("Meal Preference for Passenger #%d (0-5): ", i + 1);
    scanf("%d", &temp_meal);
    passengers[i].meal_pref = temp_meal;
  }
}

// Main Manifest
void display_main_manifest(Passenger *passengers) {
  printf("----------------\nMain Manifest\n-------------------\n");
  for (int i = 0; i < P_COUNT; i++) {
    printf("\nPassenger #%d", i + 1);
    printf("\nName: %s", (passengers + i)->name);
    printf("\nMeal Preference: %s",
           meal_to_string((passengers + i)->meal_pref));
  }
}

int main() {
  Passenger *passengers = {};
  // Read input: mutable reference
  read_input(passengers);
  // Display main manifest
  display_main_manifest(passengers);
  return 0;
}
