-- 1. Wyświetl nazwę miasta/miast, z którego pochodzi najmniejsza liczba studentów na kierunku
-- matematyka.
SELECT ADRES.MIASTO
FROM STUDENT
         JOIN GRUPA ON STUDENT.ID_GRUPA = GRUPA.ID_GRUPA
         JOIN ADRES ON STUDENT.ID_ADRES = ADRES.ID_ADRES
WHERE GRUPA.ID_KIERUNEK = (SELECT KIERUNEK.ID_KIERUNEK FROM KIERUNEK WHERE KIERUNEK.NAZWA = 'Matematyka')
GROUP BY ADRES.MIASTO
HAVING COUNT(GRUPA.ID_KIERUNEK) = (SELECT MIN(COUNT(KIERUNEK.ID_KIERUNEK))
                                   FROM KIERUNEK
                                   GROUP BY KIERUNEK.ID_KIERUNEK);

-- 2. Wyświetl nazwiska prowadzących, którzy są doktorami i uczą Analizy Danych.
SELECT DISTINCT W.NAZWISKO
FROM ZAJECIA
         JOIN WYKLADOWCA W on ZAJECIA.ID_WYKLADOWCA = W.ID_WYKLADOWCA
         JOIN PRZEDMIOT P ON ZAJECIA.ID_PRZEDMIOT = P.ID_PRZEDMIOT
         JOIN TYTULNAUKOWY T on W.ID_TYTUL = T.ID_TYTUL
WHERE T.NAZWA LIKE 'dr'
  AND P.NAZWA = 'Analiza Danych';

-- 3. Wyświetl dane prowadzącego oraz tytuł naukowy, dla tych osób, które mają najwięcej
-- wykładów
SELECT W.IMIE, W.NAZWISKO, T.NAZWA, COUNT(W.NAZWISKO) AS "LICZBA WYKLADOW"
FROM ZAJECIA
         JOIN WYKLADOWCA W on ZAJECIA.ID_WYKLADOWCA = W.ID_WYKLADOWCA
         JOIN TYTULNAUKOWY T on W.ID_TYTUL = T.ID_TYTUL
         JOIN CHARAKTER CH on ZAJECIA.ID_CHARAKTER = CH.ID_CHARAKTER
WHERE CH.NAZWA = 'Wykłady'
HAVING COUNT(W.NAZWISKO) =
       (SELECT MAX(COUNT(W.NAZWISKO))
        FROM WYKLADOWCA W
                 JOIN ZAJECIA on W.ID_WYKLADOWCA = ZAJECIA.ID_WYKLADOWCA
                 JOIN TYTULNAUKOWY T on W.ID_TYTUL = T.ID_TYTUL
                 JOIN CHARAKTER CH on ZAJECIA.ID_CHARAKTER = CH.ID_CHARAKTER
        WHERE CH.NAZWA = 'Wykłady'
        GROUP BY W.NAZWISKO)
GROUP BY W.IMIE, W.NAZWISKO, T.NAZWA;

-- 4. Wyświetl dane o studentach, którzy dostali stypendium na najkrótszy okres czasu.
SELECT S.NAZWISKO, S.IMIE, S.NRALBUMU, G.NAZWA, A.MIASTO, A.ULICA
FROM STUDENT S
         JOIN ADRES A on S.ID_ADRES = A.ID_ADRES
         JOIN STYPENDIUM ST on S.ID_STUDENT = ST.ID_STUDENT
         JOIN GRUPA G ON S.ID_GRUPA = G.ID_GRUPA
WHERE ST.DATA_ZAK - ST.DATA_PRZYZ = (SELECT MIN(ST.DATA_ZAK - ST.DATA_PRZYZ) FROM STYPENDIUM ST);

-- 5. Wyświetl ile średnio ocen z przedmiotu otrzymuje grupa ‘GRUPA 21’.

-- 6. Wyświetl dane (imię i nazwisko) prowadzących, którzy nie mają zajęć w poniedziałek
-- -- i czwartek w salach zaczynających się na literę K.
SELECT DISTINCT W.IMIE, W.NAZWISKO
FROM ZAJECIA
         JOIN WYKLADOWCA W on ZAJECIA.ID_WYKLADOWCA = W.ID_WYKLADOWCA
         JOIN SALA S on ZAJECIA.ID_SALA = S.ID_SALA
WHERE DZIENTYG NOT IN ('PON', 'CZW')
  AND S.KODSALI LIKE 'K%';

-- 7. Wyświetl jakie zajęcia (charakter) odbywają się w budynku Wydziału Inżynierii i Technologii
-- Chemicznej.
SELECT DISTINCT CH.NAZWA
FROM ZAJECIA
         JOIN CHARAKTER CH on ZAJECIA.ID_CHARAKTER = CH.ID_CHARAKTER
         JOIN SALA S on ZAJECIA.ID_SALA = S.ID_SALA
         JOIN BUDYNEK B on S.ID_BUDYNEK = B.ID_BUDYNEK
