; FilterList -- Given a superlist, sl, and a key value, key, return
;        a superlist containing only lists that contain the key.
; Note: A superlist is a list containing lists of integers.

#lang racket
(define  l0 '())
(define l1 '( 1 2 3 4 5 6 7 8 9))
(define l2 '(42 54 67 89 12 14 54 54 23))
(define l3 '(1 5 7 9 0 -10 45 67 89 ))
(define l4 (append l1 l2 l3))
(define l5 (list l0 l1 l2 l3 l4))



(define filterList (lambda (sl key) (
                               if (null? sl)
                                  '()
                                  (if (search (car sl) key)
                                      (cons (car sl) (filterList (cdr sl) key))
                                      (filterList (cdr sl) key)
                                    )
                     )
  ))

; Search -- Inputs: A list, l, and a key, key.
;           Outputs: #t iff key is in l.
(define search (lambda (l key) (
                       if (null? l)
                           #f
                           (if (eq? (car l) key)
                               #t
                               (search (cdr l) key)
                              )
                           )
                 )
  )