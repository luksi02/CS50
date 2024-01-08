import speech_recognition as sr
import pyttsx3

def continuous_speech_recognition():
    recognizer = sr.Recognizer()
    engine = pyttsx3.init()

    with sr.Microphone() as source:
        print("Listening...")

        while True:
            recognizer.adjust_for_ambient_noise(source, duration=2)
            audio = recognizer.listen(source)

            try:
                recognized_text = recognizer.recognize_google(audio)
                print(f"You said: {recognized_text}")

                # Use pyttsx3 to speak back the recognized text
                engine.say(f"You said: {recognized_text}")
                engine.runAndWait()

            except sr.UnknownValueError:
                print("Could not understand audio. Please try again.")
            except sr.RequestError as e:
                print(f"Error accessing speech recognition service; {e}")

if __name__ == "__main__":
    continuous_speech_recognition()
