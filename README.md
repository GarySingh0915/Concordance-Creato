# Concordance-Creator
Problem: A concordance is defined as “an alphabetical index of the principal words of a book or document,
with a reference to the passage in which each occurs”. Creating a concordance from an existing
document is a task requiring attention to lots of detail and an open-ended design since the exact
size and contents of a source document are seldom known in advance.

The Assignment: Design, develop and test a C++ program that prepares a concordance of all the words in a
text file. Your finished result will be a new text file containing an alphabetical listing of all the
words, and with each word, the number of times that word appeared in the document, and a list of
all the line numbers on which that word occurs.

Discussion: Your program will need to read the contents of a user-selected text file, word-by-word, keeping
track of line numbers, and keep a record of each word with all of the line numbers where the word is used.
Consider the following issues as you prepare your solution.

• Allow the user to select a data file from a menu of available files and save the results in a file named
“originalname_concordance.txt” where originalname is the name of the input file without its
extension. Include at least 4 of the 8 data files listed below. Allow the user to select a file by
number – do not require the user to enter the name of the data file.

• Use a C++ map (from the STL) to manage a concordance of all the unique words in the file, including
all the references to each word. This concordance must include at least the following features:

o A variable to contain the word being cataloged. The word in this instance variable must be
lower case and have all leading and trailing punctuation removed. Embedded hyphens,
apostrophes, and other punctuation must be left intact.

o A variable to collect all the line numbers where this word was found in the file.

• Create a menu-driven program that offers the user a list of available text files. The user will select a
file from the menu, and the program will read the file and produce a concordance file from it.

• The main() function must use one or more map variables to build and maintain the concordance.
This concordance must be reset each time an input data file is selected and opened.

• Open the user-selected file and read every word in it, adding and updating them in the
Concordance object as necessary. For consistency, each word read from the file must be converted
to lowercase and have all leading and trailing punctuation removed before being added to the
concordance. Words that contain only punctuation, e.g. “***” or “—" must be discarded and not
included in the concordance.

• When the end of the data file has been reached and all words have been cataloged, save the
formatted contents of the concordance to a new file, named “originalname_concordance.txt”
where originalname is the name of the data file without its filename extension.

• Allow the user to repeat this process for as many input files as they want.
