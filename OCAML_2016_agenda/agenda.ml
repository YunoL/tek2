open Contact
type field = All | Id | Name | Surname | Age | Email | Phone | Date | Hour | Time

exception Add_Contact_With_Invalid_Data

module type AGENDA =
  sig
    val addContact     : Contact.contact list -> string * string * int * string * string -> Contact.contact list
    val getContactId   : Contact.contact list -> field -> string -> int
    val removeContact  : Contact.contact list -> int -> Contact.contact list
    val replaceContact : Contact.contact list -> int -> string * string * int * string * string -> Contact.contact list
    val printContacts  : Contact.contact list -> field -> string -> unit
  end

module Agenda : AGENDA =
  struct
    let addContact list (surname, name, age, email, phone) = match surname with
    | "" -> raise Add_Contact_With_Invalid_Data
    | _ -> match name with
      | "" -> raise Add_Contact_With_Invalid_Data
      | _ -> match age with
        | f when f < 0 -> raise Add_Contact_With_Invalid_Data
        | f when f > 120 ->  raise Add_Contact_With_Invalid_Data
        | _ -> list@[{surname = capitalize(String.trim(surname)); name = String.trim(String.uppercase(name)); age = age; email = check_email email true; phone = check_phone phone true}]
  end
