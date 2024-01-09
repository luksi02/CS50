import speech_recognition as sr
import pyttsx3
import pyautogui
import webbrowser
import datetime

tasks = []
listening_to_task = False

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
    engine.say(response_text)
    engine.runAndWait()

def record_speech():
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
    except sr.UnknownValueError:
        print("Could not understand audio. Please try again.")
    except sr.RequestError:
        print("Unable to access the Google Speech Recognition API.")

def main():
    global tasks
    global listening_to_task

    respond("Hello, Luke. I hope you're having a nice day today.")

    while True:
        command = listen_for_command()

        trigger_keyword = "engine"

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
            elif "motivation" in command:                
                respond("It is not death that a man should fear, but he should fear never beginning to live.")
            elif "exit" in command:
                respond("Goodbye!")
                break
            else:
                respond("Sorry, I'm not sure how to handle that command.")

if __name__ == "__main__":
    main()
