# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment6.txt", header = T)
describe(data)

# Question 1
model1 = lm(data$salary ~ data$years)
summary(model1)

# Question 2
model1 = lm(data$salary ~ data$years)
confint(model1)

# Question 3
model3 = lm(data$salary ~ data$years + data$courses)
summary(model3)

# Question 4
confint(model3)

# Question 5
prof.code = C(data$profession, treatment)
model4 = lm(data$salary ~ data$years + data$courses + (prof.code))
summary(model4)

# Question 6
prof.code = C(data$profession, treatment)
model4 = lm(data$salary ~ data$years + data$courses + (prof.code))
summary(model4)

# Question 7
prof.code = C(data$profession, treatment)
model4 = lm(data$salary ~ data$years + data$courses + (prof.code))
summary(model4)

# Question 8
prof.code = C(data$profession, treatment)
model4 = lm(data$salary ~ data$years + data$courses + (prof.code))
summary(model4)

# Question 9
prof.code = C(data$profession, treatment)
model4 = lm(data$salary ~ data$years + data$courses + (prof.code))
summary(model4)
tapply(data$salary, data$profession, mean)

# Question 10
anova(model1, model3)
anova(model2, model3)
