; PCMaxDist -- Given a list of points, plist, return the maximum distance between two points.

#lang racket
(define plist1 (list '(0 0) '(4 0) '(0 4) '(4 4)))
(define plist2 (list '(24 5 )'(1 22 ) '(1 43 ) '(24 29 ) '(19 47 ) '(16 28 ) '(33 33 ) '(39 22 ) '(49 17 ) '(25 36 ) ))
(define plist3 (list '(43 23 ) '(33 16 ) '(9 29 ) '(5 9 ) '(47 0 ) '(50 46 ) '(12 22 ) '(11 31 ) '(29 19 ) '(48 39 ) ))
(define plist4 (list '(5 5) '(5 5) '(5 5)))
(define plist5 (list '(0 0) '(5 0) '(10 0)))
(define plist6 (list '(0 0) '(100 100) '(0 0) '(1 2) '(3 4)))
(define plist7 '())

; getDeltaX -- given two points, p1 and p2, return the distance between the x-coordinates.
(define getDeltaX (lambda (p1 p2) (- (car p1) (car p2)  ) ))

; getDeltaY -- given two points, p1 and p2, return the distance between the y-coordinates.
(define getDeltaY (lambda (p1 p2) (- (car (cdr p1)) (car (cdr p2)) ) ))

; getDistance -- given two points, p1 and p2, return the distance between the points, where
;        distance, d = sqrt(dx*dx + dy*dy)
(define getDistance (lambda (p1 p2) (sqrt (+ (* (getDeltaX p1 p2) (getDeltaX p1 p2))  (* (getDeltaY p1 p2) (getDeltaY p1 p2)) ) ) ))

; getDistList -- given a list of points, plist and a point, p, return the list of all distances
;        between p and every point in plist.
(define getDistList (lambda (plist p) (
                            if (null? plist)
                               '()
                               (cons (getDistance p (car plist)) (getDistList (cdr plist) p) )
                                       )
                      )
  )

; getAllDistances -- given a list of points, plist (= p1 p2 p2 ... pn), return the list of all distances between
;        all points. This is done by appending the lists created by the list of distances between p1 and all
;        points to the right with the list between p2 and all points to the right, and so on.
(define getAllDistances (lambda (plist) (
                         if (< (length plist) 2)
                            "Error: Points list has less than 2 points in getAllDistances."
                            (if (eq? (length plist) 2)
                                (getDistList (cdr plist) (car plist))
                                (append (getDistList (cdr plist) (car plist)) (getAllDistances (cdr plist)))
                                         )
                          )
                          )
  )

; FindMax -- given a list of values, l, return the max value in the list.
;       Note: I ended up not using this function because it has horrible
;             performance for larger lists. Used the Racket sort function instead.
(define findMax (lambda (l) (
                 if (null? l)
                    0
                    (if (> (car l) (findMax (cdr l)) )
                        (car l)
                        (findMax (cdr l))
                        )
                             )
                  )
  )
                  

; PCMaxDist -- Given a list of points, plist, return the maximum distance between two points.
;       Note that the sort function supported by racket is found to find the maximum value
;       in the list of distances.
(define PCMaxDist (lambda (plist) (
                     if (< (length plist) 2)
                        "Error: Point cloud has less than two points in PCMaxDist"
                        (car (sort (getAllDistances plist) >))
                        )
                    )
  )