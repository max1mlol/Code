students = {
    "S001": ("Бат", 20, "Компьютерын ухаан"),
    "S002": ("Болд", 21, "Программ хангамж")
}
def add_student(student_id, name, age, major):
    # Оюутны мэдээллийг нэмэх
    students[student_id]={
    "name" : name,
    "age" : age,
    "major" : major
    }


add_student("S003", "uyanga", 22, "CS")
# print(students)
def find_student_by_id(student_id):
    # Оюутны мэдээллийг ID-аар хайх
    return students.get(student_id)
id = input("Enter student id: ")
if student_id in students:


# def list_students_by_major(major):
#     # Тодорхой хөтөлбөрийн бүх оюутнуудыг жагсаах

# def count_students():
#     # Нийт оюутны тоог тоолох
#     return len(students)
