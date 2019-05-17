from Pakiet import text
from math import sqrt


def selected_language(choice, choice_txt):
    if choice_txt == "pl":
        txt = "Pierwiastek wynosi: "
    else:
        txt = "The root is equal: "
    text.center(choice.lang['hello'], 50)
    sqr = int(input(choice.lang['info']))
    if sqr < 0:
        text.center(choice.lang['error'], 50)
    else:
        text.center(f"{txt}{sqrt(sqr)}", 50)
        text.center(choice.lang['bye'], 50)


choose_lang = input("Choose lang [pl/en]")

if choose_lang == "pl":
    from Słownik import pl
    selected_language(pl, choose_lang)
else:
    from Słownik import en
    selected_language(en, choose_lang)
