; CountIfEquals - Given a list of integers, l, and a key, key, return
;      the number of times that the key appears in l.
#lang racket
(define  l0 '())
(define l1 '( 1 2 3 4 5 6 7 8 9))
(define l2 '(42 54 67 89 12 14 54 54 23))
(define l3 '(1 5 7 9 0 -10 45 67 89 ))
(define l4 (append l1 l2 l3))

(define countIf (lambda (l key) (
                        if (null? l)
                           0
                           (if (eq? (car l) key)
                               (+ 1 (countIf (cdr l) key))
                               (countIf (cdr l) key)
                            )
                           )
                 )
  )