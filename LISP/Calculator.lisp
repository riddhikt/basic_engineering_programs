(loop

(princ "enter 1st num ")
(terpri)
(setq num1 (read))
(princ "enter 2nd num ")
(terpri)
(setq num2 (read))
(format t "~%enter 1. for addition ~% enter 2. for subtraction ~% 3. for multiplication ~% 4. for division")
(terpri)
(setq num(read))
(case num
	(1 (format t "Addition is ~2d" (+ num1 num2)))

	(2 (format t "Subtraction is ~2d"(- num1 num2)))

	(3 (format t "Multiplication is ~2d"(* num1 num2)))

	(4 (format t "Division is ~2d ~%"(/ num1 num2)))

)

(when (< num 4)))
