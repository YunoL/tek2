let get_first_name (a, b, c, d) = a

let get_last_name (a, b, c, d) = b

let get_grad_year (a, b, c, d) = c

let is_close (a, b, c, d) = d

let is_in_grad_year (a, b, c, d) n = if n = c then true else false

let rec is_in_grad_year_range (a, b, c, d) m n = if c >= m && c <= n then true else false
