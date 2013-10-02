# -----------------------------------------------------------------------
# Create a vector
v=c(1,3,5,7)

# -----------------------------------------------------------------------
# Create a list
l=c("Blue", 2, 5, "Red")

# -----------------------------------------------------------------------
# Create a matrix
m=matrix(1:6,2,3)
# > matrix(1:6,2,3)
# [,1] [,2] [,3]
# [1,]    1    3    5
# [2,]    2    4    6

# -----------------------------------------------------------------------
# Create a matrix from a vector
m2=matrix(1:6)
dim(m2)=c(2,3) # gets the same result as the matrix above


# -----------------------------------------------------------------------
# Create a matrix by binding columns and rows
x=1:6
y=5:10
cbind(x,y)
rbind(x,y)


# -----------------------------------------------------------------------
# Dataframes (a matrix to construct different types of objects
d=data.frame(id=1:5,gender=c("M","F","F","M","F"),score=c(8,3,6,5,5))

nrol(d) # number of rows
ncol(d) # number of columns

attributes(d) # check the attributes of the data frame as we do with matrix

d[2,1] # get the second row first column value from data frame

View(d) # Open a TCL windows for dataframe viewing
edit(d) # Open a TCL windows for dataframe editting

?edit # get help for the edit function

install.packages("psych") # install psych library

library(psych) # Load psych library

search() # show loaded libraries
