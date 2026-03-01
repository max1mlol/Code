import numpy as np
scores = [85, 92, 78, 90, 88]
sum = 0
for i in range(1, len(scores)):
    sum += scores[i]
avg = sum / (len(scores)-1)
print(f"Dundaj: ", avg)
if avg>=90:
    print("A")
elif avg >= 80:
    print("B")
elif avg >= 70:
    print("C")
elif avg >= 60:
    print("D")
else:
    print("F")