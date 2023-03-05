import math
import re

formats = {
    "^[A-Z]{2}-[0-9]{2}-[0-9]{2}$": [23, 23, 10, 10, 10, 10],
    "^[0-9]{2}-[0-9]{2}-[A-Z]{2}$": [23, 23, 10, 10, 10, 10],
    "^[0-9]{2}-[A-Z]{2}-[0-9]{2}$": [23, 23, 10, 10, 10, 10],
    "^[A-Z]{2}-[0-9]{2}-[A-Z]{2}$": [23, 23, 23, 23, 10, 10]
}

ALPHABET = "ABCDEFGHIJLMNOPQRSTUVXZ"

def sort(license: str) -> str:
    return list(filter(lambda c: c.isalpha(), license)) + list(filter(lambda c: c.isnumeric(), license))

def decode(license: str) -> (str, int, [int]):
    previous = 0
    for regex, counts in formats.items():
        if re.search(regex, license):
            return sort(license), previous, counts
        previous += math.prod(counts)

# Colocar numeros à direira já que é o primeiro a ser contando, mantendo a ordem de tudo
def order(license: str) -> int:
    # print("license={0}".format(license))
    license, previous, counts = decode(license)
    # print("license={0}, previous={1}, counts={2}".format(license, previous, counts))

    permutations = 1
    for i, char in enumerate(license):
        index = int(char) if char.isnumeric() else ALPHABET.index(char)
        product = math.prod(counts[i + 1:])
        permutations += index * product
        # print("i={0}, char={1}, index={2}, product={3}, permutations={4}".format(i, char, index, product, permutations))
    permutations += previous
    # print(permutations)
    # print()
    return permutations

def main():
    while True:
        license_a, license_b = input().split()
        order_a, order_b = order(license_a), order(license_b)
        interval = abs(order_a - order_b)
        print(interval)

if __name__ == "__main__":
    main()

# order("AA-00-00")
# order("AA-00-01")
# order("AA-00-10")
# order("AA-01-00")
# order("AA-10-00")
# order("AB-00-00")
# order("BA-00-00")
# order("00-00-AA")
