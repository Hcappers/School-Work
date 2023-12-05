; PCCenterofMass -- Given a list of unweighted points, PC, return the center of mass,
;       CM, where CM = ( average X-value, average Y-value).

#lang racket
(define plist1 (list '(0 0) '(4 0) '(0 4) '(4 4)))
(define plist2 (list '(24 5 )'(1 22 ) '(1 43 ) '(24 29 ) '(19 47 ) '(16 28 ) '(33 33 ) '(39 22 ) '(49 17 ) '(25 36 ) ))
(define plist3 (list '(43 23 ) '(33 16 ) '(9 29 ) '(5 9 ) '(47 0 ) '(50 46 ) '(12 22 ) '(11 31 ) '(29 19 ) '(48 39 ) ))
(define plist4 (list '(5 5) '(5 5) '(5 5)))
(define plist5 (list '(0 0) '(5 0) '(10 0)))
(define plist6 (list '(0 0) '(100 100) '(0 0) '(1 2) '(3 4)))
(define plist7 '())

; ySum -- Given a list of points, plist, return the sum of the y-values.
(define ySum (lambda (plist) (
                              if (null? plist)
                                 0
                                 (+ (car (cdr (car plist))) (ySum (cdr plist))  )
                              )
               )
  )

; xSum -- Given a list of points, plist, return the sum of the x-values.
(define xSum (lambda (plist) (
                              if (null? plist)
                                 0
                                 (+ (car (car plist)) (xSum (cdr plist)))
                              )
               )
  )

; xAverage -- Given a list of points, plist, return the average x-value.
(define xAverage (lambda (plist) (
                                  if (null? plist)
                                     "Error: Points list is empty."
                                     (/ (xSum plist) (length plist) )

                                  )
                   )
  )

; yAverage -- Given a list of points, plist, return the average y-value. 
(define yAverage (lambda (plist) (
                                  if (null? plist)
                                     "Error: Points list is empty."
                                     (/ (ySum plist) (length plist) )

                                  )
                   )
  )

; CMass -- Given a list of points, plist, return the center of mass = (average X-value, average y-value)
(define cMass (lambda (plist) (list (xAverage plist) (yAverage plist))))

(map cMass (list plist1 plist2 plist3 plist4 plist5 plist6 plist7))