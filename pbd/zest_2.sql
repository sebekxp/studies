-- 1. Oblicz na ile dni upłynęło od wpisania ostatniej oceny (użyj funkcji sysdate). Wyświetl kto ją
-- wpisał i z jakiego przedmiotu.
SELECT W.IMIE, W.NAZWISKO, ROUND(SYSDATE - O.DATA) AS "UPLYNELO DNI", P.NAZWA
FROM ZAJECIA
         JOIN WYKLADOWCA W ON ZAJECIA.ID_WYKLADOWCA = W.ID_WYKLADOWCA
         JOIN OCENA O ON ZAJECIA.ID_ZAJECIA = O.ID_ZAJECIA
         JOIN PRZEDMIOT P on ZAJECIA.ID_PRZEDMIOT = P.ID_PRZEDMIOT
WHERE O.DATA = (SELECT MIN(OCENA.DATA) FROM OCENA);

-- 2. Wyświetl dane wykładowców (imię, nazwisko, tytuł naukowy), którzy w ciągu ostatnich 12
-- miesięcy wpisywali oceny. Kolumnie nadaj nazwę DANE.
SELECT DISTINCT (W.IMIE || ' ' || W.NAZWISKO || ' ' || T.NAZWA) AS DANE
FROM ZAJECIA
         JOIN WYKLADOWCA W on ZAJECIA.ID_WYKLADOWCA = W.ID_WYKLADOWCA
         JOIN OCENA O on ZAJECIA.ID_ZAJECIA = O.ID_ZAJECIA
         JOIN TYTULNAUKOWY T on W.ID_TYTUL = T.ID_TYTUL
WHERE MONTHS_BETWEEN(SYSDATE, O.DATA) < 30;

-- 3.Wyświetl minimalna, średnią oraz maksymalną ocenę. Nazwy kolumn wynikowych mają być
-- odpowiednio: MINIMALNA OCENA, ŚREDNIA Z OCEN, MAKSYMALNA OCENA.
SELECT MIN(OCENA)           AS "MINIMALNA OCENA",
       ROUND(AVG(OCENA), 2) AS "SREDNIA Z OCEN",
       MAX(OCENA)           AS "MAKSYMALNA OCENA"
FROM OCENA;

-- 4.Wyświetl nazwy przedmiotów oraz wszystkie dane prowadzącego, który wpisał ocenę mającą
-- najstarszą datę.
SELECT PRZEDMIOT.NAZWA,
       WYKLADOWCA.NAZWISKO,
       WYKLADOWCA.IMIE,
       ADRES.ULICA,
       ADRES.NRBUDYNKU,
       ADRES.NRLOKALU,
       ADRES.MIASTO,
       ADRES.KODPOCZTOWY,
       TYTULNAUKOWY.NAZWA
FROM ZAJECIA
         JOIN PRZEDMIOT ON ZAJECIA.ID_PRZEDMIOT = PRZEDMIOT.ID_PRZEDMIOT
         JOIN WYKLADOWCA ON ZAJECIA.ID_WYKLADOWCA = WYKLADOWCA.ID_WYKLADOWCA
         JOIN ADRES ON WYKLADOWCA.ID_ADRES = ADRES.ID_ADRES
         JOIN TYTULNAUKOWY on WYKLADOWCA.ID_TYTUL = TYTULNAUKOWY.ID_TYTUL
WHERE ZAJECIA.ID_WYKLADOWCA = (
    SELECT WYKLADOWCA.ID_WYKLADOWCA
    FROM OCENA
             JOIN ZAJECIA ON ZAJECIA.ID_ZAJECIA = OCENA.ID_ZAJECIA
             JOIN WYKLADOWCA ON ZAJECIA.ID_WYKLADOWCA = WYKLADOWCA.ID_WYKLADOWCA
    WHERE OCENA.DATA = (SELECT MIN(OCENA.DATA) FROM OCENA)
);

