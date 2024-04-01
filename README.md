# primative_genetic_algorithm_paremeter_optimization
There are tools to analyze market behaviour. Linear regression, relative strength index, bollinger bands and more.  Optimizing selection of parameters in C

Some may be choosen and tested with past market prices to find optimal value and combination. Genetic algorithms uses natural selection and evolution. Each cell has a genetic code for min or max values for buy and sell. also an activation gene as 0 or 1. With python it was taking maybe hundreds of times longer then C. That's why I migrated to C for this particular test.

we may create 100k cells, each cell starts with random parameters and tries to trade along the data. They cannot sell before buying. At the and their profits are calculated and best cells are choosen to reproduce by mixing their genes randomly. These children as well as parents are transfered into the next repatition. Then again best genes are crossed.
