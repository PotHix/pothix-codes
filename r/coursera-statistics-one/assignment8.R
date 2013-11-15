# Preparing
library(psych)
setwd("/home/pothix/repos/pothix-codes/r/coursera-statistics-one")

# Reading data
data <- read.table("data/assignment8.txt", header = T)
describe(data)

# Question 1
t.test(data$SR ~ data$time, paired=T)

# Question 2
wm = subset(data, data$condition=="WM")
pe = subset(data, data$condition=="PE")
ds = subset(data, data$condition=="DS")
t.test(wm$SR ~ wm$time, paired=T)
t.test(pe$SR ~ pe$time, paired=T)
t.test(ds$SR ~ ds$time, paired=T)

# Question 3
cohensD(wm$SR ~ wm$time, method="paired")
cohensD(pe$SR ~ pe$time, method="paired")
cohensD(ds$SR ~ ds$time, method="paired")

# Question 4
library(reshape)
data.wide = cast(data, subject+condition~time)
data.wide$gain = data.wide$post - data.wide$pre
wm.wide = subset(data.wide, data.wide$condition=="WM")
pe.wide = subset(data.wide, data.wide$condition=="PE")
ds.wide = subset(data.wide, data.wide$condition=="DS")
t.test(wm.wide$gain, pe.wide$gain, var.equal=T)
t.test(wm.wide$gain, ds.wide$gain, var.equal=T)
t.test(ds.wide$gain, pe.wide$gain, var.equal=T)

# Question 5
leveneTest(data.wide$gain, data.wide$condition)

# Question 6
aov.model = aov(data.wide$gain ~ data.wide$condition)
summary(aov.model)

# Question 7
library(lsr)
etaSquared(aov.model, anova=T)

# Question 8
library(lsr)
etaSquared(aov.model, anova=T)

# Question 9
TukeyHSD(aov.model)

# Question 10
TukeyHSD(aov.model)