-- 5. Wyświetl studenta /ów (imię, nazwisko, nr albumu), który ma najwięcej ocen.
SELECT STUDENT.IMIE, STUDENT.NAZWISKO, STUDENT.NRALBUMU, COUNT(*) AS "LICZBA OCEN"
FROM STUDENT
         JOIN OCENA ON STUDENT.ID_STUDENT = OCENA.ID_STUDENT
GROUP BY STUDENT.IMIE, STUDENT.NAZWISKO, STUDENT.NRALBUMU
HAVING COUNT(OCENA.ID_STUDENT) = (SELECT MAX(COUNT(OCENA.ID_STUDENT))
                                  FROM OCENA
                                  GROUP BY OCENA.ID_STUDENT);

-- 6. Wyświetl liczbę studentów w każdej grupie studenckiej na kierunku informatyka
SELECT GRUPA.NAZWA, COUNT(STUDENT.ID_GRUPA) AS "LICZBA STUDENTOW"
FROM STUDENT
         JOIN GRUPA ON STUDENT.ID_GRUPA = GRUPA.ID_GRUPA
WHERE GRUPA.ID_KIERUNEK = (SELECT KIERUNEK.ID_KIERUNEK FROM KIERUNEK WHERE KIERUNEK.NAZWA = 'Informatyka')
GROUP BY GRUPA.NAZWA, STUDENT.ID_GRUPA;

-- 7. Wyświetl daty trzech najbliższych poniedziałków, przypadających po ostatniej ocenie
-- wpisanej do bazy.
SELECT NEXT_DAY((SELECT MAX(OCENA.DATA) FROM OCENA), 2)                               AS "PON1",
       NEXT_DAY((NEXT_DAY((SELECT MAX(OCENA.DATA) FROM OCENA), 2)), 2)                AS "PON2",
       NEXT_DAY((NEXT_DAY((NEXT_DAY((SELECT MAX(OCENA.DATA) FROM OCENA), 2)), 2)), 2) AS "PON3"
FROM DUAL;
-- 7. WARIANT 2
SELECT NEXT_DAY(MAX(O.DATA), 2)                               AS "PON1",
       NEXT_DAY((NEXT_DAY(MAX(O.DATA), 2)), 2)                AS "PON2",
       NEXT_DAY((NEXT_DAY((NEXT_DAY(MAX(O.DATA), 2)), 2)), 2) AS "PON3"
FROM DUAL,
     OCENA O;
-- 8. Wyświetl nazwiska i imiona (pierwsze dwie kolumny) wykładowców oraz informację czy
-- prowadzą oni przedmiot. Jeżeli dany wykładowca ma w nazwisku ‘sk’, informacja (w trzeciej
-- kolumnie) brzmi: „BRAK PRZEDMIOTU”. W przeciwnym razie „PROWADZI PRZEDMIOT”
SELECT WYKLADOWCA.NAZWISKO,
       WYKLADOWCA.IMIE,
       CASE
           WHEN WYKLADOWCA.NAZWISKO LIKE '%sk%' THEN 'BRAK PRZEDMIOTOW'
           ELSE 'PROWADZI PRZEDMIOT'
           END AS "PROWADZI CZY NIE ?"
FROM WYKLADOWCA;

-- 9. Wyświetl dane na temat budynku, w którym odbywa się najwięcej zajęć.
SELECT NAZWA, "ILOSC ZAJEC"
FROM (
         SELECT BUDYNEK.NAZWA, COUNT(BUDYNEK.ID_BUDYNEK) "ILOSC ZAJEC"
         FROM ZAJECIA
                  JOIN SALA ON ZAJECIA.ID_SALA = SALA.ID_SALA
                  JOIN BUDYNEK ON SALA.ID_BUDYNEK = BUDYNEK.ID_BUDYNEK
         GROUP BY BUDYNEK.NAZWA
         ORDER BY COUNT(BUDYNEK.ID_BUDYNEK) DESC)
WHERE ROWNUM <= 1;
-- 9 WARIANT 2
SELECT B.NAZWA, COUNT(B.ID_BUDYNEK) AS "ILOSC ZAJEC"
FROM ZAJECIA
         JOIN SALA S on ZAJECIA.ID_SALA = S.ID_SALA
         JOIN BUDYNEK B on S.ID_BUDYNEK = B.ID_BUDYNEK
