import json
import random

items = {
    "Labor": {},
    "Materials": {},
    "Equipment": {},
    "Overhead": {},
    "Marketing": {},
    "Insurance": {},
    "Consulting": {},
    "Maintenance": {},
    "Utilities": {},
}


def generate_random_numbers():
    first_random = random.randint(1, 36)
    second_random = random.randint(first_random, 36)
    return first_random, second_random


def generate_random_number():
    return random.randint(500, 1350)


for key, value in items.items():
    # Generate random numbers for the range
    first_random, second_random = generate_random_numbers()
    month_cost = {}
    # Use the generated random numbers as the range for the loop
    for month in range(first_random, second_random + 1):
        month_cost[month] = generate_random_number()
    items[key] = month_cost

# Write item costs to a JSON file
output_file = "item_costs.json"
with open(output_file, "w") as json_file:
    json.dump(items, json_file, indent=4)

print(f"Item costs saved to {output_file}")
