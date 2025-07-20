def is_consistent(n, m, inputs, outputs):
  # Create 2D array to store values of b[i] for each input
  b = [[inputs[j][i] for j in range(m)] for i in range(n)]

  # Iterate through all variables b[i]
  for i in range(n):
    # Check if b[i] affects the output of the program
    affects_output = False
    for j in range(m):
      if b[i][j] != outputs[j]:
        affects_output = True
        break

    if affects_output:
      # Check if there is a j such that the output is different when b[i] is 0 or 1
      has_different_outputs = False
      for j in range(m):
        if b[i][j] != outputs[j]:
          has_different_outputs = True
          break

      # If there is no j such that the output is different when b[i] is 0 or 1, Elsie is lying
      if not has_different_outputs:
        return "LIE"

  # If all variables that affect the output of the program have at least one j such that the output is different when b[i] is 0 or 1, Elsie is not lying
  return "OK"


# Read the number of test cases from the first line
num_test_cases = int(input())

# Process each test case
for _ in range(num_test_cases):
  # Read n and m from the next line
  n, m = map(int, input().split())

  # Read the inputs and outputs for the test case
  inputs = []
  outputs = []
  for _ in range(m):
    line = input().strip().split()
    inputs.append(line[0])
    outputs.append(int(line[1]))

  # Check if the inputs and outputs are consistent
  result = is_consistent(n, m, inputs, outputs)
  print(result)
