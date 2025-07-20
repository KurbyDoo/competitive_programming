# To be used with the generator file in same directory
class Solution():
    def solve(self, input_stream: str) -> str:
        input_stream = input_stream.split("\n")
        input_stream = input_stream[::-1]
        input = input_stream.pop
        output = []
        def print(s): return output.append(str(s))

        # Paste your python solution here

        # ---

        return "\n".join(output) + "\n"
