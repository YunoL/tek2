let rec fibo n = match n with
| 0 -> 0
| 1 -> 1
| x when x > 0 -> (fibo (n - 1) + fibo (n - 2))
| _ -> raise (Invalid_argument "Negative value supplied to fibo")
