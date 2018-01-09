from collections import defaultdict
from random import shuffle
from config import BASELINE_WORKS, WORKS_PER_STUDENT, TEST_WORKS


class AssignmentsDB:
    def __init__(self):
        # subj id: [code files]
        self.general_assignments_dict = defaultdict(list)
        self.__generate_assignments__()
        self.personal_assignment_dict = defaultdict(list)
        self.counter_100 = 0
        self.counter_200 = 0

    def __generate_assignments__(self):
        x = list(range(BASELINE_WORKS, TEST_WORKS + BASELINE_WORKS))

        for _ in range(WORKS_PER_STUDENT - BASELINE_WORKS):
            shuffle(x)
            for i, code in enumerate(x):
                self.general_assignments_dict[100+i].append(code)
                self.general_assignments_dict[200+i].append(code)
        for i in self.general_assignments_dict.keys():
            for k in range(BASELINE_WORKS):
                self.general_assignments_dict[i].insert(k, k)
