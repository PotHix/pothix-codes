# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment3.txt", header = T)
describe(data)

des <- subset(data, data[,2]=="des")
aer <- subset(data, data[,2]=="aer")

# Question 1
round(cor(data$S1.pre, data$S2.pre), 2)

# Question 2
round(cor(data$V1.pre, data$V2.pre), 2)

# Question 3
data$S.pre = (data$S1.pre + data$S2.pre) / 2
data$V.pre = (data$V1.pre + data$V2.pre) / 2
cor(data$S.pre, data$V.pre)
# Answer: Both!?

# Question 4
data.aer = subset(data, data$cond=="aer")
cor(data.aer$S1.pre, data.aer$S1.post)
cor(data.aer$S2.pre, data.aer$S2.post)
cor(data.aer$V1.pre, data.aer$V1.post)
cor(data.aer$V2.pre, data.aer$V2.post)
# Answer: V2 is more reliable

# Question 5
data$S.pre  = (data$S1.pre + data$S2.pre) / 2
data$V.pre  = (data$V1.pre + data$V2.pre) / 2
data$S.post = (data$S1.post + data$S2.post) / 2
data$V.post = (data$V1.post + data$V2.post) / 2
data$Sgain  = data$S.post - data$S.pre
cor(data$S.pre, data$Sgain)
# Answer: no relation because the correlation is negative

# Question 6
data$S.pre  = (data$S1.pre + data$S2.pre) / 2
data$V.pre  = (data$V1.pre + data$V2.pre) / 2
data$S.post = (data$S1.post + data$S2.post) / 2
data$V.post = (data$V1.post + data$V2.post) / 2
data$Vgain  = data$V.post - data$V.pre
cor(data$V.pre, data$Vgain)

# Question 7
library(psych)
describeBy(data$Sgain, data$cond)

# Question 8
library(gclus)
base <- data[c("S1.pre", "S2.pre", "V1.pre", "V2.pre")]
base.r <- abs(cor(base))
base.color <- dmat.color(base.r)
base.order <- order.single(base.r)
cpairs(base, base.order, panel.colors = base.color, gap = .5,
              main = "Variables Ordered and Colored by Correlation")

# Question 9
library(gclus)
base <- data[c("S1.post", "S2.post", "V1.post", "V2.post")]
base.r <- abs(cor(base))
base.color <- dmat.color(base.r)
base.order <- order.single(base.r)
cpairs(base, base.order, panel.colors = base.color, gap = .5,
              main = "Variables Ordered and Colored by Correlation")

# Question 10
# Compare both and see that variance is different
