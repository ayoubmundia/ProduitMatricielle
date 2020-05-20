T1<-Sys.time() 

# M1 <- matrix(c(3,2,4,5), nrow=2)
# M2 <- matrix(c(7,1,0,5), nrow=2)

M1 <- matrix(10000, nrow = 550, ncol = 550)

M2 <- matrix(15000, nrow = 550, ncol = 550)

# print(M1)

# print(M2)

M3 <- M1 %*% M2

T2 <- Sys.time()  

Tdiff= difftime(T2, T1)

print(Tdiff)
