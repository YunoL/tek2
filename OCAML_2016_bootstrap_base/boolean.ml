type boolean = True | False

let my_and a b = match a, b with
| True, False -> False
| False, True -> False
| False, False -> False
| True, True -> True
