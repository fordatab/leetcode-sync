(define/contract (two-sum nums target)
  (-> (listof exact-integer?) exact-integer? (listof exact-integer?))
    (for/fold ([seen (hash)])
              ([n nums] [idx (in-naturals)]
               #:break (list? seen))
        (define k (- target n))
        (if (hash-has-key? seen k)
            (list (hash-ref seen k) idx)
            (hash-set seen n idx))))