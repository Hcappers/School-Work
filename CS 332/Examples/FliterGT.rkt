; FliterGT -- Given a list of integers, l, and a threshold, t, return a list of all integers in l that are greater than t.

#lang racket

(define l0 '())
(define l1 '(1 2 3 4 5 6 7 8 9 ))
(define l2 '(42 54 67 89 12 14 54 54 23))
(define l3 '(1 5 7 9 0 -10 45 67 89))
(define l4(append l1 l2 l3))
(define l5 (list l1 l2 l3 l4))

(define fliterGTLT (lambda (comparator l t))(
    if (null? l)
        '()
        (if (comparator (car l) t)
            (cons (car l) (fliterGTLT comparator (cdr l) t))
            (fliterGTLT comparator (cdr l) t)
        )
    )
)