; FilterInsideBox -- Given a list of points, plist, and a rectangle, rect,
;       return a list composed of points in plist that are inside the boundaries of rect.

#lang racket
(define plist1 (list '(0 0) '(4 0) '(0 4) '(4 4)))
(define plist2 (list '(24 5 )'(1 22 ) '(1 43 ) '(24 29 ) '(19 47 ) '(16 28 ) '(33 33 ) '(39 22 ) '(49 17 ) '(25 36 ) ))
(define plist3 (list '(43 23 ) '(33 16 ) '(9 29 ) '(5 9 ) '(47 0 ) '(50 46 ) '(12 22 ) '(11 31 ) '(29 19 ) '(48 39 ) ))
(define plist4 (list '(5 5) '(5 5) '(5 5)))
(define plist5 (list '(0 0) '(5 0) '(10 0)))
(define plist6 (list '(0 0) '(100 100) '(0 0) '(1 2) '(3 4)))
(define plist7 '())
(define rect1 '(0 10 10 0))
(define rect2 '(10 10 20 5))
(define rect3 '(0 300 300 0))

; xInBounds - given a rectangle, rect, and an x-value, x, return #t
;      if x is within the x-component of rect, and #f otherwise.
(define xInBounds (lambda (rect x) (
                          if (and (> x (car rect)) (< x (car (cdr (cdr rect)))) )
                             #t
                             #f
                                    )
                    )
  )


; yInBounds -- given a rectangle, rect, and a y-value, y, return #t
;       if y is within the y-component of rect, and #f otherwise.
(define yInBounds (lambda (rect y) (
                          if (and (< y (car (cdr rect))) (> y (car (cdr (cdr (cdr rect))))) )
                             #t
                             #f
                                    )
                    )
  )

; pointInBox? -- Given a point p, and a rectangle, rect,
;           return #t if p is in rect, and #f otherwise
(define pointInBox? (lambda (p rect)  (
                              if (and (xInBounds rect (car p)) (yInBounds rect (car (cdr p))) )
                                 #t
                                 #f
                                       )
                                      
                      )
  )

; filterInsideBox - given a list of points plist, and a rectangle, rect,
;           return a list of all points in plist inside of rect.
(define filterInsideBox (lambda (plist rect) (
                                   if (null? plist)
                                      '()
                                      (if (pointInBox? (car plist) rect)
                                          (cons (car plist) (filterInsideBox (cdr plist) rect))
                                          (filterInsideBox (cdr plist) rect)
                                          )
                                              )
                          )
  )