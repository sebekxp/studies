def left(str, len):
    new = str.ljust(len)
    print(new)


def right(str, len):
    new = str.rjust(len)
    print(new)


def center(str, len):
    new = str.center(len)
    print(new)


if __name__ == "__main__":
    left('Moduł "text" definiuje funkcje center, left, right i słuzy do :', 80)
    left("Wypisania tekstu wyrównanego do lewej,", 80)
    right("do prawej", 80)
    center("lub wyrownanego.", 80)
    print(dir(__name__))
