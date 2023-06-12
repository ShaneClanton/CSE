sentence = input('Please enter a sentence: ')
times = int(input('How many times would you like to repeat your word? '))
with open("CompletedPunishment.txt", "w") as text:
    for i in range(times):
        text.write(sentence + "\n")