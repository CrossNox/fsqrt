library("ggplot2")
options(digits=3)
setwd("/home/joaquintz/Desktop/projects/utils/utils/plots/")

comparison <- read.table("benchmark.tsv",sep="\t",header=TRUE)

comparison$err_rel <- (comparison$fsqrt-comparison$sqrt)/comparison$sqrt

max_error <- max(comparison$err_rel,na.rm=TRUE)
min_error <- min(comparison$err_rel,na.rm=TRUE)
step_error <- (max_error-min_error)/5
max_x_exp <- ceiling(max(log10(comparison$x),na.rm=TRUE))

exponent_breaks <- function(coeficientes,pot) 
    as.expression(parse(text=paste(coeficientes,"10^",pot,sep="")))

comparison.plot <- (ggplot(data=comparison,aes(x=x,y=err_rel))
                    + geom_line()
                    + scale_y_continuous(limits=c(min_error,max_error),
                                         breaks=seq(min_error,max_error,by=step_error))
                    + scale_x_log10(breaks=10^seq(0,max_x_exp),
                                    labels=exponent_breaks(NULL,seq(0,max_x_exp)))
                    + theme_bw() 
                    + ggtitle("Error relativo: sqrt vs fsqrt") 
                    + ylab("Error relativo (%)") + xlab("x [log 10]"))

print(comparison.plot)

ggsave("comparison.png")