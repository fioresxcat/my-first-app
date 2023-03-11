# ------------------------------------- util functions ---------------------------------
def compare_date(date1, date2):
    # both of date in the form yyyy-mm-dd
    y1, m1, d1 = date1.split('-')
    y2, m2, d2 = date2.split
    if y1 < y2:
        return -1
    elif y1 > y2:
        return 1
    else:
        if int(m1) < int(m2):
            return -1
        elif int(m1) > int(m2):
            return

def handle_number_people(query):
    return len(ls_data)

def handle_born_at(query):
    date = query.split()[-1]
    ls_citizen = [el for el in ls_data if el.split()[1] == date]
    return len(ls_citizen)

def handle_most_alive(query):
    pass

def handle_born_between(query: str):
    start, end = query.split()[1], query.split()[2]
    for line in ls_data:
        date = ls_data.split()[1]
        




if __name__ == '__main__':
    ls_data = []
    ls_query = []
    is_inputting_data = True
    s = input()
    while True:
        if s != '*' and is_inputting_data:
            ls_data.append(s)
        elif s == '*':
            is_inputting_data = False
        elif not is_inputting_data:
            if s != '***':
                ls_query.append(s)
            else:
                break







