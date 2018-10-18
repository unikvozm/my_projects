from cs50 import get_float

# Promp user for change
while True:
    cash = get_float("Change in dollars: ")
    if cash >= 0:
        break

# convert to integer
n = round(cash * 100)

# number of 25 cents' coins
i = n // 25
# remainder
n = n % 25
# number of 10 cents' coins
i = i + n // 10
# remainder
n = n % 10
# number of 5 cents' coins
i = i + n // 5
# remainder
n = n % 5
# number of 1 cent' coins
i = i + n // 1
# remainder
n = n % 1

# Print out how many coins
print(i)
