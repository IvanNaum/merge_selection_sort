import csv

import matplotlib.pyplot as plt


def average(lst: list) -> float:
    return sum(lst) / len(lst)


def get_output_files():
    return map(lambda x: "output/" + x, ("output1.csv", "output2.csv", "output3.csv"))


def create_size_time_dict():
    size_time_dict = {}

    for i in get_output_files():
        with open(i, "rt") as output_file:
            reader = csv.DictReader(output_file, delimiter=':')
            for row in reader:
                row["size"] = int(row["size"])
                if not size_time_dict.get(row["size"]):
                    size_time_dict[row["size"]] = {
                        "merge_sort": [],
                        "selection_sort": []
                    }
                size_time_dict[row["size"]]["merge_sort"].append(float(row["merge_sort"]))
                size_time_dict[row["size"]]["selection_sort"].append(float(row["selection_sort"]))

    for size in size_time_dict.keys():
        size_time_dict[size] = {
            'merge_sort': average(size_time_dict[size]['merge_sort']),
            'selection_sort': average(size_time_dict[size]['selection_sort'])
        }

    return size_time_dict


def main():
    size_time_dict = create_size_time_dict()

    plt.plot(
        size_time_dict.keys(),
        list(map(lambda x: x[1]["merge_sort"], size_time_dict.items()))
    )
    plt.plot(
        size_time_dict.keys(),
        list(map(lambda x: x[1]["selection_sort"], size_time_dict.items()))
    )

    plt.title("Merge and Selection Sort")

    plt.ylabel("time")
    plt.xlabel("size array")
    plt.show()


if __name__ == '__main__':
    main()
