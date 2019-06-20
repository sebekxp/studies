-- 1. Wyświetl nazwę budynku i identyfikator dla wszystkich budynków w bazie.
SELECT B.NAZWA, B.ID_BUDYNEK
FROM BUDYNEK B;
-- 2. Wyświetl nazwiska, imiona i identyfikatory studentów sortując nazwiska w kolejności
-- alfabetycznej.
SELECT IMIE, NAZWISKO, ID_STUDENT
FROM STUDENT
ORDER BY NAZWISKO;
-- 3. Wyświetl wszystkie tytuły naukowe, które nie zawierają inż.
SELECT NAZWA
FROM TYTULNAUKOWY
WHERE NAZWA NOT LIKE '%inż%';
-- 4. Wyświetl nazwę przedmiotu, który kończy się na literę „a”.
SELECT NAZWA
FROM PRZEDMIOT
WHERE NAZWA LIKE '%a';
-- 5. Wyświetl wszystkie dane (imię, nazwisko, pełen adres, tytuł naukowy) na temat
-- wykładowców o nazwisku zaczynającym sie na literę P.
SELECT W.IMIE,
       W.NAZWISKO,
       A.ULICA,
       A.NRBUDYNKU,
       A.NRLOKALU,
       A.KODPOCZTOWY,
       A.MIASTO,
       T.NAZWA
FROM WYKLADOWCA W
         JOIN TYTULNAUKOWY T on W.ID_TYTUL = T.ID_TYTUL
         JOIN ADRES A on W.ID_ADRES = A.ID_ADRES
WHERE W.NAZWISKO LIKE 'P%';
-- 6. Wyświetl wszystkie dane (imię, nazwisko, nr albumu, grupę i pełen adres) na temat
-- wszystkich studentów.
SELECT S.IMIE,
       S.NAZWISKO,
       S.NRALBUMU,
       G.NAZWA,
       A.ULICA,
       A.NRBUDYNKU,
       A.NRLOKALU,
       A.KODPOCZTOWY,
       A.MIASTO
FROM STUDENT S
         JOIN ADRES A on S.ID_ADRES = A.ID_ADRES
         JOIN GRUPA G ON G.ID_GRUPA = S.ID_GRUPA;
-- 7. Wyświetl miasto, kod pocztowy, ulicę i numer lokalu
-- a) kolumnom nadaj nazwy MIASTO, KOD POCZ., ul. oraz nr lokalu.
SELECT MIASTO      AS "MIASTO",
       KODPOCZTOWY AS "KOD POCZ",
       ULICA       AS "UL.",
       NRLOKALU    AS "NR LOKALU"
FROM ADRES;
-- b) kolumny złącz w jedną kolumnę i nazwij DANE ADRESOWE.
SELECT (MIASTO || ' ' ||
        KODPOCZTOWY || ' ' ||
        ULICA || ' ' ||
        NRLOKALU) AS "DANE ADRESOWE"
FROM ADRES;
-- 8. Wyświetl nazwisko, imię i nr albumu studentów mieszkających poza Krakowem.
SELECT S.IMIE, S.NAZWISKO, S.NRALBUMU, A.MIASTO
FROM STUDENT S
         JOIN ADRES A on S.ID_ADRES = A.ID_ADRES
WHERE A.MIASTO NOT LIKE 'Kraków';
-- 9. Wyświetl wszystkie informacje na temat sal, których kod zawiera literę F lub liczby 01.
SELECT SALA.*
FROM SALA
WHERE KODSALI LIKE '%F%'
   OR KODSALI LIKE '%01%';
-- 10. Wyświetl miasto i ulicę; ulica jest wyrazem, w którym na drugim miejscu znajduje się litera O
-- lub I a pozostałe są dowolne, natomiast miejscowość ma 8 znaków.
SELECT MIASTO, ULICA
FROM ADRES
WHERE (ULICA LIKE '_o%' OR ULICA LIKE '_i%')
  AND LENGTH(MIASTO) = 8;
-- 11. Wyświetl pkt. ECTS i nazwę wszystkich przedmiotów, których nazwa ma więcej niż 13 znaków
-- pomijając wszystkie spacje w tytule.
SELECT NAZWA, ECTS
FROM PRZEDMIOT
WHERE LENGTH(REPLACE(NAZWA, ' ', '')) > 13;
-- 12. Wyświetl liczbę studentów z każdej grupy.
SELECT G.NAZWA, COUNT(S.ID_GRUPA) AS "OSOB W GRUPIE"
FROM STUDENT S
         JOIN GRUPA G ON S.ID_GRUPA = G.ID_GRUPA
GROUP BY G.NAZWA;
-- 13. Wyświetl wszystkie oceny w kolejności od tej uzyskanej najwcześniej. Daty powinny być
-- wyświetlone w formacie dzień/miesiąc/rok np. 09/03/2018
SELECT OCENA, TO_CHAR(DATA, 'DD/MM/YYYY') AS DATA
FROM OCENA
ORDER BY TO_DATE(DATA, 'DD/MM/YYYY') DESC;
-- 14. Wyświetl ile jest rodzajów zajęć (nazwa przedmiotu, charakter zajęć).
SELECT DISTINCT P.NAZWA, CH.NAZWA, COUNT(CH.ID_CHARAKTER)
FROM ZAJECIA
         JOIN CHARAKTER CH on ZAJECIA.ID_CHARAKTER = CH.ID_CHARAKTER
         JOIN PRZEDMIOT P on ZAJECIA.ID_PRZEDMIOT = P.ID_PRZEDMIOT
GROUP BY P.NAZWA, CH.NAZWA;
