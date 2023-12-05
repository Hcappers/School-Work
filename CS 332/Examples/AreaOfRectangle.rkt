#lang racket
(define pl1 (list '(3 7 9 1) '(2 8 12 0) '(16 12 11 18)))
(define rect1 '(1 2 3 4))
(define rect2 '(10 5 0 5))
(define rect3 '(5 5 3 6))

(define getArea (lambda (rect)(
                  * (deltaX rect) (deltaY rect)
            )
      )
)

(define deltaX(lambda(rect)
      if (> (car rect) (car (cdr (cdr rect))))
         (- (car rect) (car (cdr (cdr rect))))
         (- (car (cdr (cdr rect))) (car rect))
      )
)


(define deltaY (lambda (rect) (
            if (> (car (cdr rect)) (car (cdr (cdr (cdr rect)))))
                  (- (car (cdr rect)) (car (cdr (cdr (cdr rect)))))
                  (- (car (cdr (cdr (cdr rect)))) (car (cdr rect)))
            )
      )
)
