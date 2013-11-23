# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment9.txt", header = T)
describe(data)

# Question 1
names(data)
class(data$Haste)
class(data$Prime)

# Question 2
Haste = factor(data$Haste, levels = c(1,2,3), labels = c("Early", "On Time", "Late"))
Prime = factor(data$Prime, levels = c(1,2), labels = c("Parable", "Control"))
aov.data = aov(data$Helping ~ Haste * Prime)
summary(aov.data)

# Question 3
summary(aov.data)

# Question 4
summary(aov.data)

# Question 5
aov.table = summary(aov.data)
TukeyHSD(aov.data)

# Question 6
round(etaSquared(aov.data, anova=T), 2)

# Question 7
round(etaSquared(aov.data, anova=T), 2)

# Question 8
A1.B = subset(data, data$Haste == "1")
A2.B = subset(data, data$Haste == "2")
A3.B = subset(data, data$Haste == "3")
aov.A1.B = aov(A1.B$Helping ~ A1.B$Prime)
summary(aov.A1.B)
aov.A2.B = aov(A2.B$Helping ~ A2.B$Prime)
summary(aov.A2.B)
aov.A3.B = aov(A3.B$Helping ~ A3.B$Prime)
summary(aov.A3.B)

# Question 9
A1.B = subset(data, data$Haste == "1")
aov.A1.B = aov(A1.B$Helping ~ A1.B$Prime)
round(etaSquared(aov.A1.B),2)

# Question 10
# People are more likely to help others after being primed to do so if they are early
