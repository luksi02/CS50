import random

# Define a function to roll initiative for an actor
def roll_initiative(actor):
    initiative_bonus = 0
    if actor['name'] == "Hero":
        initiative_bonus += 2
    return random.randint(1, 20) + initiative_bonus

# Define a function to determine the order of movement
def determine_order(actors):
    return sorted(actors, key=lambda x: roll_initiative(x), reverse=True)

# Define a function to perform actions for an actor
def perform_action(actor, target):
    attack_roll = random.randint(1, 20)
    if attack_roll > target['defense']:
        damage = random.randint(actor['attack'] - target['defense'], actor['attack'])
        print(f"{actor['name']} attacks {target['name']} for {damage} damage!")
    else:
        print(f"{actor['name']}'s attack on {target['name']} was unsuccessful.")

# Define the actors and their stats
actors = []

# Add an arbitrary number of actors
for i in range(3):
    actor_name = f"Actor {i}"
    actor_attack = random.randint(5, 15)
    actor_defense = random.randint(3, 10)
    actor = {"name": actor_name, "attack": actor_attack, "defense": actor_defense}
    actors.append(actor)

print("Original actors:", actors)

# Shuffle the list of actors to randomize the order
random.shuffle(actors)

# Roll initiative for all actors
initiative_order = determine_order(actors)

# Perform actions for each actor in their order of movement
for actor in initiative_order:
    remaining_targets = [target for target in actors if target != actor]
    
    if remaining_targets:
        target = random.choice(remaining_targets)
        print(f"\n{actor['name']} is performing an action against {target['name']}")
        perform_action(actor, target)
        actors.remove(target)
    else:
        print(f"\n{actor['name']} has no more targets to attack.")

# Print the final initiative order
print("\nFinal Initiative Order:", [actor['name'] for actor in initiative_order])
