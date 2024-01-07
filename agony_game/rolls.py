import random

# Simple text-to-speech imports
from gtts import gTTS
import os

import pyttsx3

def text_to_speech(text):
    # text = "Hello, this is a text-to-speech conversion example."

    # Create a gTTS object
    tts = gTTS(text=text, lang='en')

    # Save the audio file
    tts.save("output.mp3")

    # Play the audio file
    os.system("start output.mp3")

    return (print(f"Sound saved!"))

text = "Hello, this is a text-to-speech conversion example."


# Initialize the TTS engine
engine = pyttsx3.init()

# Set the properties (optional)
engine.setProperty('rate', 150)  # Speed of speech
engine.setProperty('volume', 1.0)  # Volume level (0.0 to 1.0)

# Input text
text = "Hello, this is a text-to-speech conversion example."

# Set the voice (optional, if omitted, it will use the default voice)
# You can find available voices using engine.getProperty('voices')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)  # Selecting a different voice

# Convert text to speech
# engine.say(text)

# lets say that this is a combat mechanics - attack roll against armor class (AC) - attack roll has to be higher than AC

# TODO - damage roll
# TODO - advantage/disadvantage roll
# TODO - enemy HP 


def roll_dice(dice, modifiers=0):
    return random.randint(1, dice) + modifiers

def apply_modifiers(result, modifiers):
    return result + modifiers

def interpret_outcome(result):
    if result <= 2:
        return "Critical Failure"
    elif result <= 4:
        return "Standard Success"
    else:
        return "Critical Success"

# Example Usage - exemplary data:
weapon = "Greatsword"
weapon_damage_dice = 10
spell_damage_dice = 10
dice_type = 20  # For example, a D20
dice_result = roll_dice(dice_type)
modifiers = 1  # For example, a +1 bonus
modified_result = apply_modifiers(dice_result, modifiers)
enemy_AC = 10
initial_enemy_HP = 30
hero_HP = 100
hero_AC = 10

# outcome = interpret_outcome(modified_result)
# print(f"Original Attack Roll: {dice_result}")
# print(f"Modified Result: {modified_result}")
# # print(f"Attack Roll Outcome: {outcome}")
# print(f"Enemy's armour class: {enemy_AC}")

def attack_roll(dice_result, enemy_AC, enemy_HP):
    if dice_result > enemy_AC:
        print("Hit!")
        damage_dealt = roll_dice(weapon_damage_dice)
        enemy_HP -= damage_dealt
        outcome = f"Hit! Enemy has lost {damage_dealt} hit points! Remaining enemy hit points: {enemy_HP}"
        
    else:
        print("Miss!")
        outcome = "Miss"
    return outcome, enemy_HP

outcomes = []

def spell_attack(enemy_HP):
    global outcomes  # Declare outcomes as global so it can be accessed and modified

    spell_attack_roll = roll_dice(20)
    spell_save_roll = roll_dice(20)

    if spell_attack_roll >= spell_save_roll:
        spell_damage = roll_dice(spell_damage_dice)
        enemy_HP -= spell_damage  # Use the shorthand operator to update enemy_HP

        spell_outcome = f"Hit! Enemy has lost {spell_damage} hit points by spell! Remaining enemy hit points: {enemy_HP}"
        outcomes.append(spell_outcome)

        print(spell_outcome)
        print("Spell hit the target!")
    else:
        print("Spell missed the target!")
        spell_outcome = "Spell missed the target!"

    return spell_outcome, enemy_HP

# Simulate combat to death
def combat(initial_enemy_HP, enemy_AC, hero_HP, hero_AC):
    global outcomes  # Declare outcomes as global so it can be accessed and modified

    enemy_HP = initial_enemy_HP

    while enemy_HP > 0 and hero_HP > 0:
        # Hero's turn
        spell_outcome, enemy_HP = spell_attack(enemy_HP)
        outcomes.append(spell_outcome)

        # Enemy's turn
        enemy_outcome, hero_HP = attack_roll(roll_dice(20), hero_AC, hero_HP)
        outcomes.append(enemy_outcome)

    for outcome in outcomes:
        print(outcome)
        engine.say(outcome)

# Example usage:
initial_enemy_HP = 30
enemy_AC = 15
hero_HP = 50
hero_AC = 12
spell_damage_dice = 10

engine = pyttsx3.init()  # Initialize TTS engine

combat(initial_enemy_HP, enemy_AC, hero_HP, hero_AC)
    

# weapon = "Greatsword"
# weapon_damage_dice = 10

# outcome = attack_roll(dice_result, enemy_AC, enemy_HP)

# # spell_outcome = spell_attack(enemy_HP)

# battle_result = "Attack Roll: " + str(modified_result) + ".\n against Enemy's armour class: " + str(enemy_AC) + ".\n Final attack roll outcome: " + outcome

# spell_result = spell_outcome
# print(battle_result)

# ## gTTS
# text_to_speech(spell_result)
# text_to_speech(output)
# text_to_speech(battle_result)

# engine.say(spell_result)
# engine.say(battle_result)


# for voice in voices:
#     print("\n")
#     print("ID:", voice.id)
#     print("Name:", voice.name)
#     print("Languages:", voice.languages)
#     print("Gender:", voice.gender)
#     print("Age:", voice.age)
#     print("\n")

# Wait for the speech to finish
engine.runAndWait()