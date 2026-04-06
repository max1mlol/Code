def pairwise_div(Lnum, Ldenom):
    """Lnum болон Ldenom нь тоо агуулсан, ижил урттай,
        хоосон биш жагсаалт
    Хоёр жагсаалтыг харгалзах элемент бүрээр хувааж, хариуг
    агуулсан шинэ жагсаалт буцаана (Lnum/Ldenom).
    Хэрэв Ldenom жагсаалт 0 утга агуулсан эсвэл ямар нэг байдлаар
    хуваахад асуудал гарсан тохиолдолд ValueError алдаа үүсгэ."""
    # Энд кодоо бичнэ үү...
    assert isinstance(Lnum, list) and isinstance(Ldenom, list), "Jagsaalt baih ystoi"
    assert len(Lnum) > 0 and len(Ldenom) > 0, "Jagsaalt hooson baij bolohgui"
    assert len(Lnum) == len(Ldenom), "Jagsaaltuudiin urt ijil baih ystoi"

    result = []

    for num, denom in zip(Lnum, Ldenom):
        try:
            if denom == 0:
                raise ValueError("0-r toog huvaaj bolohgui")
            result.append(num / denom)

        except Exception:
            raise ValueError("Huvaahad aldaa garla")
    
    return result

L1 = [5, 10, 15, 20]
L2 = [1, 3, 4, 2]
print(pairwise_div(L1, L2))  # prints [5.0, 3.3333, 3.75, 10]

L1 = [5, 10, 15, 20]
L2 = [5, 4, 3]
print(pairwise_div(L1, L2))  # raises AssertionError

L1 = []
L2 = [5, 4, 3, 2]
print(pairwise_div([], [5, 4, 3, 2]))  # raises AssertionError

L1 = [5, 10, 15, 20]
L2 = [1, 3, 0, 2]
print(pairwise_div(L1, L2))  # raises ValueError