WHERE B.NAZWA LIKE 'Wydział Inżynierii i Technologii Chemicznej';

-- 8. Kto prowadzi seminaria (dane osobowe+ tytuł naukowy+ kierunek). Dane wyświetl wg. wzoru:
-- ********Adam Mickiewicz********prof. dr hab. ********Matematyka********
SELECT DISTINCT ('********' || W.IMIE || ' ' || W.NAZWISKO || ' ' || T.NAZWA || '********' || K.NAZWA ||
                 '********') AS "KTO PROWADZI SEMINARIA"
FROM ZAJECIA
         JOIN WYKLADOWCA W on ZAJECIA.ID_WYKLADOWCA = W.ID_WYKLADOWCA
         JOIN TYTULNAUKOWY T on W.ID_TYTUL = T.ID_TYTUL
         JOIN GRUPA G on ZAJECIA.ID_GRUPA = G.ID_GRUPA
         JOIN KIERUNEK K on G.ID_KIERUNEK = K.ID_KIERUNEK
         JOIN CHARAKTER C2 on ZAJECIA.ID_CHARAKTER = C2.ID_CHARAKTER
WHERE C2.NAZWA = 'Seminarium';

-- 9. Wyświetl dane o studentach, których stypendia są mniejsze niż najmniejsze stypendium na
-- -- Informatyce. ( <=  BO DLA < NIE MA ZADNYCH WYNIKOW)
SELECT STUDENT.IMIE, STUDENT.NAZWISKO, STUDENT.NRALBUMU
FROM STUDENT
         JOIN STYPENDIUM S on STUDENT.ID_STUDENT = S.ID_STUDENT
WHERE S.KWOTA <= (SELECT MIN(S2.KWOTA)
                  FROM STYPENDIUM S2
                           JOIN STUDENT S3 ON S2.ID_STUDENT = S3.ID_STUDENT
                           JOIN GRUPA G ON S3.ID_GRUPA = G.ID_GRUPA
                           JOIN KIERUNEK K on G.ID_KIERUNEK = K.ID_KIERUNEK
                  WHERE K.NAZWA = 'Informatyka');

-- 10. Wyświetl nazwiska, imiona i numery albumów studentów, którzy mają najwięcej ocen
-- z ćwiczeń.
SELECT S.IMIE, S.NAZWISKO, S.NRALBUMU
FROM OCENA
         JOIN STUDENT S on OCENA.ID_STUDENT = S.ID_STUDENT
         JOIN ZAJECIA Z on OCENA.ID_ZAJECIA = Z.ID_ZAJECIA
         JOIN CHARAKTER CH on Z.ID_CHARAKTER = CH.ID_CHARAKTER
WHERE CH.NAZWA = 'Ćwiczenia'
HAVING COUNT(OCENA.ID_STUDENT) = (SELECT MAX(COUNT(OCENA.ID_STUDENT))
                                  FROM OCENA
                                           JOIN STUDENT S2 on OCENA.ID_STUDENT = S2.ID_STUDENT
                                           JOIN ZAJECIA Z on OCENA.ID_ZAJECIA = Z.ID_ZAJECIA
                                           JOIN CHARAKTER CH on Z.ID_CHARAKTER = CH.ID_CHARAKTER
                                  WHERE CH.NAZWA = 'Ćwiczenia'
                                  GROUP BY OCENA.ID_STUDENT)
GROUP BY S.IMIE, S.NAZWISKO, S.NRALBUMU;


-- 11. Wyświetl, w które dni tygodnia jest najmniej zajęć.
SELECT DZIENTYG
FROM ZAJECIA
HAVING COUNT(DZIENTYG) = (SELECT MIN(COUNT(DZIENTYG))
                          FROM ZAJECIA
                          GROUP BY DZIENTYG)
GROUP BY DZIENTYG;

-- 12. Wyświetl imię i nazwisko, nr albumu najlepszego studenta (najwyższa średnia) oraz jego pełny
-- adres.
SELECT S.IMIE, S.NAZWISKO, S.NRALBUMU, A.MIASTO, A.ULICA, A.KODPOCZTOWY, A.NRLOKALU
FROM STUDENT S
         JOIN ADRES A on S.ID_ADRES = A.ID_ADRES
WHERE S.ID_STUDENT = (
    SELECT OCENA.ID_STUDENT
    FROM OCENA
    GROUP BY OCENA.ID_STUDENT
    HAVING AVG(OCENA) = (
        SELECT MAX(AVG(OCENA.OCENA))
        FROM OCENA
        GROUP BY OCENA.ID_STUDENT
    )
);
