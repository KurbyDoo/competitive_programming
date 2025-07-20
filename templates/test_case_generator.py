import random
import timeit
from solver_template import Solution  # Change file name to match solver

"""
Create a folder with the problem code
Inside that folder create a folder named test_cases
"""

output_path = "tcc/contests/tcc23nov/p3/problem_code"
yml_file = open(f"{output_path}/init.yml", "w+")
yml_file.write("archive: test_cases.zip\ntest_cases:\n")

solver = Solution()
number_of_sample_cases = 0

sample_input = ["7 10\n",
                "7 25\n",
                "7 50\n"]

sample_output = ["KURBYDOO MAKES THE BUS\n",
                 "KURBYDOO SKIPS BREAKFAST\n",
                 "KURBYDOO MISSES THE BUS\n"]


batch_points = []  # [1, 2, 7]
batch_constraints = {}  # {"N": [10, 100, 1000], "Q": [1, 10, 100]}

batched = True
cases_per_batch = 0
number_of_batches = 0


# Add sample cases to /test_cases
# Sample cases are made by hand
if number_of_sample_cases != 0:
    if batched: yml_file.write("- batched:\n")
    for sample_number in range(1, number_of_sample_cases + 1):
        yml_file.write(f"{'  ' if batched else ''}- in: test_cases/sample_{sample_number}.in\n")
        yml_file.write(f"{'  ' if batched else ''}  out: test_cases/sample_{sample_number}.out\n")
        with open(f"{output_path}/test_cases/sample_{sample_number}.in", "w+") as f:
            f.write(sample_input[sample_number - 1])

        with open(f"{output_path}/test_cases/sample_{sample_number}.out", "w+") as f:
            f.write(sample_output[sample_number - 1])
        
        yml_file.write(f"  points: 0\n")



for batch_number in range(1, number_of_batches + 1):
    if batched: yml_file.write("- batched:\n")

    for case_number in range(1, cases_per_batch + 1):
        start_time = timeit.default_timer()
        print(f"writing {batch_number}:{case_number}", end=" ")
        yml_file.write(f"{'  ' if batched else ''}- in: test_cases/{batch_number}_{case_number}.in\n{'  ' if batched else ''}  out: test_cases/{batch_number}_{case_number}.out\n")
        with open(f"{output_path}/test_cases/{batch_number}_{case_number}.in", "w+") as f:
            input_text = ""

            # Input Code Here

            # ---

            f.write(f"{input_text}")

        print(f"took {timeit.default_timer() - start_time}")
        start_time = timeit.default_timer()
        print(f"solving {batch_number}:{case_number}", end=" ")

        with open(f"{output_path}/test_cases/{batch_number}_{case_number}.out", "w+") as f:
            output_text = solver.solve(input_text)
            f.write(f"{output_text}")

        print(f"took {timeit.default_timer() - start_time}")

    yml_file.write(f"  points: {batch_points[batch_number - 1] if batched else 1}\n")

yml_file.close()
