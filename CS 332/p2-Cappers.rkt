#lang racket

;Test case 1
(define cList1 '((0 0 1)))
(define pList1 '((5 5) (10 10) (15 15)))

;Test case 2
(define cList2 '((10 10 10) (20 20 20)))
(define pList2 '((5 5) (1 10) (10 15) (10 19) (19 10) (18 18)))

;Test case 3
(define cList3 '((5 10 5) (20 20 5)))
(define pList3 '((7 8) (15 5) (18 18) (22 23)))

;DeltaX finds the difference between two points
;Example taken from code PCMAXdist.rkt
(define DeltaX(lambda (p1 p2) (- p1 p2) ))

;DeltaY finds the difference between two points
;Example taken from code PCMAXdist.rkt
(define DeltaY(lambda (p1 p2)(- p1 p2)))

;Distance -> given the two points DeltaX and DeltaY, it finds the distance between them
;            formula: Distance = sqrt (x2-x1)^2 + (y2-y1)^2)      
;Example taken from code PCMAXdist.rkt  
(define Distance(lambda (X1 Y1 X2 Y2)
    (sqrt (+ (* (DeltaX X2 X1) (DeltaX X2 X1)) (* (DeltaY Y2 Y1) (DeltaY Y2 Y1))))))

;Check if the points are within the circle
(define (PointsInCircle Circle PList)
    (if (null? PList)
        '()
        (if (<= (Distance (car (car Circle)) (car (cdr (car Circle))) (car (car PList)) (car (cdr (car PList)))) (car (cdr (cdr (car Circle)))))
            (cons (car PList) (PointsInCircle Circle (cdr PList)))
            (PointsInCircle Circle (cdr PList))
        )
    )
)
;main functin that 

;Test case 1
(display "Test case 1: \n")
;Main function
(display "\n")

;Test Case 2
(display "Test case 2: \n")
;main function
(display "\n")

;Test Case 3
(display "Test case 3: \n")
;main function
(display "\n")
