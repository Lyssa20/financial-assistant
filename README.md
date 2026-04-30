# Family Financial Assistant
This is a C++ console-based financial tool that helps families track monthly income, plan expenses, build grocery lists, and get simple advice on where to cut costs.

# Why I Built This

- My family has two sources of income and a lot of set monthly costs, such as rent, school fees, electricity and water. We would have a rough idea, month to month, of how much money remained, but we never really tracked it properly. I wanted to create something that would actually assist with that, something that my mum could open and use anywhere.
- I noticed that our biggest source of overspending was grocery shopping. We would go without a real plan and come back over budget. So I added a section where you write your list before you leave, then enter in actual prices to calculate and make sure you're not overspending and help you identify which expense to cut first when money is tight.

# What I learned

- I have used structs before, but this was the first time I had a project where I actually separated things properly into multiple .h and .cpp files. Getting the #ifndef guards right and figuring out which header included which was more time-consuming than I thought it would be.
- The file I/O part (fileio.cpp) was unfamiliar to me. I hadn't used ofstream before. I also had a weird bug with getline skipping the first item in the grocery list, which was a leftover newline in the input buffer. I fixed it with cin.ignore().

# How to Run

## Dev-C++ (Windows, easiest)
1. Download [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/)
2. File → New → Project → Console Application → C++
3. Add all files to the project
4. compile and run

# Future Improvements

 ~ Load salaries/get user input from instead of hardcoding
 ~ Add a monthly history, compare this month vs last month
 ~ Use a linked list instead of a fixed array for unlimited expense entries
 ~ Add a savings goal tracker

![App Demo](Cal.gif)

