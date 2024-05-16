from matplotlib import pyplot as plt

X = [i for i in range(100, 3001, 100)]

INS = [
    "rs",
    "rss",
    "ass",
]

INS_INFO = [
    "RANDOM",
    "REVERSE_SORTED",
    "ALMOST_SORTED",
]

ALGOS = [
    "qs",
    "ms",
    "sqs",
    "sqs_sms",
]

TITLES = [
    "QUICKSORT",
    "MERGESORT",
    "STRING_QUICKSORT",
    "STRING_MERGESORT",
]


for i, ii in zip(INS, INS_INFO):
    for a, t in zip(ALGOS, TITLES):
        times = []
        with open(f"./out/{i}_{a}_times.txt", "r") as file:
            times = list(map(int, file.readlines()))
        
        compares = []
        with open(f"./out/{i}_{a}_compares.txt", "r") as file:
            compares = list(map(int, file.readlines()))
        
        f, (ax1, ax2) = plt.subplots(1, 2,)
        f.suptitle(f"Algo: {t}, Array: {ii}")
        ax1.plot(X, times)
        ax1.set_title(f"Time Per Array Size")
        ax2.plot(X, compares)
        ax2.set_title(f"Compares Per Array Size")
        f.tight_layout()
        plt.savefig(f"./plots/{t}_{ii}.png")
        plt.close()