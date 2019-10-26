(defun bubble ()
        (bubbleread)
        
        (do ((i 0 (+ i 1))) ((= i (- n 1)))
        
                (do ((j 0 (+ j 1))) ((= j (- (- n i) 1)))
                
                        (if (> (aref arr j) (aref arr (+ j 1) ) )
                                (swap j (+ j 1))
                         )
                )
                (format t "~% Pass ~D" (+ i 1))
                (write arr)
        )
        
)
(defun swap(x y)
        (setf temp (aref arr x))
        (setf (aref arr x) (aref arr y))
        (setf (aref arr y) temp)
)

(defun bubbleread()
        (format t "~% Enter the size of array")
        (terpri)
        (setf n (read))
        (setf arr (make-array n))
        (terpri)
        (loop for i from 0 to (- n 1)
                do (setf (aref arr i) (read))
        )
)
 
 
               
(bubble )
