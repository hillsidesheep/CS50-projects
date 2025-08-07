# TODO
def main():
    number = get_number()
    judge(number)


def get_number():
    n = int(input("Number: "))
    return n


def judge(number):
    if (judgevalid(number)):
        length = 0
        while (number >= 100):
            number = number // 10
            length = length + 1

        length = length + 2

        if (number == 34 or number == 37):
            if (length == 15):
                print("AMEX")
            else:
                print("INVALID")
        elif (number >= 40 and number < 50):
            if ((length == 13 or length == 16)):
                print("VISA")
            else:
                print("INVALID")
        elif (number >= 51 and number <= 55):
            if (length == 16):
                print("MASTERCARD")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")


def judgevalid(number):
    k = 0
    while number != 0:
        i = number % 10
        j = number // 10 % 10
        if (2 * j >= 10):
            j = 2 * j % 10 + 1
        else:
            j = 2 * j
        k = k + i + j
        number = number // 100

    if (k % 10 == 0):
        return 1
    else:
        return 0


main()
