(define (selectList l1 l2)
  (if (> (length l1) (length l2)) l1 l2))

(define (sum list)
  (foldl (lambda (x y) (+ x y)) 0 list))

(define (sumMaxRoots f ll)
  (sum
    (foldl selectList '()
      (map (lambda (l)
        (filter (lambda (x) (= (f x) 0)) l)) ll))))