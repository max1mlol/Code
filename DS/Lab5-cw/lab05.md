# Дасгал 5

Энэхүү дасгалаар өгөдлийг хүснэгтэн хэлбэрт оруулж, статистик шинжилгээ хийх болон өгөгдлийг хувиргах чадварыг эзэмшинэ.

Дасгалын хүрээнд pandas сан хэрэглэх бөгөөд түүний DataFrame өгөгдлийн төрөлтэй ажиллана. Та дараах холбоосоор дамжуулан pandas сангийн гарын авлагатай танилцах боломжтой:

- [Pandas Documentation](https://pandas.pydata.org/docs/)
- [10 minutes to pandas](https://pandas.pydata.org/pandas-docs/stable/user_guide/10min.html)
- [Pandas Cheat Sheet](https://pandas.pydata.org/Pandas_Cheat_Sheet.pdf)

Сан хэрэглэхдээ python файлынхаа дээд хэсэгт дараах мөрийг оруулна уу:

```python
import pandas as pd
```

::: warning Өгөгдөл

Даалгаварт шаардлагатай өгөгдлийг эндээс татаж авна уу.

[**`student_data.csv` :floppy_disk:**](/numdocs/assets/icsi250/lab05/student_data.csv){target="_self", download="student_data.csv"}

:::

## Өгөгдөл унших

CSV хэлбэрийн файлаас өгөгдөл унших:

```python
# CSV файл унших
data = pd.read_csv('student_data.csv')
```

Өгөгдлийг шинжих:

```python
# Өгөгдлийн эхний 5 мөрийг харах
print(data.head())
# Бүх баганын нэрсийг харах
print(data.columns)
```

## Гүйцэтгэх дасгал

1. Pandas сан ашиглан өгөгдлийг уншиж, эхний 5 мөрийг хэвлэнэ үү.
2. Оюутны дүнд статистик шинжилгээ хийх: дундаж, медиан, стандарт хазайлт, min, max утгуудыг тооцоолно уу.
3. Оюутны дүнгийн баганын утгуудыг үсгэн тэмдэглэгээнд (`A`, `B`, `C`, `D`, `F`) хувиргаж, `grade_letter` багана үүсгэн хадгал. (90-100 = A, 80-89 = B, 70-79 = C, 60-69 = D, 0-59 = F).
4. Дунджаас дээш дүнтэй оюутнуудыг `above_average` баганаар тэмдэглэ. (Дундажаас дээш дүнтэй оюутнуудын `above_average` баганын утга нь `True`, бусад нь `False` болно).
5. Дүнгийн утгуудыг `0-1` хооронд нормалчлах.
   
   Хамгийн багыг 0, хамгийн ихийг 1 болгон нормалчлах томъёо:
   
   $\text{normalized\_grade} = \frac{\text{grade} - \min(\text{grade})}{\max(\text{grade}) - \min(\text{grade})}$
