; FilterGTx -- Given a list of points, plist, and some threshold x value, xt,
;              return the points that have an x-coordinate value greater than xt.

#lang racket
(define plist1 (list '(0 0) '(4 0) '(0 4) '(4 4)))
(define plist2 (list '(24 5 )'(1 22 ) '(1 43 ) '(24 29 ) '(19 47 ) '(16 28 ) '(33 33 ) '(39 22 ) '(49 17 ) '(25 36 ) ))
(define plist3 (list '(43 23 ) '(33 16 ) '(9 29 ) '(5 9 ) '(47 0 ) '(50 46 ) '(12 22 ) '(11 31 ) '(29 19 ) '(48 39 ) ))
(define plist4 (list '(5 5) '(5 5) '(5 5)))
(define plist5 (list '(0 0) '(5 0) '(10 0)))
(define plist6 (list '(0 0) '(100 100) '(0 0) '(1 2) '(3 4)))
(define plist7 '())

; xpointGTXT -- Given a point, p, and a threshold, xt, returns #t if the x-coordinate of the point
;       is greater than the threshold, and #f otherwise.
(define xpointGTXT (lambda (p xt) (
                                   if (null? p)
                                      #f
                                      (if (> (car p) xt)
                                          #t
                                          #f)
                                   )
                     )
  )


(define filterGTx (lambda (plist xt) (
                                if (null? plist)
                                   '()
                                   (if (xpointGTXT (car plist) xt)
                                       (cons (car plist) (filterGTx (cdr plist) xt) )
                                       (filterGTx (cdr plist) xt)
                                       )
                                      )
                    )
  )