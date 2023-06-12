import re

def word_count(word, file_path):
    with open(file_path, 'r') as f:
        contents = f.read()
        
    word = re.sub(r'[^\w\s]', '', word.lower())
    contents = re.sub(r'[^\w\s]', '', contents.lower())
    
    return contents.count(word)

word = input("Enter a word: ")
file_path = "PythonSummary.txt"
count = word_count(word, file_path)
print(f"The word {word} occurs {count} times")