HAVING COUNT(ZAJECIA.ID_SALA) = (SELECT MAX(COUNT(S2.ID_BUDYNEK))
                                 FROM ZAJECIA
                                          JOIN SALA S2 on ZAJECIA.ID_SALA = S2.ID_SALA
                                 GROUP BY S2.ID_BUDYNEK)

-- 10. Wyświetl nazwę przedmiotu (ów), które mają największą liczbę pkt. ECTS.
SELECT PRZEDMIOT.NAZWA, PRZEDMIOT.ECTS
FROM PRZEDMIOT
WHERE PRZEDMIOT.ECTS = (SELECT MAX(PRZEDMIOT.ECTS) FROM PRZEDMIOT);

-- 11. Wyświetl dane o studentach, którzy studiują na kierunku, na którym jest najmniejsza liczba
-- studentów.
SELECT STUDENT.IMIE, STUDENT.NAZWISKO, STUDENT.NRALBUMU
FROM STUDENT
         JOIN GRUPA ON STUDENT.ID_GRUPA = GRUPA.ID_GRUPA
WHERE GRUPA.ID_KIERUNEK = (
    SELECT KIERUNEK.ID_KIERUNEK
    FROM STUDENT
             JOIN GRUPA ON STUDENT.ID_GRUPA = GRUPA.ID_GRUPA
             JOIN KIERUNEK ON GRUPA.ID_KIERUNEK = KIERUNEK.ID_KIERUNEK
    GROUP BY KIERUNEK.ID_KIERUNEK
    ORDER BY COUNT(KIERUNEK.ID_KIERUNEK)
    FETCH FIRST ROW ONLY
);

-- 12. Wyświetl nazwę grupy, która ma zajęcia w budynkach „Wydział Inżynierii Elektrycznej i
-- Komputerowej” i „Wydział Inżynierii i Technologii Chemicznej”.
SELECT DISTINCT GRUPA.NAZWA
FROM ZAJECIA
         JOIN SALA ON ZAJECIA.ID_SALA = SALA.ID_SALA
         JOIN BUDYNEK ON SALA.ID_BUDYNEK = BUDYNEK.ID_BUDYNEK
         JOIN GRUPA ON GRUPA.ID_GRUPA = ZAJECIA.ID_GRUPA
WHERE BUDYNEK.NAZWA IN ('„Wydział Inżynierii Elektrycznej i
-- Komputerowej', 'Wydział Inżynierii i Technologii Chemicznej');

-- 13. Wyświetl salę oraz charakter przedmiotu, który jest wykładany przez tego wykładowcę, który
-- ma zajęcia we wtorek
SELECT SALA.KODSALI, P.NAZWA, CHARAKTER.NAZWA, WYKLADOWCA.IMIE, WYKLADOWCA.NAZWISKO
FROM ZAJECIA
         JOIN CHARAKTER ON ZAJECIA.ID_CHARAKTER = CHARAKTER.ID_CHARAKTER
         JOIN SALA ON ZAJECIA.ID_SALA = SALA.ID_SALA
         JOIN WYKLADOWCA ON ZAJECIA.ID_WYKLADOWCA = WYKLADOWCA.ID_WYKLADOWCA
         JOIN PRZEDMIOT P on ZAJECIA.ID_PRZEDMIOT = P.ID_PRZEDMIOT
WHERE ZAJECIA.DZIENTYG = 'WTO';

-- 14. Wyświetl numer grupy, z której pochodzą studenci, którzy mają zajęcia prowadzone przez
-- prof. dr. hab. inż.
SELECT DISTINCT ID_GRUPA
FROM ZAJECIA
         JOIN WYKLADOWCA W on ZAJECIA.ID_WYKLADOWCA = W.ID_WYKLADOWCA
         JOIN TYTULNAUKOWY T on W.ID_TYTUL = T.ID_TYTUL
WHERE T.NAZWA LIKE 'Prof. dr hab. inż.';
