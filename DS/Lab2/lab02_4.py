# 1. 7 хоногийн өдөр тутмын температурыг жагсаалтад хадгалах
temps = [72, 68, 75, 70, 73, 69, 71]

# 2. Хамгийн өндөр болон хамгийн бага температурыг олох
print(f"The max value is {min(temps)}")
print(f"The min value is {max(temps)}")
# 3. Дундаж температурыг тооцоолох
if len(temps) == 0:
    print("No temperatures entered")
else:
    avg = round(sum(temps)/len(temps), 2)
    print(f"The average value is {avg}")
# 4. Дундажаас дээш температуртай өдрүүдийн тоог тоолох
print("Higher than average numbers:")
for i in range(0,len(temps)):
    if temps[i] > avg:
        print(f"{temps[i]}")