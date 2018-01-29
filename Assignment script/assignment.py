from collections import defaultdict
from itertools import combinations, permutations, cycle
from random import shuffle, randint, random, sample
from config import BASELINE_WORKS, WORKS_PER_STUDENT, TEST_WORKS, BAD_WORKS, BAD_CODE, BUG_CODE, NUMBER_OF_STUDENTS


class AssignmentsDB:
    def __init__(self):
        # subj id: [code files]
        self.general_assignments_dict = defaultdict(list)
        self.__generate_assignments()
        self.personal_assignment_dict = defaultdict(list)
        self.counter_100 = 0
        self.counter_200 = 0

    def __generate_assignments(self):
        x = list(range(1, TEST_WORKS + BASELINE_WORKS))
        temp = set(x)
        for code in BAD_WORKS:
            if code in temp:
                x.remove(code)

        works = cycle(x)
        temp = list()
        for work in works:
            temp.append(work)
            if len(temp) == NUMBER_OF_STUDENTS:
                for i, code in enumerate(temp):
                    self.general_assignments_dict[100 + i].append(code)
                    # self.general_assignments_dict[200 + i].append(code)
                if len(self.general_assignments_dict[100]) == WORKS_PER_STUDENT - BASELINE_WORKS:
                    break
                else:
                    temp = list()

        for i in range(NUMBER_OF_STUDENTS):
            for k in range(BASELINE_WORKS):
                basecode = BAD_CODE if random() > 0.5 else BUG_CODE
                self.general_assignments_dict[100 + i].append(basecode)
                # self.general_assignments_dict[200 + i].append(basecode)
