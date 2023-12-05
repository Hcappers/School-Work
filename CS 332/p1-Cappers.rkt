#lang racket

(define l1 '(2  4  6  8  10))
(define l2 '(3 12 42 54))
(define l3 '(60 40 -10 5))
(define l4 '(5 6))
(define l5 '(0))

;Finds the max number in the list
(define findMax(lambda (l)(
    if (null? l)
        -inf.0
    (if (> (car l) (findMax (cdr l)))
        (car l)
        (findMax (cdr l))
    )
)))

; Finds the min number in the list
(define findMin(lambda(l)(
    if(null? l)
    +inf.0
    (if(< (car l) (findMin (cdr l)))
        (car l)
        (findMin (cdr l))
    )
)))

; ------ Question 1) Find the largest possible difference ------
(define findDiff (lambda(l) (
    if (null? l)
        +inf.0
    (- (findMax l) (findMin l))
    )
))
  


; ------ Question 2) Find the largest possible difference between two different lists where n is the larger and m is the min ------
(define findDiffBetweenNM(lambda(m n)
    (- (findMax n) (findMin m))
))

; ------ Question 3) Find the largest possible difference between two differenet lists where m is the larger and n is the min ------
(define findDiffBetweenMN(lambda(m n) 
    (- (findMax m) (findMin n))
))

;Test Cases
(display "Test cases for Question 1, 2, and 3")
(newline)
(display (findDiff l1))
(newline)
(display (findDiffBetweenNM l2 l3)) 
(newline)
(display (findDiffBetweenMN l2 l3))
(newline)
(display (findDiffBetweenNM l4 l5))
(newline)
(display (findDiffBetweenMN l4 l5))
(newline)
