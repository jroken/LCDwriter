from time import sleep
import speech_recognition as sr
from serial import Serial as sericaykardsm
r = sr.Recognizer()

cau = sericaykardsm("COM5",9600)
sleep(2)

def writer(caycininsözü):
    cau.write(caycininsözü.encode())


while True:
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Lütfen Konuşun:" + str(r.energy_threshold))
        ses = r.listen(source, timeout=10, phrase_time_limit=10)
        print(r.recognize_google(ses, language='tr-tr'))
        text = r.recognize_google(ses, language='tr-tr')
        writer(text)