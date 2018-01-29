from assignment import AssignmentsDB


class InterFace:
    def __init__(self):
        pass


def interface(assignments_db):
    print("Please select what would you like to do:")
    print('1. Assign new test subject')
    print('2. Print current test subjects')
    option = input('Choose [1-2] or q to quit')

    while option == '1':
        name = input('Please Insert Name:\n')
        if name == '':
            continue
        email = input('Please Insert Email:\n')
        test_name = assignments_db.get_name(email)
        if email == '' or '@' not in email:
            print('*** Error *** \n Invalid Email address\n')
            continue
        elif test_name is not None:
            subj_number = assignments_db.get_subject_number(email)
            print('The Email already exists with the name {}, and subj number: {}'.format(test_name, subj_number))
        print('Name is: {} \nEmail is: {}'.format(name, email))
        approved = input('Is This correct? [Yes]/No: ')
        print(approved)
        if approved == '' or approved.lower() == 'yes':
            assignee = AssignSubject(name, email, assignments_db)
            for i in assignments_db.personal_assignment_dict:
                print('key is: {} \nvalue is: {}'.format(i, assignments_db.personal_assignment_dict[i]))
            option = input('Choose [1-2] or q to quit')
        else:
            continue
        if option == 'q':
            return
