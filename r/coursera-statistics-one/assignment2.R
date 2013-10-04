library(psych)
library(sm)

setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

mydata <- read.table("data/assignment2.txt", header = T)
nrow(mydata)

describe(mydata)
mean(mydata$SR)
var(mydata$SR)

pre  <- subset(mydata, mydata[,3]=="pre")
post <- subset(mydata, mydata[,3]=="post")

mean(pre$SR)
sd(post$SR)
median(post$SR)
describe(post)
