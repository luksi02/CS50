import speech_recognition as sr
import pyttsx3
import pyautogui
import webbrowser
import datetime
from Bard import Chatbot
from dotenv import load_dotenv
import os

load_dotenv()

tasks = []
listening_to_task = False

# BARD

token = os.environ.get("token")
ts_token = os.environ.get("ts_token")



chatbot = Chatbot(token, ts_token)


def prompt_bard(prompt):
    response = chatbot.ask("""Pretend you're AI of one of human spaceships sent 
                           for colonisation of other planets, one crew member 
                           is interested about: """ + prompt)
    return response['content']

# prompt_text = "what is google bard?"
# response = prompt_bard(prompt_text)
# print("\033[31m" + 'Bards response: ', response, '\n' + "\033[0m")


def listen_for_command():
    recognizer = sr.Recognizer()

    with sr.Microphone() as source:
        print("Listening for commands...")
        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

    try:
        command = recognizer.recognize_google(audio)
        print("You said:", command)
        return command.lower()
    except sr.UnknownValueError:
        print("Could not understand audio. Please try again.")
        return None
    except sr.RequestError:
        print("Unable to access the Google Speech Recognition API.")
        return None

def respond(response_text):
    print(response_text)

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

    engine.say(response_text)
    engine.runAndWait()


def read_recorded_speech():
    respond("Previously recorded entries: ")
    try:
        with open("recorded_speech.txt", "r") as file:
            contents = file.read()
            if contents:
                respond("Here is the recorded speech:\n" + contents)
            else:
                respond("The recorded speech file is empty.")
    except FileNotFoundError:
        respond("The recorded speech file is not found.")


def record_speech():
    respond("Recording: ")
    recognizer = sr.Recognizer()

    with sr.Microphone() as source:
        print("Recording...")
        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

    try:
        recorded_text = recognizer.recognize_google(audio)
        timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        with open("recorded_speech.txt", "a") as file:
            file.write(f"{timestamp}: {recorded_text}\n")

        print("Recording complete.")
        respond("Recording complete")
        return recorded_text
    except sr.UnknownValueError:
        print("Could not understand audio. Please try again.")
        return None
    except sr.RequestError:
        print("Unable to access the Google Speech Recognition API.")
        return None


def main():
    global tasks
    global listening_to_task

    respond("Hello, this is Hal, this vessel's AI.")

    while True:
        command = listen_for_command()

        trigger_keyword = "Hal"

        if command and trigger_keyword in command:
            if listening_to_task:
                tasks.append(command)
                listening_to_task = False
                respond("Adding " + command + " to your task list. You have " + str(len(tasks)) + " currently in your list.")
            elif "add a task" in command:
                listening_to_task = True
                respond("Sure, what is the task?")
            elif "list tasks" in command:
                respond("Sure. Your tasks are:")
                for task in tasks:
                    respond(task)
            elif "take a screenshot" in command:
                pyautogui.screenshot("screenshot.png")
                respond("I took a screenshot for you.")
            elif "open chrome" in command:
                respond("Opening Chrome.")
                webbrowser.open("http://www.youtube.com/")
            elif "record" in command:
                record_speech()
            elif "question" in command:
                recorded_text = record_speech()
                bard_response = prompt_bard(recorded_text)
                respond(bard_response)
            elif "read notes" in command:
                read_recorded_speech()
            elif "motivation" in command:                
                respond("It is not death that a man should fear, but he should fear never beginning to live.")
            elif "exit" in command:
                respond("Goodbye!")
                break
            else:
                respond("Sorry, I'm not sure how to handle that command.")


if __name__ == "__main__":
    main()
