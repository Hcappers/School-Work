et = 0.001
ln2 = 0.69314718056
n = 1
sum = 0

while abs(ln2 - sum) > et:
    sum += (-1) ** (n + 1) / n
    n += 1

terms = n - 1
final_error = abs(ln2 - sum)

print(f"Number of terms requires: {terms}\nApproximated ln(2): {sum}\nFinal Error: {final_error}")
