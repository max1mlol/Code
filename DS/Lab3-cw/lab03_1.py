import json
# Багш бүрийн заадаг хичээлийг тоолох
# JSON файлаас мэдээлэл авах
with open("schedule.json", "r", encoding='utf-8') as file:
    data = json.load(file)

# Багш нарыг тоолоход хэрэглэх хоосон dictionary
teacher_course_count = {}

# Өгөгдөлд хадгалагдсан entry бүрийг шалгах
for entry in data:
    teacher_name = entry["zaasan_bagshiin_ner"]
    
    if teacher_name in teacher_course_count:
        teacher_course_count[teacher_name] = teacher_course_count[teacher_name] + 1
    else:
        teacher_course_count[teacher_name] = 1

print("Teacher class counts:")
for teacher, count in teacher_course_count.items():
    print(f"{teacher}: {count} class(es)")