type day = Monday | Tuesday | Wednesday | Thursday  | Friday | Saturday | Sunday
type month = January | February | March | April | May | June | July | August | September | October | November | December

module type CALENDAR =
  sig
    type date = day * int * month * int

    val next_day      : day -> day
    val next_month    : month -> month
    val is_leap_year  : int -> bool
    val nb_days       : int -> month -> int
    val next_nday     : int -> month -> int -> int * bool
    val next          : date -> date
  end

module Calendar : CALENDAR
