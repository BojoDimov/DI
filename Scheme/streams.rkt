#lang racket
; Това е грешно, защото cons-stream трябва да оценява само първият си аргумент
; (define (cons-stream h t) (cons h (delay t)))
(define the-empty-stream '())
(define empty-stream? null?)
(define head car)
(define (tail s) (force (cdr s)))

(define-syntax cons-stream
  (syntax-rules () ((cons-stream h t) (cons h (delay t)))))

; Да се построи редица от целите числа в интервала [a;b]
(define (range a b)
  (if (> a b) the-empty-stream
      (cons-stream a (range (+ a 1) b))))

; Намира първите n елемента от поток
(define (first n s)
  (cond ((empty-stream? s) '())
        ((= n 0) '())
        (else (cons (head s) (first (- n 1) (tail s))))))


; Да се намери първата позиция в поток на която има елемент с дадено свойство
(define (search p? stream)
  (define (helper pos stream)
    (cond ((empty-stream? stream) #f)
          ((p? (head stream)) pos)
          (else (helper (+ pos 1) (tail stream)))))
  (helper -1 stream))
(define (gt5 x)(> x 5))

; Безкраен поток
(define (from n)
  (cons-stream n (from (+ n 1))))

; Числа на фибоначи
(define (generate-fibs a b)
  (cons-stream a (generate-fibs b (+ a b))))
(define fibs (generate-fibs 0 1))

; Map stream
(define (map-stream f s)
  (if (empty-stream? s) '()
      (cons-stream (f (head s)) (map-stream f (tail s)))))

; Filter stream
(define (filter-stream p? s)
  (cond ((empty-stream? s)s)
        ((p? (head s)) (cons-stream (head s) (filter-stream p? (tail s))))
        (else (filter-stream p? (tail s)))))

(first 15 (from 50))
(first 10 fibs)
(first 10 (map-stream (lambda (x) (+ 100 x)) (from 1)))
(first 10 (filter-stream (lambda (x) (> x 100)) (from 0)))