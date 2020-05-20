echo "AIT LACHGAR AYOUB : Calcul Matricielle"
echo "Start Compiling ..."


gcc normal.cpp -o normal
gcc thread.cpp -o thread
gcc -o omp -fopenmp omp.c
mpicc mpi.c -o mpi &>/dev/null


echo "End Compiling"

echo "NORMAL----"
./normal

echo "PTHREAD----"
./thread

echo "OpenMP----"
./omp

echo "OpenMPI----"
mpiexec -np 4 ./mpi

echo "GoLang----"
go run go.go

echo "R----"
Rscript R.R
