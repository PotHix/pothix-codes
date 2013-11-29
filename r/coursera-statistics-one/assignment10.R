# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment10.txt", header = T)
describe(data)

# Question 1
describeBy(data$age, data$change=="1")

# Question 2
fit = glm(data$change ~ data$educ + data$age + data$gdp + data$co2, family = binomial)
summary(fit)

# Question 3

# Question 4
round(confint(fit),2)

# Question 5
round(confint.default(fit), 2)

# Question 6
round(with(fit, null.deviance - deviance), 2)

# Question 7
round(with(fit, df.null - df.residual), 2)

# Question 8
# Yes, the p-value for the difference between the two models is significant

# Question 9
# Yes, it differ significantly if I drop educ as a predictor in the model

# Question 10
ClassLog(fit, data$change)
