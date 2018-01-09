from assignment import AssignmentsDB
from csv import DictWriter, writer


def main():
    assignments_db = AssignmentsDB()

    with open('general_assignments.csv', 'w', newline='') as file:
        # fieldnames = ['ID', 'assigned_test_list']
        w = writer(file, dialect='excel')
        # w.writerow(fieldnames)
        for i in assignments_db.general_assignments_dict:
            w.writerow([i] + assignments_db.general_assignments_dict[i])


if __name__ == '__main__':
    main()
