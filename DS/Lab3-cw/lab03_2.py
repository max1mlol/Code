import json
from datetime import time
# Яг одоо сул байгаа ангийг олох
# JSON файлаас мэдээлэл авах
with open(".\DS\Lab3-cw\schedule.json", "r", encoding='utf-8') as file:
    data = json.load(file)

# Багш нарыг тоолоход хэрэглэх хоосон dictionary
empty_room_count = {}
def time_to_min(time):
    hr, min = map(int, time.split(':'))
    return hr*60+min
time_hr = int(input("What is the hour of the time right now: "))
time_min = int(input("What is the minute of the time right now: "))
time_right_now = datetime.now().strftime("%H:%M")
# Өгөгдөлд хадгалагдсан entry бүрийг шалгах
for entry in data:
    room = entry["uruunii_dugaar"]
    bair = entry["khicheellekh_bair"]
    jil = entry["khicheeliin_jil"]
    start = entry["ekhlekh_tsag"]
    end = entry["duusakh_tsag"]
    if time_to_min(start) < time_to_min(time_right_now) and time_to_min(end) > time_to_min(time_right_now) and jil == "2025-2026" and term == "Намрын улирал" and bair == "Хичээлийн байр 8":
        print("This room is not empty")   
    else:
        print("This room is empty")

