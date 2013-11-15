# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment7.txt", header = T)
describe(data)

# Question 1
round(cor(data$extra, data$happy),2)

# Question 2
round(cor(data$extra, data$diverse),2)

# Question 3
round(cor(data$diverse, data$happy),2)

# Question 4
summary(lm(data$happy ~ data$extra))
round(0.03753*100, 2)

# Question 5
summary(lm(data$happy ~ data$extra + data$diverse))
round(0.03753*100, 2)

# Question 6
happyextra <- lm(data$happy ~ data$extra)
round(confint(happyextra), 2)

# Question 7
happyextra <- lm(data$happy ~ data$extra)
confint(happyextra)

# Question 8
indirect = sobel(data$extra, data$diverse, data$happy)

# Question 9
indirect = sobel(data$extra, data$diverse, data$happy)

# Question 10
indirect = sobel(data$extra, data$diverse, data$happy)
