type 'a my_list = Item of ('a * 'a my_list) | Empty

let rec length my_list = match my_list with
| Empty -> 0
| Item (head, tail) -> length (tail) + 1

let hd my_list = match my_list with
| Empty -> raise (Failure "hd")
| Item (head, _) -> head

let tl my_list = match my_list with
| Empty -> raise (Failure "tl")
| Item (_, tail) -> tail

let rev my_list =
let rec aux reverse = function
| Empty -> reverse
| Item (head, tail) -> aux (Item (head, reverse)) tail
in aux Empty my_list

let append my_list my_list2 =
let rec appendList aux = function
| Empty -> aux
| Item (head, tail) -> appendList (Item (head, aux)) tail
in appendList my_list2 (rev my_list)

let rev_append my_list my_list2 =
append (rev my_list) my_list2

let flattern my_list =
let rec concat aux = function
| Empty -> ()
| Item (head, tail) -> concat (rev_append head aux) tail
in concat Empty my_list

let rec split = function
| Empty -> (Empty, Empty)
| Item ((head, tail), tail2) -> let (a, b) = split tail2 in (Item (head, a), Item (tail, b))
