# 1. Өгүүлбэр оруулах
sentence =  "the cat and the dog and the bird"

# 2. Үг бүр хэдэн удаа давтагдсаныг тоолох
words = sentence.split()
word_count = {}
for i in words:
    i = i.lower()
    if i in word_count:
        word_count[i] += 1
    else:
        word_count[i] = 1

# 3. Үр дүнг dictionary-д хадгалах



# 4. Нэгээс олон удаа гарсан үгсийг хэвлэх
print("Duplicate words: ")
for i, count in word_count.items():
    if count > 1:
        print(f"{i}: {count}")
