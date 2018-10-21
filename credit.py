from cs50 import get_int

# Promp user for a credit card number
while True:
    cc_number = get_int("Credit card number: ")
    if cc_number > 0:
        break

# checking validity - counting sums
sum1 = 0
sum2 = 0
x = cc_number

while x > 0:
    y1 = x % 10
    sum1 = sum1 + y1
    x = (x - y1) // 10

    y2 = x % 10
    if y2 * 2 < 10:
        sum2 = sum2 + y2 * 2
    else:
        sum2 = sum2 + (((y2 * 2) % 10) + ((y2 * 2 - ((y2 * 2) % 10)) / 10))
    x = (x - y2) // 10

# checking sums
if (sum1 + sum2) % 10 == 0:
    # checking company
    if (cc_number >= 340000000000000 and cc_number < 350000000000000) or (cc_number >= 370000000000000 and cc_number < 380000000000000):
        print("AMEX")
    elif cc_number >= 5100000000000000 and cc_number < 5600000000000000:
        print("MASTERCARD")
    elif (cc_number >= 4000000000000 and cc_number < 5000000000000) or (cc_number >= 4000000000000000 and cc_number < 5000000000000000):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")