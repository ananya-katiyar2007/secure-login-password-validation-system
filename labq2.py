def change_string(s):
    s="x"+s[1:]
    print("inside function:",s)

    my_string="hello"
    print("before:",my_string)
    change_string(my_string)
    print("after:",my_string)
