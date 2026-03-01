students = {
    "S001": ("Бат", 20, "Компьютерын ухаан"),
    "S002": ("Болд", 21, "Программ хангамж")
}
def add_student(student_id, name, age, major):
    # Оюутны мэдээллийг нэмэх
    students[student_id]=(name, age, major)

def find_student_by_id(student_id):
    # Оюутны мэдээллийг ID-аар хайх
    if student_id in students:
        student = students[student_id]
        print(f"Student Found: {student}")
        return student
    else:
        print("Student not found")

def list_students_by_major(major):
    # Тодорхой хөтөлбөрийн бүх оюутнуудыг жагсаах
    major_students = []
    for  student_id, student_info in students.items():
        name, age, student_major = student_info
        if student_major == major:
            major_students.append(student_info)
    if major_students:
        print(f"'{major} ' major students")
        for student in major_students:
            print(f" {student}")
    else:
        print(f"'{major}' major doesn't have students")
    return major_students
    
def count_students():
    # Нийт оюутны тоог тоолох
    count = len(students)
    print(f"Number of students: {count}")
    return count

add_student("S003", "Уянга", 22, "Компьютерын ухаан")
find_student_by_id("S002") # Гаралт: ("Болд", 21, "Программ хангамж")
list_students_by_major("Компьютерын ухаан") # Гаралт: [("Бат", 20, "Компьютерын ухаан), ("Уянга", 22, "Компьютерын ухаан")]
count_students() # Гаралт: 3

