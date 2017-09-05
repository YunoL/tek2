type field = All | Id | Name | Surname | Age | Email | Phone | Date | Hour | Time
type contact = {mutable firstname : string; mutable lastname : string; mutable age : int; mutable email : string; mutable telephone : string}

module type CONTACT =
  sig
  end

module Agenda : AGENDA
