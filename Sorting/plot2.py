import matplotlib.pyplot as plt

if __name__ == '__main__':

    filepath = 'data2.txt'  # TODO: add path to your data file here
    names = ["Selection", "Bubble", "Bubble with EC", "insert", "Merge", "Quick"]  # TODO: add the names of each sorting method in the order they are saved in the text file
    x = list(range(1000, 20001, 1000))  # this is the range of input sizes tested
    with open(filepath, 'r') as file:
        for i, line in enumerate(file):
            y = list(map(int, line.split(',')))
            plt.plot(x, y, label=names[i])

    plt.xlabel('Input size')
    plt.ylabel('Time taken (ns)')
    plt.title('Comparison of sort procedures')
    plt.legend()
    plt.savefig('sorting.pdf')
    plt.show()


