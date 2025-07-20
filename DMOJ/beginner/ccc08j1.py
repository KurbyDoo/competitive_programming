bmi = float(input()) / (float(input()) ** 2)

if bmi > 25:
    print("Overweight")

elif bmi < 18.5:
    print("Underweight")

else:
    print("Normal weight")
