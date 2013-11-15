# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment5.txt", header = T)
describe(data)

# Question 1
model1 = lm(data$salary ~ data$years)
confint(model1)

# Question 2
model2 = lm(data$salary ~ data$courses)
confint(model2)

# Question 3
model3 = lm(data$salary ~ data$years + data$courses)
anova(model1, model3)
anova(model2, model3)

# Question 4
model3.z = lm(scale(data$salary) ~ scale(data$years) + scale(data$courses))
confint(model3.z)

# Question 5
# sample

# Question 6
set.seed(1)
sample = data[sample(nrow(data), 15), ]

# Question 7
data.subset = data[51:70,]
model3.subset = lm(data.subset$salary ~ data.subset$years + data.subset$courses)
summary(model3.subset)

# Question 8
model1.subset = lm(data.subset$salary ~ data.subset$years)
model2.subset = lm(data.subset$salary ~ data.subset$courses)
model3.subset = lm(data.subset$salary ~ data.subset$years + data.subset$courses)
summary(model1.subset)
summary(model2.subset)
summary(model3.subset)
anova(model1.subset, model3.subset)
anova(model2.subset, model3.subset)

# Question 9
data.subset$predicted = fitted(model3.subset)
cor(data.subset$predicted, data.subset$salary)

# Question 10
data.subset$error = resid(model3.subset)
cor(data.subset$predicted, data.subset$error)
