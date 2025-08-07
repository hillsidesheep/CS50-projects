# TODO
def main():
    # Prompt for Text
    text = input("Text: ")

    # count letters
    letters = count_letters(text)

    # count word
    words = count_words(text)

    # count word
    sentences = count_sentences(text)

    # index
    L = letters / 1.0 / words * 100.0
    S = sentences / 1.0 / words * 100.0

    index = 0.0588 * L - 0.296 * S - 15.8
    grade = int(index)
    if ((index - grade) >= 0.5):
        grade += 1
    if (grade < 1):
        print("Before Grade 1")
    elif (grade > 16):
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():  # 更简洁的字母判断方式
            letters += 1
    return letters


def count_words(text):
    n = 0
    words = 1
    for char in text:
        if char == ' ':
            words += 1
    return words


def count_sentences(text):
    sentences = 0
    for char in text:
        if char in ('.', '?', '!'):  # 更简洁的判断方式
            sentences += 1
    return sentences


if __name__ == "__main__":
    main()
