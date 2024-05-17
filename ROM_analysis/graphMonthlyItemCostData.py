import json
import matplotlib.pyplot as plt

# Load the JSON data from the file
with open("item_costs.json", "r") as json_file:
    data = json.load(json_file)

# Extract item names, start months, end months, and their respective costs
items = list(data.keys())
start_months = {item: int(min(data[item].keys())) for item in items}
end_months = {item: int(max(data[item].keys())) for item in items}
months = list(range(1, 37))  # x-axis from 1 to 36
costs = {item: [data[item].get(str(month), 0) for month in months] for item in items}

# Plotting the data
plt.figure(figsize=(12, 8))

for item in items:
    # Calculate the start and end indices based on the start and end months for each item
    start_index = months.index(start_months[item])
    end_index = months.index(end_months[item]) + 1  # +1 to include the end month
    plt.plot(
        months[start_index:end_index], costs[item][start_index:end_index], label=item
    )

plt.xlabel("Months")
plt.ylabel("Cost")
plt.title("Cost of Items Over Months")
plt.legend()
plt.grid(True)
plt.tight_layout()

# Show the plot
plt.show()
