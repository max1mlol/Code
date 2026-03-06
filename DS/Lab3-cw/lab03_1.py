import json

# Read the JSON file
with open("schedule.json", "r", encoding='utf-8') as file:
    data = json.load(file)

# Create an empty dictionary to store teacher counts
teacher_course_count = {}

# Loop through each entry in the data
for entry in data:
    # Get the teacher's name from the current entry
    teacher_name = entry["zaasan_bagshiin_ner"]
    
    # If this teacher is already in our dictionary, increment their count
    if teacher_name in teacher_course_count:
        teacher_course_count[teacher_name] = teacher_course_count[teacher_name] + 1
    # If this teacher is not in our dictionary yet, add them with count 1
    else:
        teacher_course_count[teacher_name] = 1

# Print the result
print("Teacher class counts:")
for teacher, count in teacher_course_count.items():
    print(f"{teacher}: {count} class(es)")