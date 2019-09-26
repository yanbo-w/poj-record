# poj1035


## Description

You, as a member of a development team for a new spell checking program, are to write a module that will check the correctness of given words using a known dictionary of all correct words in all their forms.
If the word is absent in the dictionary then it can be replaced by correct words (from the dictionary) that can be obtained by one of the following operations:
?deleting of one letter from the word;
?replacing of one letter in the word with an arbitrary letter;
?inserting of one arbitrary letter into the word.
Your task is to write the program that will find all possible replacements from the dictionary for every given word.
## Input

The first part of the input file contains all words from the dictionary. Each word occupies its own line. This part is finished by the single character '#' on a separate line. All words are different. There will be at most 10000 words in the dictionary.
The next part of the file contains all words that are to be checked. Each word occupies its own line. This part is also finished by the single character '#' on a separate line. There will be at most 50 words that are to be checked.
All words in the input file (words from the dictionary and words to be checked) consist only of small alphabetic characters and each one contains 15 characters at most.
## Output

Write to the output file exactly one line for every checked word in the order of their appearance in the second part of the input file. If the word is correct (i.e. it exists in the dictionary) write the message: " is correct". If the word is not correct then write this word first, then write the character ':' (colon), and after a single space write all its possible replacements, separated by spaces. The replacements should be written in the order of their appearance in the dictionary (in the first part of the input file). If there are no replacements for this word then the line feed should immediately follow the colon.

## 解题思路

发现自己直接上手写的效率就会很慢，还会有bug，还是要先演算，然后再写。

最开始拿到题目的想法就是hash解决问题，找到了一个BKDRHash的方法对字符串进行处理，然后解题过程中遇到了对于char*的处理问题以及两个字符串不完全复制的问题，还是不够熟练。其实对于字符串指针，本质上是c++传递的是一个数，而不能传递一个数组，也就是传递地址，如果需要传递数组的话只能是在系统中占领一块地方，然后传递他的地址出来。此外，在函数处理过程中，str的运算【不】会对原来的造成影响，错误：因此需要复制一下再操作。字符串指针其实就是一个数？

char a[] 把内容存在stack。char *a 则把指针存在 stack，把内容存在 constants。

调用函数时，首先进行参数压栈，一般情况下压栈顺序为从右到左，最后压函数地址。

【值得再研究研究，涉及到c的程序运行原理】

此外就是hashtable的建立，最开始自己想当然，没有考虑重复hash的情况，后来发现，需要加上链表来解决问题，从而造成了几次错误。

另外就是输入输出要看清楚题目说明。