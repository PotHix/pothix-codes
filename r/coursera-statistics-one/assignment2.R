# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment2.txt", header = T)
describe(data)

pre  <- subset(data, data[,3]=="pre")
post <- subset(data, data[,3]=="post")

# Question 1
nrow(data)

# Question 2
names(data)

# Question 3
mean(data$SR)

# Question 4
var(data$SR)

# Question 5
mean(pre$SR)

# Question 6
sd(post$SR)

# Question 7
median(post$SR)

# Question 8
describeBy(post, post$condition)

# Question 9
pre.wm  = sapply(subset(pre,   pre$condition=="WM"), as.numeric)
post.wm = sapply(subset(post, post$condition=="WM"), as.numeric)
pre.pe  = sapply(subset(pre,   pre$condition=="PE"), as.numeric)
post.pe = sapply(subset(post, post$condition=="PE"), as.numeric)
pre.ds  = sapply(subset(pre,   pre$condition=="DS"), as.numeric)
post.ds = sapply(subset(post, post$condition=="DS"), as.numeric)
par(mfrow = c(2,3))
hist(pre.wm)
hist(post.wm)
hist(pre.pe)
hist(post.pe)
hist(pre.ds)
hist(post.ds)

# Question 10
pre.wm  = subset(pre,   pre$condition=="WM")
post.wm = subset(post, post$condition=="WM")
pre.pe  = subset(pre,   pre$condition=="PE")
post.pe = subset(post, post$condition=="PE")
pre.ds  = subset(pre,   pre$condition=="DS")
post.ds = subset(post, post$condition=="DS")
mean(post.wm$SR)-mean(pre.wm$SR)
mean(post.pe$SR)-mean(pre.pe$SR)
mean(post.ds$SR)-mean(pre.ds$SR)
