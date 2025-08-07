import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database = []
    str_list = []
    filename = sys.argv[1]
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        str_list = reader.fieldnames[1:]
        for row in reader:
            person = {}
            person["name"] = row["name"]
            for subsequence in str_list:
                person[subsequence] = int(row[subsequence])
            database.append(person)

    # TODO: Read DNA sequence file into a variable
    filename = sys.argv[2]
    with open(filename, "r") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_count = {}
    for subsequence in str_list:
        str_count[subsequence] = longest_match(sequence, subsequence)

    # TODO: Check database for matching profiles
    match = "No match"
    for person in database:
        all_match = True
        for subsequence in str_list:
            if person[subsequence] != str_count[subsequence]:
                all_match = False
                break
        if all_match == True:
            match = person["name"]
            break

    print(match)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
