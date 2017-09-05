let rec fact_if x = if x <= 1 then 1 else x * fact_if (x - 1)

let rec fact_match = function x -> if x <= 1 then 1 else x * fact_match (x - 1)
