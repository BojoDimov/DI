#lang racket
(provide my-reverse)
(provide palindrome?)

(define (my-reverse n)
  (define (helper current result)
    (if (<= current 0)
        result
        (helper (quotient current 10)
                (+ (* result 10) (remainder current 10)))))
  (helper n 0))

(define (palindrome? n)
  (= n (my-reverse n)))

(define (fib n)
  
  

  