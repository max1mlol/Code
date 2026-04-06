def sum_str_lengths(L):
    """
    L нь хоосон биш жагсаалт бөгөөд дараах өгөгдлийн төрлүүдийг агуулна:
    * тэмдэгт мөрүүд эсвэл
    * тэмдэгт мөр агуулсан хоосон биш дэд жагсаалт
    L жагсаалт доторх бүх тэмдэгт мөр, мөн дэд жагсаалт байвал
    түүн доторх тэмдэгт мөр бүрийн уртыг олж,
    нийлбэрийг буцаана. Хэрэв L жагсаалтад тэмдэгт мөрөөс
    өөр төрөлтэй өгөгдөл олдох юм бол ValueError алдаа үүсгэнэ үү.
    """
    # Энд кодоо бичнэ үү...
    assert isinstance(L, list), "Jagsaalt baih ystoi"
    assert len(L) > 0, "Jagsaalt hooson baij bolohgui"

    total = 0

    for item in L:
        if isinstance(item, str):
            total += len(item)
        elif isinstance(item, list):
            if len(item) == 0:
                raise ValueError("Ded jagsaalt hooson baij bolohgui")
            for sub in item:
                if isinstance(sub, str):
                    total += len(sub)
                else:
                    raise ValueError("Ded jagsaalt zuvhun string baih ystoi")
        else:
            raise ValueError("Zuvhun string esvel string aguulsan jagsaalt baih ystoi")
    return total

print(sum_str_lengths(["abcd", ["e", "fg"]]))  # prints 7
print(sum_str_lengths([12, ["e", "fg"]]))  # raises ValueError
print(sum_str_lengths(["abcd", [3, "fg"]]))  # raises ValueError

