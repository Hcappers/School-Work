; PCBoundingBox -- Given a list of points, plist, return the rectangle
;           that bounds, or contains, all of the points. 

#lang racket
(define plist1 (list '(0 0) '(4 0) '(0 4) '(4 4)))
(define plist2 (list '(24 5 )'(1 22 ) '(1 43 ) '(24 29 ) '(19 47 ) '(16 28 ) '(33 33 ) '(39 22 ) '(49 17 ) '(25 36 ) ))
(define plist3 (list '(43 23 ) '(33 16 ) '(9 29 ) '(5 9 ) '(47 0 ) '(50 46 ) '(12 22 ) '(11 31 ) '(29 19 ) '(48 39 ) ))
(define plist4 (list '(5 5) '(5 5) '(5 5)))
(define plist5 (list '(0 0) '(5 0) '(10 0)))
(define plist6 (list '(0 0) '(100 100) '(0 0) '(1 2) '(3 4)))
(define plist7 '())

;makeXList -- given a list of points, plist, return a list containing all of the x-coordinates.
(define makeXList (lambda (plist) (
                        if (null? plist)
                           '()
                            (cons (car (car plist)) (makeXList (cdr plist)) )
                                   )
                    )
  )

; makeYList -- given a list of points, plist, return a list containing all of the y-coordinates.
(define makeYList (lambda (plist) (
                        if (null? plist)
                           '()
                            (cons (car (cdr (car plist))) (makeYList (cdr plist)) )
                                   )
                    )
  )

; findMax -- given a list of values, l, return the maximum value in the list.
(define findMax (lambda (l) (
                       if (null? l)
                          0
                          (if (> (car l) (findMax (cdr l)))
                              (car l)
                              (findMax (cdr l))
                           )
                             )
                  )
  )

; findMin -- given a list of values, l, return the minimum value in the list.
(define findMin (lambda (l) (
                       if (null? l)
                          "Error: List is empty in findMin"
                          (if (eq? 1 (length l))
                              (car l)
                              (if (< (car l) (findMin (cdr l)) )
                                  (car l)
                                  (findMin (cdr l))
                               )
                           )
                          
                             )
                  )
  )

; PCBoundingBox -- Given a list of points, plist, return the rectangle
;           that bounds, or contains, all of the points.
(define PCBoundingBox (lambda (plist) (
                           list (findMin (makeXList plist))
                                (findMax (makeYList plist))
                                (findMax (makeXList plist))
                                (findMin (makeYList plist))
                                       )
                        )
  )