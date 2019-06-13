#lang planet neil/sicp

;Zadanie 2. Oblicz wartość wyrażenia przy pomocy Lispa
(display(/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 3))))) (* 3 (- 6 2) (- 2 7))))


;Zadanie 3. Napisz funkcję przyjmującą trzy argumenty, zwracającą sumę pierwszego i iloczynu
;dwóch ostatnich: (a+b*c).

(define (fun a b c)(+ a (* b c)))
( display (fun 1 2 3))


;Zadanie 4. Napisz funkcję przyjmującą trzy argumenty, zwracającą sumę kwadratów dwóch
;największych argumentów.

(define (p y) (* y y)) ;potega

(
define(fun1 a1 a2 a3)
(define a 0)
(if (<= a1 a2 a3)  (set! a (+ (p a2) (p a3)))) a
(if (<= a1 a3 a2)  (set! a (+ (p a2) (p a3)))) a
(if (<= a2 a1 a3)  (set! a (+ (p a1) (p a3)))) a
(if (<= a2 a3 a1)  (set! a (+ (p a1) (p a3)))) a
(if (<= a3 a2 a1)  (set! a (+ (p a2) (p a1)))) a
(if (<= a3 a1 a2)  (set! a (+ (p a2) (p a1)))) a
)

(display (fun1 1 1 3))

;Zadanie 5. Napisz funkcję która wylicza i wypisuje rozwiązania równania kwadratowego
;ax^2+bx+c=0. Funkcja powinna przyjmować jako argumenty wartości a, b, c oraz x. Zakładamy, że
;zawsze są dwa rozwiązania.

(define(d a b c) (- (* b b) (* 4 a c)))
(
 define(rownanieKwadratowe a b c)
  (define x1 0)
  (define x2 0)
  (define delta 0)
  (set! delta (d a b c) )
  (set! x1 (/ (+ (- b) (sqrt delta)) (* 2 a)))
  (set! x2 (/ (- (- b) (sqrt delta)) (* 2 a)))
  (display x1)
  (display x2)
)
(rownanieKwadratowe 1 6 9)


