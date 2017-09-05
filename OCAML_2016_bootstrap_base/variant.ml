type day = Monday | Tuesday | Wednesday | Thursday  | Friday | Saturday | Sunday
type month = January | February | March | April | May | June | July | August | September | October | November | December

let next_day day = match day with
| Monday -> Tuesday
| Tuesday -> Wednesday
| Wednesday -> Thursday
| Thursday -> Friday
| Friday -> Saturday
| Saturday -> Sunday
| Sunday -> Monday

let next_month month = match month with
| January -> February
| February -> March
| March -> April
| April -> May
| May -> June
| June -> July
| July -> August
| August -> September
| September -> October
| October -> November
| November -> December
| December -> January

let is_leap_year year = match year with
| x when x mod 4 == 0 && x mod 10 != 0 -> true
| x when x mod 400 == 0 -> true
| _ -> false

let nb_days year month = match year, month with
| x, February when is_leap_year x == true -> 29
| _, February -> 28
| _, January -> 31
| _, March -> 31
| _, April -> 30
| _, May -> 31
| _, June -> 30
| _, July -> 31
| _, August -> 31
| _, September -> 30
| _, October -> 31
| _, November -> 30
| _, December -> 31

let next_nday day month year = match day, month, year with
| x, February, y when is_leap_year y == true && x == 29 -> (1, true)
| x, February, y when x == 28 && is_leap_year y == false -> (1, true)
| x, February, _ -> (x + 1, false)
| x, January, _ when x == 31 -> (1, true)
| x, March, _ when x == 31 -> (1, true)
| x, April, _ when x == 30 -> (1, true)
| x, May, _ when x == 31 -> (1, true)
| x, June, _ when x == 30 -> (1, true)
| x, July, _ when x == 31 -> (1, true)
| x, August, _ when x == 31 -> (1, true)
| x, September, _ when x == 30 -> (1, true)
| x, October, _ when x == 31 -> (1, true)
| x, November, _ when x == 30 -> (1, true)
| x, December, _ when x == 31 -> (1, true)
| x, _, _ -> (x + 1, false)

let next (day, nb_day, month, year) = match day, nb_day, month, year with
| i, x, y, z when next_nday x y z = (1, true) && y == December -> (next_day i, 1, next_month y, z + 1)
| i, x, y, z when next_nday x y z = (1, true) -> (next_day i, 1, next_month y, z)
| i, x, y, z -> (next_day i, x + 1, y, z)
