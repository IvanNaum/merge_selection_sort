from math import log
from random import shuffle


def generate_file(filename: str, max_size: int):
    with open(filename, "wt") as input_file:
        for i in range(2, round(log(max_size, 10)) * 2 + 2):
            size = int(10 ** (i // 2) / (2 - i % 2))
            numbers = list(range(1, size + 1))
            shuffle(numbers)

            print(size, file=input_file)
            print(*numbers, file=input_file)


def main():
    for i in range(3):
        generate_file(f"input{i + 1}.txt", max_size=10 ** 4)


if __name__ == '__main__':
    main()
