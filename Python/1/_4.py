# Write a Python program that takes a sentence as input and identifies and prints all the palindromic words in the sentence. Use an array to store the palindromic words.


def is_palindrome(word):
    for i in range(0, int(len(word)/2)):
        if word[i] != word[len(word)-i-1]:
            return False
    return True


def find_palindromes(sentence):
    words = sentence.split()
    palindromes = []
    for word in words:
        if is_palindrome(word):
            palindromes.append(word)
    return palindromes


sentence = "madam knows malayalam well"
palindromes = find_palindromes(sentence)
print("Palindromes in the sentence are: ", palindromes)

