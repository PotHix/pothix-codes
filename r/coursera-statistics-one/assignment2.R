library(psych)
library(sm)

setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

mydata <- read.table("data/assignment2.txt", header = T)
nrow(mydata)

describe(mydata)
mean(mydata$SR)
