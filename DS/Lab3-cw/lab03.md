# Дасгал 3

МУИС-ийн нээлттэй өгөгдөл [https://data.num.edu.mn/dataset](https://data.num.edu.mn/dataset) хаяг дээр байрладаг бөгөөд энэхүү дасгалаар [LiveData NUM](https://datascientiafoundation.github.io/LiveDataNUM/datasets/) өгөгдлийн багцийг Python хэлний дасгал ажилдаа ашиглана.

**Даалгавар:**

1. LiveData NUM-аас хичээлийн хуваарь агуулсан json хэлбэрийн өгөгдлийг татаж авсан (`schedule.json` - [source](https://sisi.num.edu.mn/digital_num/api/package/hicheeliin-huvaari)). Энэхүү файлыг энгийн текст засварлагч программаар нээж, үзэж болно.
2. Python кодоор json хэлбэрийн текстийг уншина (`open`).
3. Уншсан json текстээ Python хэлний dictionary болгож хувиргана (`json.load`).
4. Уншсан өгөгдөл дээрээ шинжилгээ хийх. Үүнд нэг багш хэдэн ялгаатай хичээл, тус бүр хэдэн удаа орж байна, хамгийн их эсвэл бага ачаалалтай анги танхим, хамгийн их хичээл ордог долоо хоногийн өдөр гэх мэт байж болно.

## Хэрэгтэй кодын хэсгүүд

**`schedule.json` файлын бүтэц нь дараах хэлбэртэй:**

```json
[
  {
    "khuvaariin_dugaar": "402d7675d21511963510dd0121823da3",
    "khicheeliin_dugaar": "5e3ade25abcb8f3aa9c00f07a2a68590",
    "khicheeliin_jil": "2025-2026",
    "uliral": "Намрын улирал",
    "zaasan_bagshiin_ner": "О.Билгүүн",
    "bagshiin_khuviin_dugaar": "f36d8902-1d57-43f8-b422-e2d982ed36f8",
    "khicheeliin_ner": "Мэдээллийн аюулгүй байдал",
    "bagts_tsag": 3.0,
    "khicheeliin_khelber": "Лаборатори",
    "garag": "Баасан",
    "ekhlekh_tsag": "15:05",
    "duusakh_tsag": "17:30",
    "oroltyn_too": 16,
    "davtamj": "7 хоног тутам",
    "ekhlekh_ognoo": "2025-09-05T15:05:00",
    "batalgaajuulsan_suraltsagchiin_too": 53,
    "uruunii_khuviin_dugaar": "0fcbc61acd0479dc77e3cccc0f5ffca7",
    "khicheellekh_bair": "Хичээлийн байр 8",
    "uruunii_dugaar": "405",
    "uruunii_ner": "Компьютерийн лаборатори ",
    "bolomjit_suudal": 27,
    "khicheeliin_tenkhimiin_dugaar": "71c9fc47d49e39f870df6cd4b4114ede",
    "khicheeliin_surguuliin_dugaar": "96b1402f186af59414e2c686d8672908"
  }
]
```

- `*_dugaar` талбарууд нь тухайн объектын дугаар буюу ID-г илэрхийлнэ.

**Файл унших, json-ыг Python dictionary болгох кодын жишээ:**

```python
import json

# JSON файлыг унших
with open("schedule.json", "r") as file:
    # JSON файлыг Python dictionary болгож хувиргах
    data = json.load(file)


# Жишээ: Багш бүрийн хичээлийн тоог тоолох, заавал ийм байх албагүй, өөр шинжилгээ хийж болно.
teacher_course_count = {}
for entry in data:
    # Энэ жишээ давталтын их биеийг өөрчилж дасгалаа хийнэ.
    entry # нь schedule.json дахь нэг объектыг илэрхийлнэ
    entry["zaasan_bagshiin_ner"] # нь тухайн объектыг заасан багшийн нэрийг илэрхийлнэ
    entry["bagshiin_khuviin_dugaar"] # нь тухайн объектыг заасан багшийн id-г илэрхийлнэ

print(teacher_course_count)
```
