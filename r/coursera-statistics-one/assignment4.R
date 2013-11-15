# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment4.txt", header = T)
describe(data)

# Question 1
round(cor(data$salary, data$years), 2)

# Question 2
round(cor(data$salary, data$courses), 2)

# Question 3
model1 = lm(data$salary ~ data$years)
summary(model1)

# Question 4
cor.test(data$salary, data$years)

# Question 5
model3 = lm(data$salary ~ data$years + data$courses)
summary(model3)

# Question 6
model3 = lm(data$salary ~ data$years)
summary(model3)
# Use "Estimate" value rounded

# Question 7
model3 = lm(data$salary ~ data$courses)
summary(model3)
# Use "Estimate" value rounded

# Question 8
model3 = lm(data$salary ~ data$years + data$courses)
data.predicted = fitted(model3)
round(mean(data.predicted), 0)

# Question 9
model3 = lm(data$salary ~ data$years + data$courses)
data.error = resid(model3)
round(mean(data.error), 0)

# Question 10
