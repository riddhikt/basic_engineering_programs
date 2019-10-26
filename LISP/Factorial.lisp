(defun fact(num)
(format t "~& <<<the fact ~d >>> ~& 1 i method ~& 2 r method ~& enter choice:" num)
(setq num(read))
(if (= x 1)
(format t "fact = ~d(using i)"   (fact1 num)))
(if (= x 2)
(format t "fact = ~d(using r)"   (fact2 num)))
 
)
(defun fact1 (n)
(let ((f1))
(loop for i from 1 to num 
do (setf f (* f i))
)
	f
)
)
(defun fact2 ()
(if  (= num 0)
          1
     	(* num fact2(- num 1))
    )


)


